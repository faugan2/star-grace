#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QLabel>
#include "includes.h"


MainWindow::MainWindow(QSqlDatabase db, QString id_user,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->db=db;
    this->id_user=id_user;
    this->statusBar()->hide();





    QToolBar * toolbar;
    toolbar=addToolBar("File");

    toolbar->addAction(ui->actionParam_tres);
    //ui->actionParam_tres->setVisible(false);
    toolbar->addAction(ui->actionDeconnexion);
    toolbar->addAction(ui->actionFermer);
    toolbar->addSeparator();

    toolbar->addAction(ui->actionListe_des_points_de_vente);
    toolbar->addAction(ui->actionListe_des_utilisateurs);
    toolbar->addAction(ui->actionListe_des_clients);
    toolbar->addSeparator();

    toolbar->addAction(ui->actionCat_gories);
    toolbar->addAction(ui->actionAjouter);
    toolbar->addAction(ui->actionAutres_produits);
    toolbar->addSeparator();

    toolbar->addAction(ui->actionSynchroniser_les_donn_es);
    toolbar->addAction(ui->actionSauvegarder_la_base_de_donn_es);
    toolbar->addAction(ui->actionRestaurer_la_base_de_donn_es);
    ui->inventaire_du_2->setDate(QDate::currentDate());
    ui->inventaire_au->setDate(QDate::currentDate());
    ui->date_recette->setDate(QDate::currentDate());





    ui->table_vente->setColumnWidth(2,50);

    can_update_combobox=false;
    load_user_info();
    carreaux_settings();
    load_points_vente();
    load_stock_alerte();
    load_client_impaye();
    load_client_pre_paye();
    load_produits();
    load_clients();
    load_users();
    load_formats();
    load_inventaire();
    load_recette();
    load_droit();
    load_server();
    can_update_combobox=true;
   // ui->block_points_vente->hide();

    QSqlQuery qr;
    qr.exec("select * from mouvements order by date asc");
    if(qr.next()){
        ui->inventaire_du_2->setDate(qr.value("date").toDate());
    }

    qr.exec("select * from users where token_id='"+id_user+"'");
    QString id_pv="";
    if(qr.next()){
        QString user_name=qr.value("nom").toString();
        ui->user_name->setText("Bonjour "+user_name.toUpper()+",");
        id_pv=qr.value("point_vente").toString();
    }

    if(id_pv!=""){

        qr.exec("select * from points_vente where token_id='"+id_pv+"'");
        if(qr.next()){
            QString pv=qr.value("adresse").toString();
            ui->user_pv->setText(pv.toUpper());
        }
    }


    ui->scrollArea->hide();
    ui->pushButton_9->hide();

    ui->serveur_distant->hide();

    this->selected_row_inventaire=-1;

   timer=new QTimer(this);
   connect(timer,&QTimer::timeout,this,&MainWindow::all_updates);
   timer->start(15000);

   timer2=new QTimer(this);
   connect(timer2,&QTimer::timeout,this,&MainWindow::synchroniser_tout);
   timer2->start(5000*60);


}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_pushButton_clicked()
{
    ajout_point_vente=new AjouterPointDeVente(db,this);
    ajout_point_vente->setModal(true);
    ajout_point_vente->show();
}*/

void MainWindow::on_actionFermer_triggered()
{
    this->close();
}

void MainWindow::on_actionDeconnexion_triggered()
{

    Login *l=new Login;
    l->show();

    this->close();
}

void MainWindow::on_produits_currentIndexChanged(int index)
{
    if(index==0){
        ui->label_format->setText("---");
        ui->label_qte->setText("---");
        return;
    }

    QString f=formats.at(index);



    ui->label_format->setText(f);

    QString produit=ui->produits->currentText();
    QString id_produit=ui->produits->currentData().toString();
    ui->label_format->setToolTip(id_produit);
    qDebug()<<"the id of the product is "<<id_produit;

    QString format_nom="-";
    QSqlQuery qr;
    qr.exec("select * from formats where token_id='"+f+"'");
    if(qr.next()){
        format_nom=qr.value("nom").toString();
    }
    ui->label_format->setText(format_nom);

    qr.exec("select * from stock where token_id='"+id_produit+"'");
    if(qr.next()){
        QString pu=qr.value("prix_par_m2").toString();
        ui->pu->setText(pu);
    }

    qDebug()<<"select sum(qte) from mouvements where point_vente='"+user_info.at(4).toUpper()+"' and produit='"+id_produit+"'";

    qr.exec("select sum(total_cartons) from mouvements where point_vente='"+user_info.at(4).toUpper()+"' and produit='"+id_produit+"'");
    if(qr.next()){
        QString total=qr.value(0).toString().replace(QChar('-'),"");
        QSqlQuery qr2;
        if(format_nom.length()>3){
            QString new_qte_in_stock="";
            qr2.exec("select * from formats where token_id='"+f+"'");
            if(qr2.next()){
                double nbpc=qr2.value("pieces_par_carton").toDouble();
                double tc=total.toDouble();
                int tc_int=(int)tc;
                int nb_c=tc_int;
                int nb_p=0;
                new_qte_in_stock=QString::number(nb_c)+" cartons ";
                if(tc>tc_int){
                    double reste_c=tc-tc_int;
                    nb_p=reste_c*nbpc;
                    new_qte_in_stock+=QString::number(nb_p)+" pieces";
                    ui->label_qte->setText(new_qte_in_stock);
                }else{
                    ui->label_qte->setText("---");
                }

            }else{
                ui->label_qte->setText(total);
            }
        }else{
            ui->label_qte->setText(total);
        }


        if(total.toInt()==0){
            //ui->pushButton_3->setEnabled(false);
        }
    }else{
        ui->label_qte->setText("0");
    }

    if(f=="-"){
        ui->unite->setEnabled(false);
        //ui->calcul->setEnabled(false);
        ui->calcul->setText(ui->qte->text());
        return;
    }else{

        ui->calcul->show();
        make_vente_calculation();
        ui->unite->setEnabled(true);
       // ui->calcul->setEnabled(true);
    }

}

void MainWindow::make_vente_calculation()
{
    int index=ui->produits->currentIndex();

    QString f=formats.at(index);


    if(f=="-"){
        ui->calcul->setToolTip(ui->qte->text());
        return;
    }
    if(index==0){
        return;
    }
    QString qte=ui->qte->text();
    if(qte.isEmpty()){
        return;
    }

    QString pu=ui->pu->text();
    if(pu.isEmpty()){
        return;
    }

    ui->unite->setEnabled(true);
   // ui->calcul->setEnabled(true);

    QString id_produit=ui->produits->currentData().toString();
    QString id_format="";
    QSqlQuery qr;
    qr.exec("select * from stock where token_id='"+id_produit+"'");
    if(qr.next()){
        id_format=qr.value("format").toString();
    }
    if(id_format=="-"){
        return;
    }

    int new_index=index-1;
    float piece_par_m2=pieces_par_m2.at(new_index).toFloat();
    float piece_par_cartons=pieces_par_cartons.at(new_index).toFloat();
    float dimension=dimensions.at(new_index).toFloat();

    qr.exec("select * from formats where token_id='"+id_format+"'");
    if(qr.next()){
        piece_par_m2=qr.value(2).toFloat();
        piece_par_cartons=qr.value(3).toFloat();
        dimension=qr.value(4).toFloat();
        //if(pu.isEmpty()){
            pu=qr.value(5).toString();
        //}

    }

    ui->nb_cartons->setText("0 crt");
    ui->nb_m2->setText("0 m2");
    ui->nb_pieces->setText("0 pcs");

    //############################################################

        //ui->nb_m2->setText(qte+" m2");
        float nb_total_piece=qte.toFloat()*piece_par_m2;
        float nb_total_cartons=nb_total_piece/piece_par_cartons;
        ui->calcul->setToolTip(QString::number(nb_total_cartons));
         //ui->nb_cartons->setText(QString::number(nb_total_cartons)+" crt");
        if(nb_total_cartons>1){
            int nb_cartons=(int)nb_total_cartons;
            float reste=nb_total_cartons - nb_cartons;
            float reste_piece=reste*piece_par_cartons;
            ui->calcul->setText(QString::number(nb_cartons)+" cartons "+QString::number(reste_piece)+" pieces");
           // ui->nb_pieces->setText(QString::number(reste_piece)+" pcs");
        }else if(nb_total_cartons<1){
            ui->calcul->setText(QString::number(nb_total_piece)+" pieces");
           // ui->nb_pieces->setText(QString::number(nb_total_piece)+" pcs");
        }else{
            ui->calcul->setText(QString::number(nb_total_cartons)+" cartons");
            //ui->nb_cartons->setText(QString::number(nb_total_cartons) +" crt");
        }

    //############################################################

    //############################################################
    if(ui->unite->currentIndex()==0){
        ui->nb_m2->setText(qte+" m2");
        float nb_total_piece=qte.toFloat()*piece_par_m2;
        float nb_total_cartons=nb_total_piece/piece_par_cartons;
        ui->nb_cartons->setText(QString::number(nb_total_cartons)+" crt");
        ui->nb_pieces->setText(QString::number(nb_total_piece)+" pcs");
        ui->pu->setText(pu);

    }
    //############################################################

    //############################################################
    if(ui->unite->currentIndex()==1){
        ui->nb_cartons->setText(qte+" crt");
        float nb_total_piece=qte.toFloat()*piece_par_cartons;
        float nb_total_m2=nb_total_piece/piece_par_m2;
        ui->nb_m2->setText(QString::number(nb_total_m2)+" m2");
        ui->nb_pieces->setText(QString::number(nb_total_piece)+" pcs");

        int new_pu=int(pu.toFloat()*nb_total_m2/qte.toFloat());
        qDebug()<<"the new pu is "<<QString::number(new_pu);
       ui->pu->setText(QString::number(new_pu));
       ui->calcul->setText(ui->qte->text());

    }
    //############################################################


    //############################################################
    if(ui->unite->currentIndex()==2){
        ui->nb_pieces->setText(qte+" pcs");
        float nb_total_cartons=qte.toFloat()/piece_par_cartons;
        float nb_total_m2=qte.toFloat()/piece_par_m2;
        ui->nb_cartons->setText(QString::number(nb_total_cartons)+" crt");
        ui->nb_m2->setText(QString::number(nb_total_m2)+" m2");
        int new_pu=int(pu.toFloat()*nb_total_m2/qte.toFloat());
        ui->pu->setText(QString::number(new_pu));
        ui->calcul->setText(ui->qte->text());
    }
    //############################################################

    ui->total->setText(QString::number(qte.toFloat()*pu.toFloat()));




}

