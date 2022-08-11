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
        ui->du->addItem(nom,qr.value(0));
    }
}

void TransfertProduits::load_produits()
{
    QSqlQuery qr;
    qr.exec("select * from stock where type='1'");
    ui->produit->clear();
    ui->produit->addItem("Choisir");
    while(qr.next()){
        QString nom=qr.value("nom").toString();
        ui->produit->addItem(nom,qr.value(0));
    }

}

void TransfertProduits::calculate_remaining_qte()
{
    if(ui->du->currentIndex()==0 || ui->produit->currentIndex()==0){
        ui->qte_en_stock->setText("");
        return;
    }

    QString id_produit=ui->produit->currentData().toString();
    QString id_pv=ui->du->currentData().toString();

    QSqlQuery qr;
    qr.exec("select sum(qte) from mouvements where produit='"+id_produit+"' and point_vente='"+id_pv+"' ");
    float total=0;
    if(qr.next()){
        total=qr.value(0).toFloat();
    }
    ui->qte_en_stock->setText("En stock : "+QString::number(total)+" carton(s)");

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
    qr.exec("select * from points_vente where id<>'"+id_pv+"'");
    while(qr.next()){
        QString nom=qr.value("adresse").toString();
        ui->a->addItem(nom,qr.value(0));
    }
    calculate_remaining_qte();

}

void TransfertProduits::on_produit_currentIndexChanged(int index)
{
    calculate_remaining_qte();
}

void TransfertProduits::on_pushButton_clicked()
{
    if(ui->du->currentIndex()==0 || ui->a->currentIndex()==0 || ui->produit->currentIndex()==0 || ui->qte->text().isEmpty()){
        QMessageBox::warning(this,"Erreur","Certains champs ne sont pas remplis");
        return;
    }

    QString id_pv_du=ui->du->currentData().toString();
    QString id_pv_a=ui->a->currentData().toString();
    QString id_produit=ui->produit->currentData().toString();
    QString qte=ui->qte->text();

    QSqlQuery qr;
    qr.exec("select * from user");
    QString id_user="";
    if(qr.next()){
        id_user=qr.value(0).toString();
    }

    qr.prepare("insert into transfert(du,a,produit,quantite,user,date) values(:du,:a,:produit,:quantite,:user,:date)");
    qr.bindValue(":du",id_pv_du);
    qr.bindValue(":a",id_pv_a);
    qr.bindValue(":produit",id_produit);
    qr.bindValue(":quantite",qte);
    qr.bindValue(":user",id_user);
    qr.bindValue(":date",QDate::currentDate());
    if(qr.exec()){
        QSqlQuery qr2;

        qr2.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token)");
        qr2.bindValue(":date",QDateTime::currentDateTime());
        qr2.bindValue(":type","1");
        qr2.bindValue(":produit",id_produit);
        qr2.bindValue(":qte",qte);
        qr2.bindValue(":user",id_user);
        qr2.bindValue(":point_vente",id_pv_a);
        qr2.bindValue(":nb_cartons",qte);
        qr2.bindValue(":token","2");
        qr2.exec();


        qr2.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token)");
        qr2.bindValue(":date",QDateTime::currentDateTime());
        qr2.bindValue(":type","1");
        qr2.bindValue(":produit",id_produit);
        qr2.bindValue(":qte","-"+qte);
        qr2.bindValue(":user",id_user);
        qr2.bindValue(":point_vente",id_pv_du);
        qr2.bindValue(":nb_cartons","-"+qte);
        qr2.bindValue(":token","2");
        qr2.exec();

        QMessageBox::information(this,"Success","L'opération de transfert s'est bien passé");
        ui->du->setCurrentIndex(0);
        ui->a->setCurrentIndex(0);
        ui->produit->setCurrentIndex(0);
        ui->qte->clear();
        load_liste();
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }

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

        QString nom_produit="";
        QString nom_du="";
        QString nom_a="";

        QSqlQuery qr2;
        qr2.exec("select * from stock where id='"+id_produit+"'");
        if(qr2.next()){
            nom_produit=qr2.value("nom").toString();
        }

        qr2.exec("select * from points_vente where id='"+id_pv_du+"'");
        if(qr2.next()){
            nom_du=qr2.value("adresse").toString();
        }

        qr2.exec("select * from points_vente where id='"+id_pv_a+"'");
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

        row++;
    }
}
