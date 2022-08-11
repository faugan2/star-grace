#include "ajoutcarreaux.h"
#include "ui_ajoutcarreaux.h"

AjoutCarreaux::AjoutCarreaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutCarreaux)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);

    can_update=false;
    init();
    load_list();
    load_formats();
    ui->table_liste_point_vente->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->table_liste_point_vente->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
    ui->btn_modifier_stock->setEnabled(false);

     ui->table_liste_point_vente->horizontalHeader()->setStretchLastSection(true);
     can_update=true;

     ui->btn_modifier_stock->hide();
}


AjoutCarreaux::~AjoutCarreaux()
{
    delete ui;
}

void AjoutCarreaux::on_pushButton_clicked()
{
        QString nom=ui->nom->text();
        QString format=ui->format->currentText();
        QString id_format=ui->format->currentData().toString();

        QString prix_par_m2=ui->prix_par_m2->text();


        if(nom.isEmpty() || format.isEmpty() || prix_par_m2.isEmpty()){
            QMessageBox::warning(this,"Erreur","Remplissez tous champs avant de valider");
            return;
        }

        QSqlQuery qr;
        if(id_selected==""){
            qr.prepare("insert into stock (type,nom,format,prix_par_m2,alerte) values(:type,:nom,:format,:prix_par_m2,:alerte)");
            qr.bindValue(":type","1");
            qr.bindValue(":nom",nom.toUpper());
            qr.bindValue(":format",id_format);
            qr.bindValue(":prix_par_m2",prix_par_m2);
            qr.bindValue(":alerte","0");
            if(qr.exec()){
                init();
                load_list();
            }else{
                QMessageBox::warning(this,"Erreur","Une erreur est survenue l'ors de l'insertion");
            }
        }else{
            qr.prepare("update stock set nom=:nom, format=:format,prix_par_m2=:prix_par_m2 where id=:id");
            qr.bindValue(":nom",nom.toUpper());
            qr.bindValue(":format",id_format);
            qr.bindValue(":prix_par_m2",prix_par_m2);
            qr.bindValue(":id",id_selected);
            if(qr.exec()){
                init();
                load_list();
            }else{
                ui->alerte->setText("Une erreur est survenue");
            }
        }
}

void AjoutCarreaux::load_list()
{
    can_update=false;
    QSqlQuery qr;
    int total=0;
    qr.exec("select count(*) from stock where type='1'");
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_point_vente->setRowCount(total);


    qr.exec("select * from stock where type='1'");
    int r=0;
    while(qr.next()){
        QString id=qr.value(0).toString();
        QString nom=qr.value(2).toString();
        QString format=qr.value(3).toString();
        QString prix_par_m2=qr.value(4).toString();
        QString sa=qr.value(5).toString();

        QSqlQuery qr2;
        QString format_nom="-";
        qr2.exec("select * from formats where id='"+format+"'");
        if(qr2.next()){
            format_nom=qr2.value("nom").toString();
        }


        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(nom));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(format_nom));
        ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem(prix_par_m2));
        ui->table_liste_point_vente->setItem(r,3,new QTableWidgetItem(sa));

        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        ui->table_liste_point_vente->item(r,0)->setTextAlignment(Qt::AlignCenter);
        ui->table_liste_point_vente->item(r,1)->setTextAlignment(Qt::AlignCenter);
        ui->table_liste_point_vente->item(r,2)->setTextAlignment(Qt::AlignCenter);
        ui->table_liste_point_vente->item(r,3)->setTextAlignment(Qt::AlignCenter);
        r++;

    }
    can_update=true;
}

void AjoutCarreaux::init()
{
    ui->nom->clear();
    ui->format->setCurrentIndex(0);
    ui->prix_par_m2->clear();

    ui->pushButton->setText("Ajouter");
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
    ui->btn_modifier_stock->setEnabled(false);
}