void MainWindow::make_vente_calculation(int round)
{
    int index=ui->produits->currentIndex();

    QString f=formats.at(index);


    if(f=="-"){
        ui->calcul->setToolTip(ui->qte->text());
        return;
    }
    if(index==0){
        return;
    }
    QString qte=ui->qte->text();
    if(qte.isEmpty()){
        return;
    }

    QString pu=ui->pu->text();
    if(pu.isEmpty()){
        return;
    }

    ui->unite->setEnabled(true);
   // ui->calcul->setEnabled(true);

    QString id_produit=ui->produits->currentData().toString();
    QString id_format="";
    QSqlQuery qr;
    qr.exec("select * from stock where token_id='"+id_produit+"'");
    if(qr.next()){
        id_format=qr.value("format").toString();
    }
    if(id_format=="-"){
        return;
    }

    int new_index=index-1;
    float piece_par_m2=pieces_par_m2.at(new_index).toFloat();
    float piece_par_cartons=pieces_par_cartons.at(new_index).toFloat();
    float dimension=dimensions.at(new_index).toFloat();

    qr.exec("select * from formats where token_id='"+id_format+"'");
    if(qr.next()){
        piece_par_m2=qr.value(2).toFloat();
        piece_par_cartons=qr.value(3).toFloat();
        dimension=qr.value(4).toFloat();
        if(pu.isEmpty()){
            pu=qr.value(5).toString();
        }

    }






    float nb_total_piece=qte.toFloat()*piece_par_m2;
    float nb_total_cartons=nb_total_piece/piece_par_cartons;
    ui->calcul->setToolTip(QString::number(nb_total_cartons));

    if(nb_total_cartons>1){
        int nb_cartons=(int)nb_total_cartons;
        float reste=nb_total_cartons - nb_cartons;
        float reste_piece=reste*piece_par_cartons;

        QString exces=QString::number(ceil(reste_piece));
        QString defaut=QString::number(floor(reste_piece));
        qDebug()<<"the rest is "<<QString::number(reste)<<" = "<<QString::number(reste_piece)<<" exce="<<exces<<" defaut="<<defaut;

        if(round==0){
            ui->calcul->setText(QString::number(nb_cartons)+" cartons "+QString::number(floor(reste_piece))+" pieces");
        }else{
            ui->calcul->setText(QString::number(nb_cartons)+" cartons "+QString::number(ceil(reste_piece))+" pieces");
        }
    }else if(nb_total_cartons<1){
        ui->calcul->setText(QString::number(nb_total_piece)+" pieces");
    }else{
        ui->calcul->setText(QString::number(nb_total_cartons)+" cartons");
    }

    ui->total->setText(QString::number(qte.toFloat()*pu.toFloat()));


}

void MainWindow::on_qte_textChanged(const QString &arg1)
{

    if(ui->label_format->text()=="-"){
        if(!ui->qte->text().isEmpty() && !ui->pu->text().isEmpty()){
            double qte=ui->qte->text().toDouble();
            double pu=ui->pu->text().toDouble();
            double total=qte*pu;
            ui->total->setText(QString::number(total));
            ui->calcul->setToolTip(QString::number(qte));
            ui->calcul->setText(QString::number(qte));
        }else{
            ui->total->setText("");
        }


        return;
    }

    if(ui->unite->currentIndex()!=0){
        ui->calcul->setText(arg1);
        //return;
    }
    if(ui->unite->currentIndex()!=0){
        ui->calcul->setText(ui->qte->text());
    }
    make_vente_calculation();

    if(ui->qte->text()!=""){
        float pu=ui->pu->text().toFloat();
        float total=pu*ui->qte->text().toFloat();
        ui->total->setText(QString::number(total));
    }
}

