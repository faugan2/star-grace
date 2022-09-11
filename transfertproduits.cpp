#include "transfertproduits.h"
#include "ui_transfertproduits.h"

TransfertProduits::TransfertProduits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransfertProduits)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);

    ui->table_liste_point_vente->horizontalHeader()->setStretchLastSection(true);

    load_liste();
    load_point_vente();
    load_produits();
    ui->btn_edit->hide();

    //ui->qte->setValidator(new QIntValidator());
   // ui->pieces->setValidator(new QIntValidator());
}

TransfertProduits::~TransfertProduits()
{
    delete ui;
}

void TransfertProduits::load_point_vente()
{
    QSqlQuery qr;
    qr.exec("select * from points_vente");
    ui->du->clear();
    ui->du->addItem("Choisir");
    while(qr.next()){
        QString nom=qr.value("adresse").toString();
        ui->du->addItem(nom,qr.value("token_id"));
    }
}

void TransfertProduits::load_produits()
{
    QSqlQuery qr;
    int total=0;
    qr.exec("select count(*) from stock where type='1'");
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_produits->setRowCount(total);

    qr.exec("select * from stock where type='1'");
    //ui->produit->clear();
    //ui->produit->addItem("Choisir");
    int row=0;
   // ui->table_produits->setColumnWidth(2,40);
    ui->table_produits->setColumnWidth(1,50);
    while(qr.next()){
        QString nom=qr.value("nom").toString();
        QString token_id=qr.value("token_id").toString();
        //ui->produit->addItem(nom,token_id);

        ui->table_produits->setItem(row,0,new QTableWidgetItem(nom));
        ui->table_produits->setItem(row,1,new QTableWidgetItem(""));
        ui->table_produits->setItem(row,2,new QTableWidgetItem(""));

        ui->table_produits->item(row,0)->setToolTip(token_id);




        row++;

    }

}

void TransfertProduits::calculate_remaining_qte()
{
    if(ui->du->currentIndex()==0 ){
        ui->qte_en_stock->setText("");
        return;
    }

   // QString id_produit=ui->produit->currentData().toString();
    QString id_produit="x";
    QString id_pv=ui->du->currentData().toString();

    QSqlQuery qr;
    qr.exec("select sum(total_cartons) from mouvements where produit='"+id_produit+"' and point_vente='"+id_pv+"' ");
    float total=0;
    if(qr.next()){
        total=qr.value(0).toFloat();
    }
    ui->qte_en_stock->setText("En stock : "+QString::number(total)+" carton(s)");

}

void TransfertProduits::init()
{
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
    ui->btn_print->setEnabled(false);
}

void TransfertProduits::on_du_currentIndexChanged(int index)
{
     ui->a->clear();
    if(index==0){
        return;
    }

    ui->a->addItem("Choisir");
    QString id_pv=ui->du->currentData().toString();
    QSqlQuery qr;
    qr.exec("select * from points_vente where token_id<>'"+id_pv+"'");
    while(qr.next()){
        QString nom=qr.value("adresse").toString();
        ui->a->addItem(nom,qr.value("token_id"));
    }
    calculate_remaining_qte();

}

void TransfertProduits::on_produit_currentIndexChanged(int index)
{
    calculate_remaining_qte();
}

