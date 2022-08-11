#include "bris.h"
#include "ui_bris.h"

Bris::Bris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bris)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);

    ui->table_liste_point_vente->horizontalHeader()->setStretchLastSection(true);
    load_produits();
    load_liste();
}

Bris::~Bris()
{
    delete ui;
}

void Bris::on_pushButton_clicked()
{
   if(ui->produit->currentIndex()==0 || ui->pieces_cassees->text().isEmpty() || ui->lot_obtenu->text().isEmpty()){
       QMessageBox::warning(this,"Erreur","Tous les champs ne sont pas saisis");
       return;
   }
   QString id_produit=ui->produit->currentData().toString();
   QString pieces=ui->pieces_cassees->text();
   QString lot=ui->lot_obtenu->text();


   QSqlQuery qr;
   qr.exec("select * from user");
   QString id_user="";
   if(qr.next()){
       id_user=qr.value(0).toString();
   }
   qr.prepare("insert into bris(produit,pieces_cassees,lots_obtenus,date,user) values(:produit,:pieces_cassees,:lots_obtenus,:date,:user)");
   qr.bindValue(":produit",id_produit);
   qr.bindValue(":pieces_cassees",pieces);
   qr.bindValue(":lots_obtenus",lot);
   qr.bindValue(":date",QDate::currentDate());
   qr.bindValue(":user",id_user);

   if(qr.exec()){
       ui->produit->setCurrentIndex(0);
       ui->pieces_cassees->clear();
       ui->lot_obtenu->clear();
       load_liste();
       QMessageBox::information(this,"Success","Bris bien enregistré");
   }else{
       QMessageBox::warning(this,"Erreur","Une erreur est survenue");
   }
}

void Bris::load_liste()
{
    QSqlQuery qr;
    qr.exec("select count(*) from bris");
    int total=0;
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_point_vente->setRowCount(total);

    int row=0;
    qr.exec("select * from bris");
    while(qr.next()){
        QString id_produit=qr.value("produit").toString();
        QString pieces=qr.value("pieces_cassees").toString();
        QString lots=qr.value("lots_obtenus").toString();
        QString date=qr.value("date").toString();

        ui->table_liste_point_vente->setItem(row,0,new QTableWidgetItem(date));
        ui->table_liste_point_vente->setItem(row,1,new QTableWidgetItem(id_produit));
        ui->table_liste_point_vente->setItem(row,2,new QTableWidgetItem(pieces));
        ui->table_liste_point_vente->setItem(row,3,new QTableWidgetItem(lots));

        row++;
    }
}

void Bris::load_produits()
{
    QSqlQuery qr;
    qr.exec("select * from stock");
    ui->produit->clear();
    ui->produit->addItem("Choisir");
    while(qr.next()){
        ui->produit->addItem(qr.value("nom").toString(),qr.value(0));
    }
}