void MainWindow::on_pu_textChanged(const QString &arg1)
{
    if(ui->label_format->text()=="-"){
        if(!ui->qte->text().isEmpty() && !ui->pu->text().isEmpty()){
            double qte=ui->qte->text().toDouble();
            double pu=ui->pu->text().toDouble();
            double total=qte*pu;
            ui->total->setText(QString::number(total));
            ui->calcul->setText(QString::number(qte));
        }else{
            ui->total->setText("");
        }
        return;
    }

    if(ui->unite->currentIndex()!=0){
        QString q=ui->qte->text();
        QString p=ui->pu->text();
        QString t=QString::number(q.toFloat()*p.toFloat());
        ui->calcul->setText(q);
        ui->total->setText(t);
        //return;
    }
    //make_vente_calculation();

    if(ui->qte->text()!=""){
        float pu=arg1.toFloat();
        float total=pu*ui->qte->text().toFloat();
        ui->total->setText(QString::number(total));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString produit=ui->produits->currentText();
    QString id_produit=ui->produits->currentData().toString();
    QString qte=ui->calcul->text();
    QString total=ui->total->text();
    QString f=ui->label_format->text();
    QString pu=ui->pu->text();
    QString m2=ui->qte->text();
    QString nb_carton=ui->calcul->toolTip();
    QString unite=ui->unite->currentText();
    QString total_cartons=ui->nb_cartons->text();
    QString total_m2=ui->nb_m2->text();
    QString total_pieces=ui->nb_pieces->text();

    if(produit.isEmpty() || qte.isEmpty() || total.isEmpty()){
        return;
    }


    QString str_produit=produit;
    if(f!="-"){
        str_produit+="-"+f;
    }

    vente_produit.append(id_produit);
    vente_produit_format.append(str_produit);
    vente_qte.append(qte);
    vente_total.append(total);
    vente_pu.append(pu);
    vente_carton.append(nb_carton);
    vente_qte_m2.append(m2);
    unites.append(unite);
    vente_total_cartons.append(total_cartons);
    vente_total_m2.append(total_m2);
    vente_total_pieces.append(total_pieces);

    int old_size=ui->table_vente->rowCount();
    old_size++;
    ui->table_vente->setRowCount(old_size);
    int row=old_size-1;
    ui->table_vente->setItem(row,0,new QTableWidgetItem(str_produit));
    if(unite!="m2"){
        ui->table_vente->setItem(row,1,new QTableWidgetItem(qte+" "+unite+"(s)"));
    }else{
        ui->table_vente->setItem(row,1,new QTableWidgetItem(qte));
    }

    ui->table_vente->setItem(row,2,new QTableWidgetItem(total));
    ui->table_vente->item(row,0)->setToolTip(str_produit);
    ui->table_vente->item(row,1)->setToolTip(qte);
    ui->table_vente->item(row,2)->setToolTip(total);
    ui->table_vente->item(row,2)->setTextAlignment(Qt::AlignCenter);
    ui->table_vente->item(row,1)->setTextAlignment(Qt::AlignCenter);

    ui->table_vente->item(row,1)->setToolTip(QString::number(row));
   // ui->table_vente->setColumnWidth(2,80);
    ui->produits->setCurrentIndex(0);
    ui->qte->setText("");
    ui->pu->setText("");
    ui->total->setText("");
    ui->calcul->setText("");

    float sub_total=0;
    for(int i=0; i<old_size; i++){
        float v=ui->table_vente->item(i,2)->text().toFloat();
        sub_total+=v;
    }
    ui->total_facture->setText("Total = "+QString::number(sub_total)+" F CFA");
}

void MainWindow::load_points_vente()
{
    QStringList data;
    QStringList adresses;
    QStringList responsables;
    QStringList contacts;





    QSqlQuery qr;
    QString my_id="";
    qr.exec("select * from user");
    if(qr.next()){
        my_id=qr.value(0).toString();
    }
    qr.exec("select * from users where token_id='"+my_id+"'");
    QString user_type="";
    QString user_point_vente="";
    if(qr.next()){
        user_type=qr.value("type").toString();
        user_point_vente=qr.value("point_vente").toString();
    }

    QString req1="select count(*) from points_vente";
    QString req2="select * from points_vente";

    if(user_type!="Admin"){
        req1="select count(*) from points_vente where token_id='"+user_point_vente+"'";
        req2="select * from points_vente where token_id='"+user_point_vente+"'";
    }

    qr.exec(req1);
    int total=0;
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    qreal size=total/2.0;
    double nb_rows=qCeil(size);
    int index=0;


    qr.exec(req2);
    while(qr.next()){
        QString id=qr.value(0).toString();
        QString adr=qr.value(1).toString();
        QString resp=qr.value(2).toString();
        QString ct=qr.value(3).toString();
        QString token_id=qr.value("token_id").toString();
        data.append(token_id);
        adresses.append(adr);
        responsables.append(resp);
        contacts.append(ct);

    }

    QSignalMapper* mapper = new QSignalMapper (this) ;
    connect(mapper,SIGNAL(mapped(QString)),this,SLOT(point_vente_clicked(QString)));


    for(int r=0; r<nb_rows; r++){
        for(int c=0; c<2; c++){
            if(data.length()==index){
                continue;
            }


            QPushButton *a_point_vente=new QPushButton();

            connect(a_point_vente,SIGNAL(clicked()),mapper,SLOT(map()));
            mapper->setMapping(a_point_vente,data.at(index));

            a_point_vente->setMinimumSize(80,70);
            a_point_vente->setStyleSheet("background-color:white;border:none");

            QVBoxLayout *layout=new QVBoxLayout();

            QLabel *adresse=new QLabel(adresses.at(index).toUpper());
            adresse->setStyleSheet("color:black; font-weight:bold;font-size:10px");
            adresse->setWordWrap(false);

            QLabel *responsable=new QLabel(responsables.at(index));
            responsable->setStyleSheet("font-size:10px");

            QLabel *contact=new QLabel(contacts.at(index));
            contact->setStyleSheet("font-size:10px");


            layout->addWidget(adresse);
            layout->addWidget(responsable);
            layout->addWidget(contact);

            a_point_vente->setLayout(layout);
            a_point_vente->setToolTip(adresses.at(index).toUpper());



            ui->grid_point_de_vente->addWidget(a_point_vente,r,c);
            ui->grid_point_de_vente->setRowStretch(r,1);
            //ui->grid_point_de_vente->setMargin(10);
            index++;
        }

    }


    ui->inventaire_point_vente->clear();
    ui->inventaire_point_vente->addItem("Tous");
    for(int i=0; i<adresses.length(); i++){
        qDebug()<<"the data is "<<data.at(i)<<adresses.at(i);
        ui->inventaire_point_vente->addItem(adresses.at(i).toUpper(),QVariant(data.at(i).toInt()));
    }

    if(user_type!="Admin"){
        ui->inventaire_point_vente->setCurrentIndex(1);
        ui->inventaire_point_vente->setEnabled(false);
    }
}

void MainWindow::load_users()
{
    QSqlQuery qr;
    qr.exec("select * from user");
    QString id_user="";
    QString id_user_pv="";
    if(qr.next()){
        id_user=qr.value(0).toString();
        id_user_pv=qr.value(1).toString();
    }

    QString type_user="";
    qr.exec("select * from users where token_id='"+id_user+"'");
    if(qr.next()){
        type_user=qr.value("type").toString();
    }

    QString req="select * from users";
    if(type_user!="Admin"){
        req+=" where token_id='"+id_user+"'";
    }
    qr.exec(req);
    ui->inventaire_utilisateurs->clear();
    ui->inventaire_utilisateurs->addItem("Tous");

    ui->utilisateur_recette->clear();
    ui->utilisateur_recette->addItem("Tous");

    while(qr.next()){
        QString nom=qr.value(1).toString();
        QVariant data=qr.value("token_id");
        ui->inventaire_utilisateurs->addItem(nom.toUpper(),qr.value("token_id"));
        ui->utilisateur_recette->addItem(nom.toUpper(),data);

    }

    if(type_user!="Admin"){
        ui->utilisateur_recette->setCurrentIndex(1);
        ui->utilisateur_recette->setEnabled(false);

        ui->inventaire_utilisateurs->setCurrentIndex(1);
        ui->inventaire_utilisateurs->setEnabled(false);
    }



}

void MainWindow::on_pushButton_9_clicked()
{
    load_points_vente();
}

void MainWindow::on_actionListe_des_utilisateurs_triggered()
{
    list_users=new ListeUsers(db,this);
    list_users->setModal(true);
    list_users->show();
}

void MainWindow::on_actionListe_des_points_de_vente_triggered()
{
    list_point_vente=new listpointvente(this);
    list_point_vente->setModal(true);
    list_point_vente->show();
}

void MainWindow::on_actionListe_des_clients_triggered()
{
    list_clients=new listclients(this);
    list_clients->setModal(true);
    list_clients->show();
}

void MainWindow::on_toolButton_12_clicked()
{
    transfert_produit=new TransfertProduits(this);
    transfert_produit->setModal(true);
    transfert_produit->show();
}

void MainWindow::on_toolButton_13_clicked()
{
    depenses=new Depenses(this);
    depenses->setModal(true);
    depenses->show();
}

void MainWindow::on_toolButton_10_clicked()
{
    bris=new Bris(this);
    bris->setModal(true);
    bris->show();
}

void MainWindow::on_toolButton_11_clicked()
{
    retrait=new Retrait(this);
    retrait->setModal(true);
    retrait->show();
}

void MainWindow::point_vente_clicked(QString id)
{
    info_point_vente=new InfoPointDeVente(id,this);
    info_point_vente->setModal(true);
    info_point_vente->show();
}

void MainWindow::load_stock_alerte()
{
    QHBoxLayout *layout_stock_alerte=new QHBoxLayout();


    if(ui->stock_alerte->layout()!=NULL){
       QLayoutItem *item;
       while((item=ui->stock_alerte->layout()->takeAt(0))!=NULL){
           delete item->widget();
           delete item;
       }
       delete ui->stock_alerte->layout();
    }

    ui->stock_alerte->setLayout(layout_stock_alerte);

    QSignalMapper* mapper = new QSignalMapper (this) ;
    connect(mapper,SIGNAL(mapped(QString)),this,SLOT(stock_alerte_clicked(QString)));
    QLabel *no_data=new QLabel("Aucun produit n'a franchit le seuil d'alerte");
    no_data->setStyleSheet("text-align:center;width:100%");


    QSqlQuery qr;
    QString my_id="";
    QString type_user="";
    QString my_pv="";
    qr.exec("select * from user");
    if(qr.next()){
        my_id=qr.value(0).toString();
    }
    qr.exec("select * from users where token_id='"+my_id+"'");
    if(qr.next()){
        type_user=qr.value("type").toString();
        my_pv=qr.value("point_vente").toString();
    }
    qr.exec("select * from stock where alerte <>''");
    int i=0;
    while(qr.next()){
        QString id_produit=qr.value("token_id").toString();
        float sa=qr.value("alerte").toFloat();

        QSqlQuery qr3;

        if(type_user=="Admin"){
            qr3.exec("select distinct point_vente from mouvements");
        }else{
            qr3.exec("select distinct point_vente from mouvements where point_vente='"+my_pv+"'");
        }

        while(qr3.next()){
            QString id_pv=qr3.value(0).toString();
            if(id_pv=="-"){
                continue;
            }
            QSqlQuery qr2;
            qr2.exec("select sum(total_cartons) from mouvements where produit='"+id_produit+"' and point_vente='"+id_pv+"'");
            float in_stock=0;
            if(qr2.next()){
                in_stock=qr2.value(0).toFloat();
            }

            if(in_stock>sa){
                continue;
            }
            QString nom_pv="";
            qr2.exec("select * from points_vente where token_id='"+id_pv+"'");
            if(qr2.next()){
                nom_pv=qr2.value("adresse").toString();
            }

            QString nom_produit="";
            qr2.exec("select * from stock where token_id='"+id_produit+"'");
            if(qr2.next()){
                nom_produit=qr2.value("nom").toString();
            }

            QVBoxLayout *a_layout=new QVBoxLayout();

            QLabel *avatar=new QLabel("SA : "+QString::number(sa)+" crts");
            avatar->setAlignment(Qt::AlignCenter);

            QLabel *nom_client=new QLabel(nom_produit.toUpper());
            nom_client->setAlignment(Qt::AlignCenter);
            nom_client->setStyleSheet("font-size:10px;font-weight:bold;color:black");

            QLabel *montant_impaye=new QLabel(QString::number(in_stock)+" crts");
            montant_impaye->setStyleSheet("color:indianred");

             nom_client->setStyleSheet("font-size:10px;");
            montant_impaye->setAlignment(Qt::AlignCenter);



            a_layout->addWidget(nom_client);
            a_layout->addWidget(avatar);
            a_layout->addWidget(montant_impaye);


            QPushButton *alerte=new QPushButton();
            alerte->setToolTip(nom_pv);
            alerte->setStyleSheet("border:none;background-color:white;");
            connect(alerte,SIGNAL(clicked()),mapper,SLOT(map()));
            mapper->setMapping(alerte,id_produit+"#"+id_pv);


            alerte->setMinimumSize(50,70);
            alerte->setMaximumSize(100,70);
            alerte->setLayout(a_layout);

            if(i<=3){
                layout_stock_alerte->addWidget(alerte);
            }
            i++;
        }
    }

    if(i==0){
        layout_stock_alerte->addWidget(no_data);
    }

}

void MainWindow::load_client_impaye()
{
    QHBoxLayout *layout_impayes=new QHBoxLayout();
    if(ui->impayes->layout()!=NULL){
       QLayoutItem *item;
       while((item=ui->impayes->layout()->takeAt(0))!=NULL){
           delete item->widget();
           delete item;
       }
       delete ui->impayes->layout();
    }
    ui->impayes->setLayout(layout_impayes);



    QSignalMapper* mapper = new QSignalMapper (this) ;
    connect(mapper,SIGNAL(mapped(QString)),this,SLOT(client_impaye_clicked(QString)));

    QLabel *no_data=new QLabel("Aucune facture impayée");
    no_data->setStyleSheet("text-align:center;width:100%");


    QSqlQuery qr;
    qr.exec("select * from user");
    QString id_user="";
    if(qr.next()){
        id_user=qr.value(0).toString();
    }

    QString type_user="";
    qr.exec("select * from users where token_id='"+id_user+"'");
    if(qr.next()){
        type_user=qr.value("type").toString();
    }

   // qr.exec("select * from mouvements where user")


   qr.exec("select * from ventes_options where impaye<>'' order by id asc");
   int i=0;
   while(qr.next()){
    QString token=qr.value("token").toString();
    QString impaye=qr.value("impaye").toString().split("#").at(2);
    QString id_client=qr.value("client").toString();



    if(i>=4){
        i++;
        continue;
    }

    qDebug()<<"the user is "<<type_user;

    QSqlQuery qr2;
    if(type_user!="Admin"){
        qr2.exec("select * from mouvements where token='"+token+"'");
        if(qr2.next()){
            QString m_id_user=qr2.value("user").toString();
            if(m_id_user!=id_user){
                continue;
            }
        }
    }
    qr2.exec("select * from clients where token_id='"+id_client+"'");
    QString str_nom_client="";
    QString str_contact_client="";
    if(qr2.next()){
        str_nom_client=qr2.value("nom").toString();
        str_contact_client=qr2.value("contact").toString();
    }
    QVBoxLayout *a_layout=new QVBoxLayout();

    QLabel *avatar=new QLabel(token);
    avatar->setAlignment(Qt::AlignCenter);
    avatar->setStyleSheet("color:gray;font-size:7px");
    /*QPixmap watermark2(":/img/images/people-outline.svg");
    QPixmap newPixmap2 = watermark2.scaled(QSize(25,25),  Qt::KeepAspectRatio);
    avatar->setPixmap(newPixmap2);*/

    QLabel *nom_client=new QLabel(str_nom_client.toUpper());
    nom_client->setAlignment(Qt::AlignCenter);
    nom_client->setStyleSheet("font-size:10px;font-weight:bold");

    QLabel *montant_impaye=new QLabel(impaye+" Fr");

    montant_impaye->setAlignment(Qt::AlignCenter);


    a_layout->addWidget(nom_client);
    a_layout->addWidget(montant_impaye);
    a_layout->addWidget(avatar);

    QPushButton* btn_client=new QPushButton();
    btn_client->setLayout(a_layout);
    btn_client->setMinimumSize(60,70);
    btn_client->setMaximumSize(100,70);
    btn_client->setStyleSheet("background-color:white;border:none");

    connect(btn_client,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(btn_client,token);


      layout_impayes->addWidget(btn_client);

    i++;

   }

   if(i==0){
       layout_impayes->addWidget(no_data);
   }

}

void MainWindow::load_client_pre_paye()
{

    QHBoxLayout *layout_impayes=new QHBoxLayout();
    if(ui->list_prepaye->layout()!=NULL){
       QLayoutItem *item;
       while((item=ui->list_prepaye->layout()->takeAt(0))!=NULL){
           delete item->widget();
           delete item;
       }
       delete ui->list_prepaye->layout();
    }

    ui->list_prepaye->setLayout(layout_impayes);

    QSignalMapper* mapper = new QSignalMapper (this) ;
    connect(mapper,SIGNAL(mapped(QString)),this,SLOT(client_pre_paye_clicked(QString)));

    QLabel *no_data=new QLabel("Aucun pré-payement");
    no_data->setStyleSheet("text-align:center;width:100%");
    //layout_impayes->addWidget(no_data);

    QSqlQuery qr;
    qr.exec("select * from user");
    QString my_id="";
    QString type_user="";
    if(qr.next()){
        my_id=qr.value(0).toString();
    }
    qr.exec("select * from users where token_id='"+my_id+"'");
    if(qr.next()){
        type_user=qr.value("type").toString();
    }

    QString req="select distinct client from prepayements";
    if(type_user!="Admin"){
        req+=" where user='"+my_id+"'";
    }
    req+=" limit 4";
    qr.exec(req);
    int i=0;
    while(qr.next()){
        QString id_client=qr.value(0).toString();
        QSqlQuery qr2;

        QString montant="";
        qr2.exec("select sum(montant) from prepayements where client='"+id_client+"'");
        if(qr2.next()){
            montant=qr2.value(0).toString();
        }

        QString id_line=id_client;


        qr2.exec("select * from clients where token_id='"+id_client+"'");
        QString str_nom_client="";
        if(qr2.next()){
            str_nom_client=qr2.value("nom").toString();
        }


        QVBoxLayout *a_layout=new QVBoxLayout();

        QLabel *avatar=new QLabel();
        avatar->setAlignment(Qt::AlignCenter);
        QPixmap watermark2(":/img/images/people-outline.svg");
        QPixmap newPixmap2 = watermark2.scaled(QSize(25,25),  Qt::KeepAspectRatio);
        avatar->setPixmap(newPixmap2);

        QLabel *nom_client=new QLabel(str_nom_client.toUpper());
        nom_client->setAlignment(Qt::AlignCenter);
        nom_client->setStyleSheet("font-size:10px;font-weight:bold");

        QLabel *montant_impaye=new QLabel(montant+" Fr");
         nom_client->setStyleSheet("font-size:10px;");
        montant_impaye->setAlignment(Qt::AlignCenter);

        a_layout->addWidget(avatar);
        a_layout->addWidget(nom_client);
        a_layout->addWidget(montant_impaye);

        QPushButton* btn_client=new QPushButton();
        btn_client->setLayout(a_layout);
        btn_client->setMinimumSize(50,70);
         btn_client->setMaximumSize(100,70);
        btn_client->setStyleSheet("background-color:white;border:none;");

        connect(btn_client,SIGNAL(clicked()),mapper,SLOT(map()));
        mapper->setMapping(btn_client,id_line);

        if(i<=3){
            layout_impayes->addWidget(btn_client);
        }


        i++;
    }

    if(i==0){
        layout_impayes->addWidget(no_data);
    }


}

void MainWindow::load_produits()
{
    QSqlQuery qr;
    qr.exec("select * from stock");
    ui->produits->clear();
    ui->produits->addItem("");
    ui->inventaire_type->clear();
    ui->inventaire_type->addItem("Tous");
    while(qr.next()){
        ui->produits->addItem(qr.value("nom").toString().toUpper(),qr.value("token_id"));
        ui->inventaire_type->addItem(qr.value("nom").toString().toUpper(),qr.value("token_id"));
    }
}

void MainWindow::load_clients()
{
    QSqlQuery qr;
    qr.exec("select * from clients");
    ui->list_clients->clear();
    ui->list_clients->addItem("Choisir un client");
    while(qr.next()){
        ui->list_clients->addItem(qr.value("nom").toString().toUpper(),qr.value("token_id"));
    }
}

void MainWindow::load_formats()
{
    QSqlQuery qr;
    qr.exec("select * from formats");
    ui->inventaire_format->clear();
    ui->inventaire_format->addItem("Tous");
    while(qr.next()){
        QString nom=qr.value("nom").toString();

        ui->inventaire_format->addItem(nom,qr.value("token_id"));
    }
}

void MainWindow::carreaux_settings()
{
    QSqlQuery qr;
    qr.exec("select * from stock");
    formats.append("");
    pieces_par_m2.append("");
    pieces_par_cartons.append("");
    dimensions.append("");
    while(qr.next()){

        QString nom=qr.value("format").toString();
        formats.append(nom.toUpper());

        QSqlQuery qr2;
        qr2.exec("select * from formats where token_id='"+nom+"'");
        if(qr2.next()){
            QString ppm=qr2.value("pieces_par_m2").toString();
            QString ppc=qr2.value("pieces_par_carton").toString();
            QString d=qr2.value("dimension").toString();

            pieces_par_m2.append(ppm);
            pieces_par_cartons.append(ppc);
            dimensions.append(d);
        }


    }
}

void MainWindow::stock_alerte_clicked(QString id)
{
    info_stock_alerte=new InfoStockAlerte(id,this);
    info_stock_alerte->setModal(true);
    info_stock_alerte->show();
}

void MainWindow::client_impaye_clicked(QString id)
{
    QSqlQuery qr;
    qr.exec("delete from token");
    qr.exec("insert into token values('"+id+"')");

    QString id_client="";

    qr.exec("select * from ventes_options where token='"+id+"'");
    if(qr.next()){
        id_client=qr.value("client").toString();
    }

    info_client=new InfoClient(id_client,this);
    info_client->setModal(true);
    info_client->show();
}

void MainWindow::client_pre_paye_clicked(QString id)
{
    client_prepayement=new ClientPrePayement(id,this);
    client_prepayement->setModal(true);
    client_prepayement->show();
}

void MainWindow::view_all_clients_impaye(QString id)
{
    all_impayes=new AllImpayes(this);
    all_impayes->setModal(true);
    all_impayes->show();
}

void MainWindow::on_actionCat_gories_triggered()
{
    list_format=new Listformat(this);
    list_format->setModal(true);
    list_format->show();
}

void MainWindow::on_actionAjouter_triggered()
{
    ajout_carreaux=new AjoutCarreaux(this);
    ajout_carreaux->setModal(true);
    ajout_carreaux->show();
}

void MainWindow::on_actionAutres_produits_triggered()
{
    ajout_autres=new AjoutAutres(this);
    ajout_autres->setModal(true);
    ajout_autres->show();
}



void MainWindow::on_pushButton_6_clicked()
{

    if(vente_produit.length()==0){
        QMessageBox::warning(this,"Aucune information","Aucune information n'est trouvée sur la facture");
        return;
    }

    if(ui->list_clients->currentIndex()==0){
        QMessageBox::warning(this,"Aucun client","Vous devez choisir un  client");
        return;
    }

    QString client=ui->list_clients->currentData().toString();
    QString non_livre="0";
    if(ui->non_livre->isChecked()){
        non_livre="1";
    }else{
        non_livre="0";
    }

    QSqlQuery qr;
    QString token_id=QString::number(QDateTime::currentDateTime().toTime_t());
    QString token=QString::number(QDateTime::currentDateTime().toTime_t());
    for(int i=0; i<vente_produit.length(); i++){
        QString v_pr=vente_produit.at(i);
        QString v_pr_f=vente_produit_format.at(i);
        QString v_qte=vente_qte.at(i);
        QString v_pu=vente_pu.at(i);
        QString v_t=vente_total.at(i);
        QString nb_carton=vente_carton.at(i);
        QString v_qte_m2=vente_qte_m2.at(i);
        QString unite=unites.at(i);
        QString v_t_carton=vente_total_cartons.at(i);
        QString v_t_m2=vente_total_m2.at(i);
        QString v_t_pieces=vente_total_pieces.at(i);


        QSqlQuery qr2;
        qr2.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token,qte_m2,prix,unite,token_id,total_cartons,total_m2,total_pieces) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token,:qte_m2,:prix,:unite,:token_id,:total_cartons,:total_m2,:total_pieces)");
        qr2.bindValue(":date",QDateTime::currentDateTime());
        qr2.bindValue(":type","2");
        qr2.bindValue(":produit",v_pr);
        qr2.bindValue(":qte","-"+nb_carton);
        qr2.bindValue(":user",id_user);
        qr2.bindValue(":point_vente",user_info.at(4));
        qr2.bindValue(":nb_cartons",v_qte);
        qr2.bindValue(":token",token);
        qr2.bindValue(":qte_m2","-"+v_qte_m2);
        qr2.bindValue(":prix",v_pu);
        qr2.bindValue(":unite",unite);
        qr2.bindValue(":token_id",token_id+QString::number(i));
        qr2.bindValue(":total_cartons","-"+v_t_carton.replace(" crt",""));
        qr2.bindValue(":total_m2","-"+v_t_m2.replace(" m2",""));
        qr2.bindValue(":total_pieces","-"+v_t_pieces.replace(" pcs",""));
        qr2.exec();




    }

    qr.exec("select * from remise");
    QString remise="";
    if(qr.next()){
        remise=qr.value("total").toString()+"#"+qr.value("montant").toString()+"#"+qr.value("reste").toString();
    }

    qr.exec("select * from impaye");
    QString impaye="";
    if(qr.next()){
        impaye=qr.value("total").toString()+"#"+qr.value("montant").toString()+"#"+qr.value("reste").toString();
    }

    qr.exec("select * from biz");
    QString biz="";
    while(qr.next()){
        biz+=qr.value(1).toString()+"#"+qr.value(2).toString()+"#"+qr.value(3).toString()+"#"+qr.value(4).toString()+"$";
    }

    qr.exec("delete from biz");
    qr.exec("delete from impaye");
    qr.exec("delete from remise");


    qr.exec("insert into ventes_options(token,biz,remise,impaye,client,non_livre,token_id) values('"+token+"','"+biz+"','"+remise+"','"+impaye+"','"+client+"','"+non_livre+"','"+token_id+"')");

    ui->table_vente->setRowCount(0);
    ui->total_facture->setText("Total = 0 F CFA");
    ui->label_remise->setText("Remise = 0 F CFA");
    vente_produit.clear();
    vente_carton.clear();
    vente_produit_format.clear();
    vente_pu.clear();
    vente_qte.clear();
    vente_qte_m2.clear();
    vente_total.clear();
    unites.clear();
    vente_total_cartons.clear();
    vente_total_m2.clear();
    vente_total_pieces.clear();
    ui->unite->setCurrentIndex(0);
    //vente_client="";
    ui->list_clients->setCurrentIndex(0);
    ui->non_livre->setChecked(false);

    load_recette();
    load_client_impaye();
    load_stock_alerte();
    if(non_livre=="0"){
        print_facture(token);
    }
    load_inventaire();

    synchroniser("clients,mouvements,ventes_options");



}