void TransfertProduits::on_pushButton_clicked()
{
    if(ui->du->currentIndex()==0 || ui->a->currentIndex()==0){
        QMessageBox::warning(this,"Erreur","Certains champs ne sont pas remplis");
        return;
    }



    QString id_pv_du=ui->du->currentData().toString();
    QString id_pv_a=ui->a->currentData().toString();
   // QString id_produit=ui->produit->currentData().toString();



    int taille=ui->table_produits->rowCount();
    for(int i=0; i<taille; i++){
        QString qte="0";
        QString pieces="0";
        QString id_produit=ui->table_produits->item(i,0)->toolTip();
        QString qte_carton=ui->table_produits->item(i,1)->text();
        QString qte_piece=ui->table_produits->item(i,2)->text();
        if(qte_carton.isEmpty() && qte_piece.isEmpty()){
            continue;
        }

        if(qte_carton==""){
            qte="0";
        }else{
            qte=qte_carton;
        }
        if(qte_piece==""){
            pieces="0";
        }else{
            pieces=qte_piece;
        }

        //############################################

        QSqlQuery qr;
        qr.exec("select * from user");
        QString id_user="";
        if(qr.next()){
            id_user=qr.value(0).toString();
        }

        QString prix="0";

        qr.exec("select * from stock where token_id='"+id_produit+"'");
        QString id_format="";
        if(qr.next()){
            prix=qr.value("prix_par_m2").toString();
            id_format=qr.value("format").toString();
        }

        float total_cartons=0;
        float total_m2=0;
        float total_pieces=0;

        float nb_carton=0;
        float nb_pieces=0;

        if(!qte.isEmpty()){
            nb_carton=qte.toFloat();
        }

        if(!pieces.isEmpty()){
            nb_pieces=pieces.toFloat();
        }

       // total_cartons+=nb_carton;
        total_pieces+=nb_pieces;

        qDebug()<<"select * from format where token_id='"+id_format+"'";

        qr.exec("select * from formats where token_id='"+id_format+"'");


        if(qr.next()){
            prix=qr.value("prix").toString();

            float pieces_par_m2=qr.value("pieces_par_m2").toFloat();
            float pieces_par_carton=qr.value("pieces_par_carton").toFloat();

            total_pieces+=pieces_par_carton*nb_carton;
            total_cartons=total_pieces/pieces_par_carton;
            total_m2=total_pieces/pieces_par_m2;

        }
        //qDebug()<<"nous avons au total"<<QString::number(total_pieces)<<"pieces";

        //return;



        QString token_id=QString::number(QDateTime::currentDateTime().toTime_t()+i);
        QString token_id2=QString::number(QDateTime::currentDateTime().toTime_t()+1+i);
        if(id_selected.isEmpty()){
            int token=QDateTime::currentDateTime().toTime_t();
            qr.prepare("insert into transfert(du,a,produit,quantite,user,date,token,token_id) values(:du,:a,:produit,:quantite,:user,:date,:token,:token_id)");
            qr.bindValue(":du",id_pv_du);
            qr.bindValue(":a",id_pv_a);
            qr.bindValue(":produit",id_produit);
            qr.bindValue(":quantite",QString::number(total_cartons));
            qr.bindValue(":user",id_user);
            qr.bindValue(":date",QDate::currentDate());
            qr.bindValue(":token",QString::number(token));
            qr.bindValue(":token_id",token_id);
            if(qr.exec()){
                QSqlQuery qr2;

                qr2.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token,qte_m2,prix,unite,token_id,total_cartons,total_m2,total_pieces) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token,:qte_m2,:prix,:unite,:token_id,:total_cartons,:total_m2,:total_pieces)");
                qr2.bindValue(":date",QDateTime::currentDateTime());
                qr2.bindValue(":type","1");
                qr2.bindValue(":produit",id_produit);
                qr2.bindValue(":qte",QString::number(total_cartons));
                qr2.bindValue(":user",id_user);
                qr2.bindValue(":point_vente",id_pv_a);
                qr2.bindValue(":nb_cartons",QString::number(token));
                qr2.bindValue(":token","4");
                qr2.bindValue(":qte_m2",QString::number(total_cartons));
                qr2.bindValue(":prix",prix);
                qr2.bindValue(":unite","Carton");
                qr2.bindValue(":token_id",token_id);
                qr2.bindValue(":total_cartons",QString::number(total_cartons));
                qr2.bindValue(":total_m2",QString::number(total_m2));
                qr2.bindValue(":total_pieces",QString::number(total_pieces));
                qr2.exec();


                qr2.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token,qte_m2,prix,unite,token_id,total_cartons,total_m2,total_pieces) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token,:qte_m2,:prix,:unite,:token_id,:total_cartons,:total_m2,:total_pieces)");
                qr2.bindValue(":date",QDateTime::currentDateTime());
                qr2.bindValue(":type","1");
                qr2.bindValue(":produit",id_produit);
                qr2.bindValue(":qte","-"+QString::number(total_cartons));
                qr2.bindValue(":user",id_user);
                qr2.bindValue(":point_vente",id_pv_du);
                qr2.bindValue(":nb_cartons",QString::number(token));
                qr2.bindValue(":token","4");


                if(total_cartons>0){
                    qr2.bindValue(":qte_m2","-"+QString::number(total_cartons));
                }else{
                    qr2.bindValue(":qte_m2",QString::number(total_cartons*-1));
                }

                qr2.bindValue(":prix",prix);
                qr2.bindValue(":unite","Carton");
                qr2.bindValue(":token_id",token_id2);
                if(total_cartons>0){
                    qr2.bindValue(":total_cartons","-"+QString::number(total_cartons));
                }else{
                    qr2.bindValue(":total_cartons",QString::number(total_cartons*-1));
                }

                if(total_m2>0){
                    qr2.bindValue(":total_m2",QString::number(total_m2));
                }else{
                    qr2.bindValue(":total_m2",QString::number(total_m2*-1));
                }

                if(total_pieces>0){
                    qr2.bindValue(":total_pieces","-"+QString::number(total_pieces));
                }else{
                    qr2.bindValue(":total_pieces",QString::number(total_pieces*-1));
                }




               /*qr2.bindValue(":qte_m2","-"+QString::number(total_cartons));
                qr2.bindValue(":prix",prix);
                qr2.bindValue(":unite","Carton");
                qr2.bindValue(":token_id",token_id2);
                qr2.bindValue(":total_cartons","-"+QString::number(total_cartons));
                qr2.bindValue(":total_m2","-"+QString::number(total_m2));
                qr2.bindValue(":total_pieces","-"+QString::number(total_pieces));*/
                qr2.exec();

                //QMessageBox::information(this,"Success","L'opération de transfert s'est bien passé");



            }else{
                //QMessageBox::warning(this,"Erreur","Une erreur est survenue");
            }
        }else{
            qr.exec("select * from transfert where token_id='"+id_selected+"'");
            QString token="";
            if(qr.next()){
                token=qr.value("token").toString();
            }

        }


        //###########################################

    }
    ui->du->setCurrentIndex(0);
    ui->a->setCurrentIndex(0);
    /*ui->produit->setCurrentIndex(0);
    ui->qte->clear();
    ui->pieces->clear();*/
     load_liste();





}

