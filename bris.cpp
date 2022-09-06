#include "bris.h"
#include "ui_bris.h"

Bris::Bris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bris)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);
    selected_token="";

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
       qDebug()<<QString::number(ui->produit->currentIndex())<<" and data is "<<ui->produit->currentData().toString();

       QMessageBox::warning(this,"Erreur","Tous les champs ne sont pas saisis");
       return;
   }
   QString id_produit=ui->produit->currentData().toString();
   QString pieces=ui->pieces_cassees->text();
   QString lot=ui->lot_obtenu->text();




   QSqlQuery qr;
   qr.exec("select * from stock where token_id='"+id_produit+"'");
   QString id_format="";
   if(qr.next()){
       id_format=qr.value("format").toString();
   }

   qDebug()<<"the id format is "<<id_format<<"for "<<id_produit;
   qr.exec("select * from formats where token_id='"+id_format+"'");
   float total_cartons=0;
   float total_m2=0;
   float total_pieces=pieces.toFloat();
   QString pu="";

   if(qr.next()){
       float qte_par_m2=qr.value("pieces_par_m2").toFloat();
       float qte_par_cartons=qr.value("pieces_par_carton").toFloat();
        pu=QString::number(qr.value("prix").toFloat());
       //total_cartons
        total_cartons=pieces.toFloat()/qte_par_cartons;
        total_m2=pieces.toFloat()/qte_par_m2;
       //total_m2

       qDebug()<<QString::number(total_cartons)<<QString::number(total_m2);
   }

   //return;
   qr.exec("select * from user");
   QString id_user="";
   QString pv_user="";
   if(qr.next()){
       id_user=qr.value(0).toString();
       pv_user=qr.value(1).toString();
   }
   QString token=QString::number(QDateTime::currentDateTime().toTime_t());
   if(selected_token==""){
       qr.prepare("insert into bris(produit,pieces_cassees,lots_obtenus,date,user,token_id) values(:produit,:pieces_cassees,:lots_obtenus,:date,:user,:token)");
       qr.bindValue(":produit",id_produit);
       qr.bindValue(":pieces_cassees",pieces);
       qr.bindValue(":lots_obtenus",lot);
       qr.bindValue(":date",QDate::currentDate());
       qr.bindValue(":user",id_user);
       qr.bindValue(":token",token);
   }else{
       qr.prepare("update bris set produit=:produit, pieces_cassees=:pieces_cassees, lots_obtenus=:lots_obtenus where token_id=:token_id");
       qr.bindValue(":produit",id_produit);
       qr.bindValue(":pieces_cassees",pieces);
       qr.bindValue(":lots_obtenus",lot);
       qr.bindValue(":token_id",selected_token);
   }

   if(qr.exec()){
    QSqlQuery qr2;
       if(selected_token==""){

           qr2.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token,qte_m2,prix,unite,token_id,total_cartons,total_m2,total_pieces) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token,:qte_m2,:prix,:unite,:token_id,:total_cartons,:total_m2,:total_pieces)");
           qr2.bindValue(":date",QDateTime::currentDateTime());
           qr2.bindValue(":type","3");
           qr2.bindValue(":produit",id_produit);
           qr2.bindValue(":qte","-"+QString::number(total_pieces));
           qr2.bindValue(":user",id_user);
           qr2.bindValue(":point_vente",pv_user);
           qr2.bindValue(":nb_cartons","convertion to be done");
           qr2.bindValue(":token","3");
           qr2.bindValue(":qte_m2","-"+QString::number(total_m2));
           qr2.bindValue(":prix",pu);
           qr2.bindValue(":unite","Pièce");
           qr2.bindValue(":token_id",token);
           qr2.bindValue(":total_cartons","-"+QString::number(total_cartons));
           qr2.bindValue(":total_m2","-"+QString::number(total_m2));
           qr2.bindValue(":total_pieces","-"+pieces);
           if(qr2.exec()){
               qDebug()<<"ok for sending data to mouvements";
           }else{
               qDebug()<<"error sending data to mouvements";
           }
       }else{
           qr2.prepare("update mouvements set produit=:produit, qte=:qte, nb_cartons=:nb_cartons, qte_m2=:qte_m2,prix=:prix, total_cartons=:total_cartons,total_m2=:total_m2,total_pieces=:total_pieces where token_id=:token_id");

           qr2.bindValue(":produit",id_produit);
           qr2.bindValue(":qte","-"+QString::number(total_pieces));
           qr2.bindValue(":nb_cartons","convertion update");
           qr2.bindValue(":qte_m2","-"+QString::number(total_m2));
           qr2.bindValue(":prix",pu);
           qr2.bindValue(":unite","Pièce");
           qr2.bindValue(":token_id",selected_token);
           qr2.bindValue(":total_cartons","-"+QString::number(total_cartons));
           qr2.bindValue(":total_m2","-"+QString::number(total_m2));
           qr2.bindValue(":total_pieces","-"+pieces);
           if(qr2.exec()){
               qDebug()<<"update is made";
           }else{
               qDebug()<<"error making update";
           }

       }
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
        QString token_id=qr.value("token_id").toString();

        QString nom_produit="";
        QSqlQuery qr2;
        qr2.exec("select * from stock where token_id='"+id_produit+"'");
        if(qr2.next()){
            nom_produit=qr2.value("nom").toString();
        }

        ui->table_liste_point_vente->setItem(row,0,new QTableWidgetItem(date));
        ui->table_liste_point_vente->setItem(row,1,new QTableWidgetItem(nom_produit));
        ui->table_liste_point_vente->setItem(row,2,new QTableWidgetItem(pieces));
        ui->table_liste_point_vente->setItem(row,3,new QTableWidgetItem(lots));

        ui->table_liste_point_vente->item(row,0)->setToolTip(token_id);

        ui->table_liste_point_vente->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table_liste_point_vente->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table_liste_point_vente->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->table_liste_point_vente->item(row,3)->setTextAlignment(Qt::AlignCenter);

        row++;
    }
    selected_token="";
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
}