QString MainWindow::espace(int n)
{
    QString v="";
      for(int i=0; i<n; i++){
          v+="&nbsp;";
      }

      //v="";
      return v;
}

void MainWindow::on_pushButton_10_clicked()
{
    load_clients();
}

void MainWindow::on_pushButton_clicked()
{
    list_clients=new listclients(this);
    list_clients->setModal(true);
    list_clients->show();
}

void MainWindow::on_produits_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_produits_currentTextChanged(const QString &arg1)
{

}

void MainWindow::load_user_info()
{
    QSqlQuery qr;
    qr.exec("select * from users where token_id='"+id_user+"'");
    qDebug()<<"select * from users where token_id='"+id_user+"'";
    if(qr.next()){
        QString nom=qr.value("nom").toString().toUpper();
        QString login=qr.value("login").toString();
        QString password=qr.value("password").toString();
        QString type=qr.value("type").toString();
        QString point_vente=qr.value("point_vente").toString();

        user_info.append(nom);
        user_info.append(login);
        user_info.append(password);
        user_info.append(type);
        user_info.append(point_vente);
    }

}

void MainWindow::load_inventaire()
{
    qDebug()<<"the index is "<<QString::number(selected_row_inventaire);
    QSqlQuery qr;
   // QString type=ui->inventaire_type->currentText();
    //QString pv=ui->inven
    QString req="select * from mouvements where '1'='1' ";

    if(ui->inventaire_format->currentIndex()!=0){
        //req+=" and format='"+ui->inventaire_format->currentData().toString()+"'";
    }
    if(ui->inventaire_type->currentIndex()!=0){
        req+=" and produit='"+ui->inventaire_type->currentData().toString()+"'";
    }


    if(ui->inventaire_point_vente->currentIndex()!=0){
       // req+=" and point_vente='"+ui->inventaire_point_vente->currentData().toString()+"'";
    }
    if(ui->inventaire_utilisateurs->currentIndex()!=0){
       // req+=" and user='"+ui->inventaire_utilisateurs->currentData().toString()+"'";
    }

    QString du=ui->inventaire_du_2->date().toString("yyyy-MM-dd");
    QString au=ui->inventaire_au->date().addDays(1).toString("yyyy-MM-dd");

    if(du==au){
        req+=" and date '"+du+"'";
    }else{
        req+=" and date between '"+du+"' and '"+au+"'";
    }

    bool affichage_m2=ui->affichage_m2->isChecked();
    bool affichage_cartons=ui->affichage_cartons->isChecked();
    bool affichage_pieces=ui->affichage_pieces->isChecked();





    int row=0;
    //ui->table_inventaire->clear();
    qDebug()<<req;
    ui->table_inventaire->setRowCount(0);
    qr.exec(req);
    int total=0;
    float cumul_qte=0;
    while(qr.next()){
        QString date=qr.value("date").toString();
        QString type=qr.value("type").toString();
        QString produit=qr.value("produit").toString();
        QString pu_tmp=qr.value("prix").toString();
        QString token=qr.value("token").toString();

        QSqlQuery qr2;
        qr2.exec("select * from stock where token_id='"+produit+"'");
        double pu=0;
        QString nom_produit="";
        QString id_format="";
        if(qr2.next()){
            if(pu_tmp.isEmpty()){
                pu=qr2.value("prix_par_m2").toDouble();
            }else{
                pu=pu_tmp.toDouble();
            }

            nom_produit=qr2.value("nom").toString();
            id_format=qr2.value("format").toString();
        }

        if(ui->inventaire_format->currentIndex()!=0){
            if(ui->inventaire_format->currentData().toString()!=id_format){
                continue;
            }
        }
        QString nom_format="";
        float qte_m2=0;
        float qte_cartons=0;
        qr2.exec("select * from formats where token_id='"+id_format+"'");
        if(qr2.next()){
            nom_format=qr2.value("nom").toString();
            qte_m2=qr2.value("pieces_par_m2").toFloat();
            qte_cartons=qr2.value("pieces_par_carton").toFloat();
        }
        QString qte=qr.value("qte_m2").toString();
        QString user=qr.value("user").toString();
        QString point_vente=qr.value("point_vente").toString();
        QString nb_cartons=qr.value("nb_cartons").toString();
        QString str_type="Vente";
        if(token=="1"){
            str_type="Entrée";
        }else if(token=="2"){
            str_type="Sortie";
        }else if(token=="3"){
            str_type="Bris";
        }else if(token=="4"){
            if(qte.toFloat()<0){
                str_type="Transfert Envoyé";
            }else{
                str_type="Transfert Reçu";
            }

        }

        QString to="m2";
        float affichage_qte=qr.value("total_m2").toFloat();
        if(affichage_cartons==true){
            affichage_qte=qr.value("total_cartons").toFloat();
            to="Carton";
        }
        if(affichage_pieces==true){
            affichage_qte=qr.value("total_pieces").toFloat();
            to="Pièce";
        }

        QString unite=qr.value("unite").toString();
        float final_price=new_price(unite,to,pu,qte_m2,qte_cartons);
        qDebug()<<"the unite is "<<unite<<QString::number(pu)<<"price is"<<QString::number(final_price);

        double t=qte.toDouble() * pu;
        total+=t;
        cumul_qte+=affichage_qte;
        float final_price1=t/affichage_qte;

        qr2.exec("select * from ventes_options where token='"+token+"'");
        QString non_livre="0";
        if(qr2.next()){
            non_livre=qr2.value("non_livre").toString();
        }



        ui->table_inventaire->setRowCount(row+1);
        ui->table_inventaire->setItem(row,0,new QTableWidgetItem(date.split("T").at(0)));
        ui->table_inventaire->setItem(row,1,new QTableWidgetItem(nom_format));
        ui->table_inventaire->setItem(row,2,new QTableWidgetItem(nom_produit));
        ui->table_inventaire->setItem(row,3,new QTableWidgetItem(str_type));
        ui->table_inventaire->setItem(row,4,new QTableWidgetItem(QString::number(affichage_qte)));
        ui->table_inventaire->setItem(row,5,new QTableWidgetItem(QString::number(cumul_qte)));
        ui->table_inventaire->setItem(row,6,new QTableWidgetItem(QString::number(final_price1)));
        ui->table_inventaire->setItem(row,7,new QTableWidgetItem(QString::number(t)));

        ui->table_inventaire->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table_inventaire->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table_inventaire->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->table_inventaire->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->table_inventaire->item(row,4)->setTextAlignment(Qt::AlignCenter);
        ui->table_inventaire->item(row,5)->setTextAlignment(Qt::AlignCenter);
        ui->table_inventaire->item(row,6)->setTextAlignment(Qt::AlignCenter);
        ui->table_inventaire->item(row,7)->setTextAlignment(Qt::AlignCenter);

         ui->table_inventaire->item(row,4)->setToolTip(token);




        if(non_livre=="1"){
            for(int x=0; x<8; x++){
                ui->table_inventaire->item(row,x)->setBackground(QBrush(QColor("pink")));
            }
        }

        row++;

    }

    if(selected_row_inventaire!=-1 && ui->table_inventaire->rowCount()>=selected_row_inventaire){

       ui->table_inventaire->setCurrentIndex(ui->table_inventaire->model()->index(selected_row_inventaire, 0));

    }

    ui->label_6->setText("Total en valeur : "+QString::number(total)+" FCFA");

}

