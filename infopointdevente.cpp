#include "infopointdevente.h"
#include "ui_infopointdevente.h"

InfoPointDeVente::InfoPointDeVente(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoPointDeVente)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedSize(750,400);
    this->id_selected=id;

    QSqlQuery qr;
    qr.exec("select * from points_vente where id='"+id+"'");
    if(qr.next()){
        QString nom=qr.value("adresse").toString();
        point_vente=nom;
        //this->setWindowTitle(nom);
        ui->label_adresse->setText(nom);
        ui->label_responsable->setText(qr.value("responsable").toString());
        ui->label_contact->setText(qr.value("contact").toString());
    }

    load_liste_users();
    load_produits();

    ui->table_produits->horizontalHeader()->setStretchLastSection(true);

    ui->table_produits->setColumnWidth(0,120);
}

InfoPointDeVente::~InfoPointDeVente()
{
    delete ui;
}

void InfoPointDeVente::load_liste_users()
{
    QSqlQuery qr;
    //qDebug()<<"select * from users where point_vente='"+point_vente+"'";
    qr.exec("select count(*) from users where point_vente='"+id_selected+"'");
    int total=0;
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_users->setRowCount(total);
    if(total==0){
        return;
    }

    qr.exec("select * from users where point_vente='"+id_selected+"'");
    int row=0;
    while(qr.next()){
        QString id_user=qr.value(0).toString();
        QString nom=qr.value(1).toString();
        QString login=qr.value("login").toString();
        QString password=qr.value("password").toString();
        QString type=qr.value("type").toString();

        ui->table_users->setItem(row,0,new QTableWidgetItem(nom));
        ui->table_users->setItem(row,1,new QTableWidgetItem(login));
        ui->table_users->setItem(row,2,new QTableWidgetItem(password));
        ui->table_users->setItem(row,3,new QTableWidgetItem(type));

        row++;

    }




}

void InfoPointDeVente::load_produits()
{
    QSqlQuery qr;
    int total=0;
    qr.exec("select count(*) from stock");
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_produits->setRowCount(total);

    qr.exec("select * from stock");
    int row=0;
    while(qr.next()){
        QString id_stock=qr.value(0).toString();
        QString nom=qr.value("nom").toString();
        QSqlQuery qr2;
        qr2.exec("select sum(qte) from mouvements where produit='"+id_stock+"' and point_vente='"+id_selected+"'");
        float qte=0;
        if(qr2.next()){
            qte=qr2.value(0).toFloat();
        }
        ui->table_produits->setItem(row,0,new QTableWidgetItem(nom));
        ui->table_produits->setItem(row,1,new QTableWidgetItem(QString::number(qte)));
        ui->table_produits->item(row,1)->setFlags(Qt::NoItemFlags);
         ui->table_produits->setItem(row,2,new QTableWidgetItem("0"));
        ui->table_produits->item(row,0)->setToolTip(id_stock);
        row++;
    }

}




void InfoPointDeVente::on_table_produits_cellClicked(int row, int column)
{
    int taille=ui->table_produits->rowCount();
    bool can_active_btn=false;
    for(int i=0; i<taille; i++){
        float v=ui->table_produits->item(i,2)->text().toFloat();
        if(v!=0){
            can_active_btn=true;
        }
    }
    ui->btn_modifier_stock->setEnabled(can_active_btn);
}

void InfoPointDeVente::on_table_produits_cellActivated(int row, int column)
{
    on_table_produits_cellClicked(row,column);

}

void InfoPointDeVente::on_table_produits_cellChanged(int row, int column)
{
   // on_table_produits_cellClicked(row,column);
}

void InfoPointDeVente::on_btn_modifier_stock_clicked()
{
    int taille=ui->table_produits->rowCount();
    for(int row=0; row<taille; row++){
       QString id_produit=ui->table_produits->item(row,0)->toolTip();
       QString qte=ui->table_produits->item(row,2)->text();
       if(qte=="0"){
           continue;
       }

       QSqlQuery qr;
       QString type="";
       qr.exec("select * from stock where id='"+id_produit+"'");
       if(qr.next()){
           type=qr.value("type").toString();
       }
       QString id_user="";
       qr.exec("select * from user");
       if(qr.next()){
           id_user=qr.value(0).toString();
       }
       qr.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token)");
       qr.bindValue(":date",QDateTime::currentDateTime());
       qr.bindValue(":type",type);
       qr.bindValue(":produit",id_produit);
       qr.bindValue(":qte",qte);
       qr.bindValue(":user",id_user);
       qr.bindValue(":point_vente",id_selected);
       qr.bindValue(":nb_cartons",qte);
       qr.bindValue(":token","1");

       if(qr.exec()){
           ui->table_produits->item(row,2)->setText("0");
       }

       //qDebug()<<"id_produit="<<id_produit;
    }

    load_produits();
    ui->btn_modifier_stock->setEnabled(false);
}