void AjoutCarreaux::on_search_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
            load_list();
            return;
        }
    QSqlQuery qr;
    qr.exec("select * from stock where nom like '%"+arg1+"%' or format  like '%"+arg1+"%' or prix_par_m2  like '%"+arg1+"%'");

    int r=0;
    //ui->table_liste_point_vente->setRowCount(0);
    while(qr.next()){
        QString id=qr.value(0).toString();
        QString type=qr.value(1).toString();
        if(type=="2"){
            continue;
        }
        QString nom=qr.value(2).toString();
        QString format=qr.value(3).toString();
        QString prix_par_m2=qr.value(4).toString();

        QString format_nom="";
        QSqlQuery qr2;
        qr2.exec("select * from formats where id='"+format+"'");
        if(qr2.next()){
            format_nom=qr2.value("nom").toString();
        }

        ui->table_liste_point_vente->setRowCount(r+1);
        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(nom));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(format_nom));
        ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem(prix_par_m2));
       // ui->table_liste_point_vente->setItem(r,3,new QTableWidgetItem("0"));



        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        r++;
    }
    if(r==0){
        ui->table_liste_point_vente->setRowCount(0);
    }

}

void AjoutCarreaux::on_btn_edit_clicked()
{
    QSqlQuery qr;
    qr.exec("select * from stock where id='"+id_selected+"'");
    if(qr.next()){
        QString nom=qr.value("nom").toString();
        QString format=qr.value("format").toString();
        QString prix_par_m2=qr.value("prix_par_m2").toString();

        QSqlQuery qr2;
        qr2.exec("select * from formats where id='"+format+"'");
        QString format_nom="";
        if(qr2.next()){
            format_nom=qr2.value("nom").toString();
        }

        ui->nom->setText(nom);
        ui->format->setCurrentText(format_nom);
        ui->prix_par_m2->setText(prix_par_m2);
        ui->pushButton->setText("Modifier");
    }
}

void AjoutCarreaux::on_btn_del_clicked()
{
    if(id_selected!=""){
        int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer le format ?");
        if(res==QMessageBox::Yes){
            QSqlQuery qr;
            if(qr.exec("delete from stock where id='"+id_selected+"'")){
                load_list();
                init();
            }else{
                QMessageBox::warning(this,"Erreur","Une erreur est survenue");
            }
        }


    }

}

void AjoutCarreaux::on_table_liste_point_vente_cellClicked(int row, int column)
{
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(true);
    ui->btn_modifier_stock->setEnabled(true);
    id_selected=ui->table_liste_point_vente->item(row,0)->toolTip();
}

void AjoutCarreaux::load_formats()
{
    QSqlQuery qr;
    qr.exec("select * from formats");
    ui->format->addItem("Choisir");
    while(qr.next()){
        ui->format->addItem(qr.value("nom").toString(),qr.value("id"));
    }

}

void AjoutCarreaux::on_btn_modifier_stock_clicked()
{
    modif_stock=new ModifierStock(id_selected,this);
    modif_stock->setModal(true);
    modif_stock->show();
}

void AjoutCarreaux::on_format_currentTextChanged(const QString &arg1)
{

    QSqlQuery qr;
    qr.exec("select * from formats where nom='"+arg1+"'");
    if(qr.next()){
        QString prix=qr.value("prix").toString();
        ui->prix_par_m2->setText(prix);
    }
}

void AjoutCarreaux::on_table_liste_point_vente_cellChanged(int row, int column)
{
    if(column==3 && can_update==true){
        QString sa=ui->table_liste_point_vente->item(row,3)->text();
        QString id_produit=ui->table_liste_point_vente->item(row,0)->toolTip();
        QSqlQuery qr;
        qr.exec("update stock set alerte='"+sa+"' where id='"+id_produit+"'");

        load_list();

    }

}

void AjoutCarreaux::on_table_liste_point_vente_cellEntered(int row, int column)
{
    qDebug()<<"celle entered 2";
}

void AjoutCarreaux::on_table_liste_point_vente_activated(const QModelIndex &index)
{

   qDebug()<<"ok here we go to change the sa";

}

void AjoutCarreaux::on_table_liste_point_vente_entered(const QModelIndex &index)
{
    qDebug()<<"ok entered";
}