void MainWindow::on_inventaire_type_currentIndexChanged(int index)
{
    load_inventaire();
}

void MainWindow::on_inventaire_point_vente_currentIndexChanged(int index)
{
    load_inventaire();
    if(can_update_combobox==false){
        return;
    }
   QString id_pv=ui->inventaire_point_vente->currentData().toString();
    QSqlQuery qr;
    if(index==0){
        qr.exec("select * from users");
    }else{
        qr.exec("select * from users where point_vente='"+id_pv+"'");
    }
    ui->inventaire_utilisateurs->clear();
    ui->inventaire_utilisateurs->addItem("Tous");
    while(qr.next()){
        ui->inventaire_utilisateurs->addItem(qr.value("nom").toString(),qr.value("token_id"));
    }
}

void MainWindow::on_inventaire_utilisateurs_currentIndexChanged(int index)
{
    load_inventaire();
}

void MainWindow::on_inventaire_format_currentIndexChanged(int index)
{
    load_inventaire();
}

void MainWindow::on_inventaire_du_2_dateChanged(const QDate &date)
{
    load_inventaire();
}

void MainWindow::on_inventaire_au_dateChanged(const QDate &date)
{
    load_inventaire();
}

void MainWindow::on_pushButton_7_clicked()
{
    /*vente_produit;
    vente_produit_format;
    vente_qte;
    vente_pu;
    vente_total;
    vente_carton;
    vente_client;*/
    biz=new Biz(vente_produit,vente_qte,vente_pu,vente_total,vente_carton,vente_client,vente_qte_m2,this);
    biz->setModal(true);
    biz->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    float total=0;
    for(int i=0; i<vente_total.length(); i++){
        total+=vente_total.at(i).toFloat();
    }

    if(total==0){
        return;
    }


    remise=new Remise(total,this);
    remise->setModal(true);
    remise->show();
}