void TransfertProduits::load_liste()
{
    QSqlQuery qr;
    qr.exec("select count(*) from transfert");
    int total=0;
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_point_vente->setRowCount(total);

    qr.exec("select * from transfert");
    int row=0;
    while(qr.next()){
        QString date=qr.value("date").toString();
        QString id_produit=qr.value("produit").toString();
        QString qte=qr.value("quantite").toString();
        QString id_pv_du=qr.value("du").toString();
        QString id_pv_a=qr.value("a").toString();
        QString id=qr.value("token_id").toString();

        QString nom_produit="";
        QString nom_du="";
        QString nom_a="";

        QSqlQuery qr2;
        qr2.exec("select * from stock where token_id='"+id_produit+"'");
        if(qr2.next()){
            nom_produit=qr2.value("nom").toString();
        }

        qr2.exec("select * from points_vente where token_id='"+id_pv_du+"'");
        if(qr2.next()){
            nom_du=qr2.value("adresse").toString();
        }

        qr2.exec("select * from points_vente where token_id='"+id_pv_a+"'");
        if(qr2.next()){
            nom_a=qr2.value("adresse").toString();
        }
        ui->table_liste_point_vente->setItem(row,0,new QTableWidgetItem(date));
        ui->table_liste_point_vente->setItem(row,1,new QTableWidgetItem(nom_produit));
        ui->table_liste_point_vente->setItem(row,2,new QTableWidgetItem(qte));
        ui->table_liste_point_vente->setItem(row,3,new QTableWidgetItem(nom_du));
        ui->table_liste_point_vente->setItem(row,4,new QTableWidgetItem(nom_a));

        ui->table_liste_point_vente->item(row,3)->setToolTip(nom_du);
        ui->table_liste_point_vente->item(row,4)->setToolTip(nom_a);
        ui->table_liste_point_vente->item(row,0)->setToolTip(id);
        ui->table_liste_point_vente->item(row,1)->setToolTip(nom_produit);
        ui->table_liste_point_vente->item(row,2)->setToolTip(qte);

        for(int c=0; c<5; c++){

            ui->table_liste_point_vente->item(row,c)->setTextAlignment(Qt::AlignCenter);
        }

        row++;
    }
}