void Bris::load_produits()
{
    if(list_produits.length()>0){
        list_produits.clear();
    }
    QSqlQuery qr;
    qr.exec("select * from stock");
    ui->produit->clear();
    ui->produit->addItem("Choisir");
    while(qr.next()){
        QString nom_produit=qr.value("nom").toString();
        list_produits.append(nom_produit);
        ui->produit->addItem(nom_produit,qr.value("token_id"));
    }
}

void Bris::on_table_liste_point_vente_cellClicked(int row, int column)
{
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(true);
}

void Bris::on_btn_edit_clicked()
{
    int row = ui->table_liste_point_vente->selectedItems().at(0)->row();
    QString token_id=ui->table_liste_point_vente->item(row,0)->toolTip();
    selected_token=token_id;

    QSqlQuery qr;
    qr.exec("select * from bris where token_id='"+token_id+"'");
    if(qr.next()){
        QString id_produit=qr.value("produit").toString();
        QString pieces=qr.value("pieces_cassees").toString();
        QString lots=qr.value("lots_obtenus").toString();

        QString nom_produit="";
        QSqlQuery qr2;
        qr2.exec("select * from stock where token_id='"+id_produit+"' ");
        if(qr2.next()){
            nom_produit=qr2.value("nom").toString();
        }

        ui->pieces_cassees->setText(pieces);
        ui->lot_obtenu->setText(lots);
        ui->produit->setCurrentText(nom_produit);
        int index=list_produits.indexOf(nom_produit);

        ui->produit->setCurrentIndex(index+1);

    }
}

void Bris::on_btn_del_clicked()
{
    int rep=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimé cette ligne ?");
    if(rep==QMessageBox::No){
        return;
    }

    int row=ui->table_liste_point_vente->selectedItems().at(0)->row();
    QString token_id=ui->table_liste_point_vente->item(row,0)->toolTip();
    QSqlQuery qr;
    qr.exec("delete from bris where token_id='"+token_id+"'");
    load_liste();
}