void MainWindow::on_actionParametres_triggered()
{
    parametres=new Parametres(this);
    parametres->setModal(true);
    parametres->show();
}

void MainWindow::on_actionParam_tres_triggered()
{
    parametres=new Parametres(this);
    parametres->setModal(true);
    parametres->show();
}

void MainWindow::on_pushButton_11_clicked()
{
    float total=0;
    for(int i=0; i<vente_total.length(); i++){
        total+=vente_total.at(i).toFloat();
    }

    if(total==0){
        return;
    }

    impaye=new Impaye(total,this);
    impaye->setModal(true);
    impaye->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    int total=ui->table_vente->rowCount();
    if(total==0){
        return;
    }

    int row=ui->table_vente->selectedItems().at(0)->row();
    QString index=ui->table_vente->item(row,1)->toolTip();

    qDebug()<<QString::number(row)<<index<<unites.at(index.toInt())<<vente_produit.at(index.toInt());
    vente_produit.removeAt(index.toInt());
    vente_produit_format.removeAt(index.toInt());
    vente_qte.removeAt(index.toInt());
    vente_total.removeAt(index.toInt());
    vente_pu.removeAt(index.toInt());
    vente_carton.removeAt(index.toInt());
    vente_qte_m2.removeAt(index.toInt());
    unites.removeAt(index.toInt());
    vente_total_cartons.removeAt(index.toInt());
    vente_total_m2.removeAt(index.toInt());
    vente_total_pieces.removeAt(index.toInt());

    ui->table_vente->removeRow(index.toInt());

    int old_size=ui->table_vente->rowCount();
    float sub_total=0;
    for(int i=0; i<old_size; i++){
        float v=ui->table_vente->item(i,2)->text().toFloat();
        sub_total+=v;
    }
    ui->total_facture->setText("Total = "+QString::number(sub_total)+" F CFA");
    return;


    ui->table_vente->setRowCount(0);
    //vente_carton.clear();
    ui->list_clients->setCurrentIndex(0);
    ui->total_facture->setText("Total = 0 F CFA");
    vente_produit.clear();
    ui->bon->setChecked(false);
    QSqlQuery qr;
    qr.exec("delete from biz");
    qr.exec("delete from impaye");
    qr.exec("delete from remise");
    ui->label_remise->setText("Total = 0");


}

