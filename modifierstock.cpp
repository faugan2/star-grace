#include "modifierstock.h"
#include "ui_modifierstock.h"

ModifierStock::ModifierStock(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierStock)
{
    ui->setupUi(this);
    id_selected=id;

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    load_magazing();
    ui->ajouter->setChecked(true);

    QSqlQuery qr;
    qr.exec("select * from stock where token_id='"+id_selected+"'");
    if(qr.next()){
        QString nom=qr.value("nom").toString().toUpper();
        QString type=qr.value("type").toString();
        if(type=="1"){
            ui->qte->setPlaceholderText("Nombre de cartons");
        }
        this->setWindowTitle("Modification du stock - "+nom);
    }
}

ModifierStock::~ModifierStock()
{
    delete ui;
}

void ModifierStock::on_pushButton_clicked()
{
    bool ajouter=ui->ajouter->isChecked();
    bool retirer=ui->retirer->isChecked();
    QString magazin=ui->magazin->currentText();
    QString qte=ui->qte->text();
    if(retirer==true){
        qte="-"+qte;
    }

    if(ui->magazin->currentIndex()==0){
        QMessageBox::warning(this,"Erreur","Vous devez choisir un point de vente");
        return;
    }
    if(qte.isEmpty()){
        QMessageBox::warning(this,"Erreur","Vous devez saisir une quantité");
        return;
    }

    QSqlQuery qr;
    qr.exec("select * from stock where token_id='"+id_selected+"'");
    QString produit="";
    if(qr.next()){
        produit=qr.value("nom").toString();
    }
    if(ui->magazin->currentIndex()==1){
        bool error=false;
        for(int i=0; i<points_vente.length(); i++){
            QString pv=points_vente.at(i).toUpper();
            QSqlQuery qr2;
            qr2.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token)");
            qr2.bindValue(":date",QDateTime::currentDateTime());
            qr2.bindValue(":type","1");
            qr2.bindValue(":produit",produit);
            qr2.bindValue(":qte",qte);
            qr2.bindValue(":user","ADMIN");
            qr2.bindValue(":point_vente",pv);
            qr2.bindValue(":nb_cartons",qte);
            qr2.bindValue(":token","");

            if(qr2.exec()){
                //QMessageBox::information(this,"Success","Stock bien mis à jour");
            }else{
                //QMessageBox::warning(this,"Erreur","Une erreur est intervenue");
                error=true;
            }

        }

        if(error==false){
            QMessageBox::information(this,"Success","Stock bien mis à jour");
            ui->qte->clear();
        }

    }else{
        qr.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token)");
        qr.bindValue(":date",QDateTime::currentDateTime());
        qr.bindValue(":type","1");
        qr.bindValue(":produit",produit);
        qr.bindValue(":qte",qte);
        qr.bindValue(":user","ADMIN");
        qr.bindValue(":point_vente",magazin);
        qr.bindValue(":nb_cartons",qte);
        qr.bindValue(":token","");
        if(qr.exec()){
            QMessageBox::information(this,"Success","Stock bien mis à jour");
            ui->qte->clear();
        }else{
            QMessageBox::warning(this,"Erreur","Une erreur est intervenue");
        }
    }



}

void ModifierStock::load_magazing()
{
    ui->magazin->clear();
    ui->magazin->addItem("Choisir un point de vente");
    ui->magazin->addItem("TOUT");
    points_vente.clear();
    QSqlQuery qr;
    qr.exec("select * from points_vente");
    while(qr.next()){
        QString nom=qr.value("adresse").toString();
        ui->magazin->addItem(nom.toUpper());
        points_vente.append(nom.toUpper());
    }
}