void TransfertProduits::on_table_liste_point_vente_cellClicked(int row, int column)
{
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(true);
    ui->btn_print->setEnabled(true);
}

void TransfertProduits::on_btn_del_clicked()
{
    int row=ui->table_liste_point_vente->selectedItems().at(0)->row();
    QString id=ui->table_liste_point_vente->item(row,0)->toolTip();
    id_selected=id;
    QSqlQuery qr;
    int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimé ce transfert");
    if(res==QMessageBox::Yes){
        qr.exec("delete from transfert where token_id='"+id+"'");
        QString token_id1=id;
        QString token_id2=QString::number(id.toUInt()+1);
        qr.exec("delete from mouvements where token_id='"+token_id1+"' or token_id='"+token_id2+"'");

        load_liste();
        init();
        id_selected="";
    }
}

void TransfertProduits::on_btn_edit_clicked()
{
    int row=ui->table_liste_point_vente->selectedItems().at(0)->row();
    QString id=ui->table_liste_point_vente->item(row,0)->toolTip();
    id_selected=id;

    QString du=ui->table_liste_point_vente->item(row,3)->toolTip();
    QString a=ui->table_liste_point_vente->item(row,4)->toolTip();
    QString produit=ui->table_liste_point_vente->item(row,1)->toolTip();
    QString qte=ui->table_liste_point_vente->item(row,2)->toolTip();
    ui->du->setCurrentText(du);
    ui->a->setCurrentText(a);
   // ui->produit->setCurrentText(produit);
    //ui->qte->setText(qte);
    /*QSqlQuery qr;
    qr.exec("select * from transfert where id='"+id+"'");
    if(qr.next()){
        QString du=qr.value("du").toString();
        QString a=qr.value("a").toString();
        QString id_produit=qr.value("produit").toString();
        QString qte=qr.value("qte").toString();


    }*/
}

void TransfertProduits::on_btn_print_clicked()
{
    QStringList ids;
    QList<QTableWidgetItem *> selections=ui->table_liste_point_vente->selectedItems();
    for(int i=0; i<selections.length(); i++){
        int row=selections.at(i)->row();
        QString id=ui->table_liste_point_vente->item(row,0)->toolTip();
        if(!ids.contains(id)){
            ids.append(id);
        }

    }

    QSqlQuery qr;
    qr.exec("delete from ordres");
    for(int x=0; x<ids.length(); x++){
        qDebug()<<"x="<<ids.at(x);
        QSqlQuery qr2;
        qr2.exec("insert into ordres(id_transfert) values('"+ids.at(x)+"')");
    }

    //int row=0;




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
    print_transfert=new PrintTransferts(this);
    print_transfert->setFixedWidth(printer.pageRect().width());
    QPainter painter;
    painter.begin(&printer);
    double xscale = printer.pageRect().width()/double(print_transfert->width());
    double yscale = printer.pageRect().height()/double(print_transfert->height());
    double scale = qMin(xscale, yscale);


    print_transfert->render(&painter);

    qr.exec("delete from ordres");

}