void MainWindow::load_recette()
{
    QSqlQuery qr;
    int total=0;
    float valeur_total=0;
    QString date2=ui->date_recette->date().toString("yyyy-MM-dd");

    int index_user=ui->utilisateur_recette->currentIndex();
    QString selected_user="";
    if(index_user!=0){
        selected_user=ui->utilisateur_recette->currentData().toString();
    }

    qr.exec("select count(distinct token) from mouvements where token<>'1' and token<>'2' and token<>'3' and token<>'4'");
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_recette->setRowCount(0);

    if(selected_user.isEmpty()){
        qr.exec("select distinct token from mouvements where token<>'1' and token<>'2' and token<>'3' and token<>'4' and date like '%"+date2+"%' order by id asc");
    }else{
        qr.exec("select distinct token from mouvements where token<>'1' and token<>'2' and token<>'3' and token<>'4' and date like '%"+date2+"%' and user='"+selected_user+"'  order by id asc");
    }

    int row=0;
    while(qr.next()){
        QString token=qr.value(0).toString();
        QSqlQuery qr2;
        qr2.exec("select * from mouvements where token='"+token+"' ");
        float valeur=0;
        QString date="";
        while(qr2.next()){
            float qte=qr2.value("qte_m2").toFloat();
            QString pu=qr2.value("prix").toString();
            date=qr2.value("date").toString().split('T').at(0);
            QString id_produit=qr2.value("produit").toString();
            QSqlQuery qr3;
            if(pu.isEmpty()){
                qr3.exec("select * from stock where token_id='"+id_produit+"'");
                if(qr3.next()){
                    float prix=qr3.value("prix_par_m2").toFloat();
                    valeur+=abs((int)qte)*prix;

                }
            }else{
                valeur+=abs((int)qte)*pu.toFloat();
            }

        }

        QString non_livre="0";
        QString id_facture="";
        qr2.exec("select * from ventes_options where token='"+token+"'");
        if(qr2.next()){
            non_livre=qr2.value("non_livre").toString();
            id_facture=qr2.value("id").toString();

        }


        ui->table_recette->setRowCount(row+1);
        ui->table_recette->setItem(row,0,new QTableWidgetItem(id_facture));
        ui->table_recette->setItem(row,1,new QTableWidgetItem(QString::number(valeur)));
        ui->table_recette->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table_recette->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table_recette->item(row,0)->setToolTip(token);

        if(non_livre=="1"){
            for(int x=0; x<2; x++){
                ui->table_recette->item(row,x)->setBackground(QBrush(QColor("pink")));
            }
        }

        row++;
        valeur_total+=valeur;
    }
    ui->total_recette->setText(QString::number(valeur_total));
    QString req="select sum(montant) from depenses where date='"+date2+"'";

    if(!selected_user.isEmpty()){
        req+=" and user='"+selected_user+"'";
    }
    float total_depense=0;
    qr.exec(req);
    if(qr.next()){
        total_depense=qr.value(0).toFloat();
    }
    ui->total_depense->setText("-"+QString::number(total_depense));

    QString req2="select sum(montant) from retrait where date='"+date2+"'";
    if(!selected_user.isEmpty()){
        req2+=" and user='"+selected_user+"'";
    }

    float total_retrait=0;
    qr.exec(req2);
    if(qr.next()){
        total_retrait=qr.value(0).toFloat();
    }
    ui->total_retrait->setText("-"+QString::number(total_retrait));
    float reste_recette=valeur_total - total_depense - total_retrait;
    ui->reste_recette->setText(QString::number(reste_recette));

}

void MainWindow::on_table_recette_cellClicked(int row, int column)
{
    QString token=ui->table_recette->item(row,0)->toolTip();
    QSqlQuery qr;
    qr.exec("delete from token");
    qr.exec("insert into token values('"+token+"')");

    details_vente=new DetailsVente(this);
    details_vente->setModal(true);
    details_vente->show();
}

void MainWindow::view_all_sa()
{
    all_sa=new AllSa(this);
    all_sa->setModal(true);
    all_sa->show();
}

void MainWindow::on_actionClients_avec_impay_s_triggered()
{
    all_impayes=new AllImpayes(this);
    all_impayes->setModal(true);
    all_impayes->show();
}

void MainWindow::on_actionClients_avec_pr_payements_triggered()
{
    all_pre_payement=new AllPrePayement(this);
    all_pre_payement->setModal(true);
    all_pre_payement->show();
}

void MainWindow::on_actionAlertes_triggered()
{
    all_sa=new AllSa(this);
    all_sa->setModal(true);
    all_sa->show();
}

void MainWindow::on_date_recette_dateChanged(const QDate &date)
{
    load_recette();
}

void MainWindow::on_utilisateur_recette_currentIndexChanged(int index)
{
    load_recette();
}

void MainWindow::load_droit()
{
    QSqlQuery qr;
    qr.exec("select * from user");
    QString id_user="";
    if(qr.next()){
        id_user=qr.value(0).toString();
    }

    qr.exec("select * from droit where user='"+id_user+"'");
    if(qr.next()){
        QString transfert=qr.value("transfert").toString();
        QString depenses=qr.value("depenses").toString();
        QString bris=qr.value("bris").toString();
        QString retrait=qr.value("retrait").toString();
        QString point_vente=qr.value("point_vente").toString();
        QString utilisateurs=qr.value("utilisateurs").toString();
        QString clients=qr.value("clients").toString();
        QString stock=qr.value("stock").toString();
        QString vente=qr.value("vente").toString();
        QString print_facture=qr.value("facture").toString();
        QString print_bon=qr.value("bon").toString();

        if(transfert=="0"){
            ui->toolButton_12->setStyleSheet("background-color:white;opacity:0;border:1px solid indianred;");
            ui->toolButton_12->setEnabled(false);
        }

        if(depenses=="0"){
            ui->toolButton_13->setStyleSheet("background-color:white;opacity:0;border:1px solid indianred;");
            ui->toolButton_13->setEnabled(false);
        }

        if(bris=="0"){
            ui->toolButton_10->setStyleSheet("background-color:white;opacity:0;border:1px solid indianred;");
            ui->toolButton_10->setEnabled(false);
        }

        if(retrait=="0"){
            ui->toolButton_11->setStyleSheet("background-color:white;opacity:0;border:1px solid indianred;");
            ui->toolButton_11->setEnabled(false);
        }
        if(point_vente=="0"){
            ui->menuPoints_de_vente->setDisabled(true);
        }
        if(utilisateurs=="0"){
            ui->menuUtilisateurs->setDisabled(true);
        }
        if(clients=="0"){
            //ui->menuCarreaux->setDisabled(true);
        }
        if(stock=="0"){
            ui->menuStock->setDisabled(true);
        }

        if(vente=="0" ){
            ui->pushButton_3->setStyleSheet("background-color:silver;border:none;padding:8px;");
            ui->pushButton_3->setEnabled(false);
        }

        if(print_facture=="0"){
            ui->pushButton_6->hide();
        }
        if(print_bon=="0"){
            ui->bon->hide();
        }

    }
}

void MainWindow::print_facture(QString token)
{


    QSqlQuery qr;
    bool bon2=false;
    qr.exec("select * from bon");
    if(qr.next()){
        bon2=true;
    }
    facture=new Facture(token,this);
    bon=new Bon(token,this);

    QString papier="";
    QString format="";

    qr.exec("select * from print_config");
    if(qr.next()){
        papier=qr.value("papier").toString();
        format=qr.value("format").toString();
    }


     QPrinter printer;
     if(papier=="1"){
          printer.setPaperSize(QPrinter::A4);
     }else{
          printer.setPaperSize(QPrinter::A5);
     }

     if(format=="2"){
         printer.setOrientation(QPrinter::Portrait);
     }else{
         printer.setOrientation(QPrinter::Landscape);
     }


     facture->setFixedWidth(printer.pageRect().width());

     QPainter painter;
     painter.begin(&printer);
     double xscale = printer.pageRect().width()/double(facture->width());
     double yscale = printer.pageRect().height()/double(facture->height());
     double scale = qMin(xscale, yscale);


     facture->render(&painter);
     printer.newPage();
     facture->render(&painter);
     printer.newPage();
     bon->render(&painter);
     painter.end();
     /*if(bon2){
         printer.newPage();
         bon->render(&painter);
     }*/

     qr.exec("delete from bon");
     qr.exec("delete from remise");
     qr.exec("delete from impaye");
     qr.exec("delete from biz");
}

void MainWindow::close_db()
{
    QString connection;
    connection=db.connectionName();
    db.close();
    db=QSqlDatabase();
    db.removeDatabase(connection);
}



void MainWindow::on_bon_clicked()
{
    QSqlQuery qr;
    qr.exec("delete from bon");
    if(ui->bon->isChecked()){
        qr.exec("insert into bon values('1')");
    }
}

void MainWindow::on_serveur_distant_clicked()
{
    close_db();
    QFile config("serveur.txt");
    config.open(QIODevice::WriteOnly);
    QTextStream stream(&config);

    if(ui->serveur_distant->isChecked()){
        db=QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("141.136.39.52");
        db.setUserName("assitcha_star_grace");
        db.setDatabaseName("assitcha_star_grace");
        db.setPassword("faugan2000@");
        if(db.open()){
            qDebug()<<"Remove server is up";
            stream<<1;
            config.close();
        }
    }else{
        db=QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setDatabaseName("base");
        db.setPassword("");
        if(db.open()){
            qDebug()<<"Local server is up";
            stream<<0;
            config.close();
        }
    }
}

void MainWindow::load_server()
{

    QFile server("serveur.txt");
    if(!server.exists()){
        ui->serveur_distant->setChecked(false);
        return;
    }
    server.open(QIODevice::ReadOnly);
    QTextStream stream(&server);
    QString local_server=stream.readLine();
    server.close();
    if(local_server=="0"){
        ui->serveur_distant->setChecked(false);
    }else{
        ui->serveur_distant->setChecked(true);
    }

    on_serveur_distant_clicked();


}

void MainWindow::on_actionSynchroniser_les_donn_es_triggered()
{
    int res=QMessageBox::question(this,"Confirmation","Etes-vous sûr d'effectuer la synchronisation des données ?");
    if(res==QMessageBox::Yes){

        ui->pushButton_12->setText("Synchronisation encours...");
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_12->setStyleSheet("background-color:gray;color:black;border:none;padding:8px;");
        timer->stop();

        QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
        connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
        connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
        mgr->get(QNetworkRequest(QUrl("http://127.0.0.1/db/saving.php")));
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    int res=QMessageBox::question(this,"Confirmation","Etes-vous sûr d'effectuer la synchronisation des données ?");
    if(res==QMessageBox::Yes){
        ui->pushButton_12->setText("Synchronisation encours...");
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_12->setStyleSheet("background-color:gray;color:black;border:none;padding:8px;");
        timer->stop();
        QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
        connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
        connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
        mgr->get(QNetworkRequest(QUrl("http://127.0.0.1/db/saving.php")));


    }
}

void MainWindow::all_updates()
{
    qDebug()<<"loading all updates";
    QSqlQuery qr;
    qr.exec("select * from remise");
    if(qr.next()){
        QString remise=qr.value("montant").toString();
        if(!remise.isEmpty() && ui->table_vente->rowCount()>0){
            float r=remise.toFloat();
            ui->label_remise->setText("Remise = "+remise+" F CFA");
        }else{
            ui->label_remise->setText("Remise = 0 F CFA");
        }
    }else{
        ui->label_remise->setText("Remise = 0 F CFA");
    }

    load_inventaire();
    load_stock_alerte();
    load_client_impaye();
    load_client_pre_paye();
    load_recette();
    //synchroniser("");
  //  load_user_info();
   // carreaux_settings();
   // load_points_vente();

    //load_produits();
    //load_clients();
   // load_users();
    //load_formats();


}

void MainWindow::on_btn_apercu_clicked()
{
    qDebug()<<"going to create the apercu";
    /*QStringList vente_produit;
    QStringList vente_produit_format;
    QStringList vente_qte;
    QStringList vente_qte_m2;
    QStringList vente_pu;
    QStringList vente_total;
    QStringList vente_carton;
    QStringList unites;
    QString vente_client;*/
    apercu_facture=new ApercuFactur(
                vente_produit,
                vente_produit_format,
                vente_qte,
                vente_qte_m2,
                vente_pu,
                vente_total,
                vente_carton,
                unites,
                vente_client,
                this);
    apercu_facture->setModal(true);
    apercu_facture->show();

}


void MainWindow::on_list_clients_currentIndexChanged(int index)
{
    if(index==0){
        vente_client="";
        return;
    }
    vente_client=ui->list_clients->currentData().toString();
}


void MainWindow::on_unite_currentIndexChanged(int index)
{
    if(index!=0){
        QString qte=ui->qte->text();
        ui->calcul->setText(qte);
        //return;
    }
    make_vente_calculation();

    if(ui->qte->text()!=""){
        float pu=ui->pu->text().toFloat();
        float total=pu*ui->qte->text().toFloat();
        ui->total->setText(QString::number(total));
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    make_vente_calculation(0);
}


void MainWindow::on_pushButton_14_clicked()
{
    make_vente_calculation(1);
}

void MainWindow::onfinish(QNetworkReply *rep)
{
    ui->pushButton_12->setText("Synchroniser");
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_12->setStyleSheet("background-color:green;color:white;border:none;padding:8px;");
    QByteArray bts = rep->readAll();
    QString str(bts);

    QFile config("log_synchronisation.txt");
    config.open(QIODevice::WriteOnly);
    QTextStream stream(&config);

    stream<<str;
    config.close();
    if(!timer->isActive()){
        timer->start();
    }

}

void MainWindow::on_table_inventaire_cellClicked(int row, int column)
{
   this->selected_row_inventaire=row;
}


void MainWindow::on_affichage_m2_clicked()
{
   load_inventaire();
}

void MainWindow::on_affichage_cartons_clicked()
{
    load_inventaire();
}

void MainWindow::on_affichage_pieces_clicked()
{
    load_inventaire();
}

float MainWindow::new_price(QString from, QString to, float price,float qte_m2,float qte_cartons)
{
    if(from==to){
        return price;
    }
    if(from=="Pièce"){
        if(to=="m2"){
            return price*qte_m2;
        }
        if(to=="Carton"){
            return price*qte_cartons;
        }
    }


    if(from=="m2"){
        if(to=="Pièce"){
            return price/qte_m2;
        }
        if(to=="Carton"){
            return  (qte_cartons*price)/qte_m2;
        }
    }

    if(from=="Carton"){
        if(to=="Pièce"){
            return price/qte_cartons;
        }
        if(to=="m2"){
            return (price*qte_m2)/qte_cartons;
        }
    }
}

void MainWindow::synchroniser(QString table)
{
    ui->pushButton_12->setText("Synchronisation encours...");
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_12->setStyleSheet("background-color:gray;color:black;border:none;padding:8px;");
    timer->stop();
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
    QString url="http://127.0.0.1/db/saving.php";
    if(table!=""){
        url+="?table="+table;
    }
    mgr->get(QNetworkRequest(QUrl(url)));
}

void MainWindow::synchroniser_tout()
{
    ui->pushButton_12->setText("Synchronisation encours...");
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_12->setStyleSheet("background-color:gray;color:black;border:none;padding:8px;");
    timer->stop();
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
    QString url="http://127.0.0.1/db/saving.php";

    mgr->get(QNetworkRequest(QUrl(url)));
}
