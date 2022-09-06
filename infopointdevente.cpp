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
        //ui->table_users->setItem(row,3,new QTableWidgetItem(type));

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
        QString id_stock=qr.value("token_id").toString();
        QString nom=qr.value("nom").toString();
        QSqlQuery qr2;
        QString arg="";
        if(ui->unite_carton->isChecked()){
            arg="total_cartons";
        }else if(ui->unite_m2->isChecked()){
            arg="total_m2";
        }else if(ui->unite_piece->isChecked()){
            arg="total_pieces";
        }
        qr2.exec("select sum("+arg+") from mouvements where produit='"+id_stock+"' and point_vente='"+id_selected+"'");
        float qte=0;
        if(qr2.next()){

            qte=qr2.value(0).toFloat();
        }
        ui->table_produits->setItem(row,0,new QTableWidgetItem(nom));
        ui->table_produits->setItem(row,1,new QTableWidgetItem(QString::number(qte)));
        ui->table_produits->item(row,1)->setFlags(Qt::NoItemFlags);
         ui->table_produits->setItem(row,2,new QTableWidgetItem("0"));
        ui->table_produits->item(row,0)->setToolTip(id_stock);

        ui->table_produits->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table_produits->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table_produits->item(row,2)->setTextAlignment(Qt::AlignCenter);
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
    QString unite="Carton";
    if(ui->unite_m2->isChecked()){
        unite="m2";
    }else if(ui->unite_piece->isChecked()){
        unite="Pièce";
    }

    int taille=ui->table_produits->rowCount();
    for(int row=0; row<taille; row++){
       QString id_produit=ui->table_produits->item(row,0)->toolTip();
       QString qte=ui->table_produits->item(row,2)->text();
       if(qte=="0"){
           continue;
       }

       QSqlQuery qr;
       QString type="";
       QString prix="";
       QString id_format="";

       float pieces_par_m2=0;
       float pieces_par_carton=0;

       qr.exec("select * from stock where token_id='"+id_produit+"'");
       if(qr.next()){
           type=qr.value("type").toString();
           prix=qr.value("prix_par_m2").toString();
           id_format=qr.value("format").toString();
       }

       qr.exec("select * from formats where token_id='"+id_format+"'");
       if(qr.next()){
           prix=qr.value("prix").toString();
           pieces_par_m2=qr.value("pieces_par_m2").toFloat();
           pieces_par_carton=qr.value("pieces_par_carton").toFloat();
       }

       float total_cartons=0;
       float total_m2=0;
       float total_pieces=0;

       if(unite=="Carton"){

           total_cartons=qte.toFloat();
           QString tmp_cartons=QString::number(total_cartons);
           QStringList tab=tmp_cartons.split(".");
           if(tab.length()>1){
               total_cartons=tab[0].toFloat();
               float nbp=tab[1].toFloat();
               total_cartons+=nbp/pieces_par_carton;
           }else{
               total_cartons=tab[0].toFloat();
           }
           //return;
           total_pieces=total_cartons*pieces_par_carton;
           total_m2=total_pieces/pieces_par_m2;
           prix=QString::number((prix.toFloat()*pieces_par_carton)/pieces_par_m2);
       }else if(unite=="m2"){
           total_m2=qte.toFloat();
           total_pieces=total_m2*pieces_par_m2;
           total_cartons=total_pieces/pieces_par_carton;
       }else if(unite=="Pièce"){
           total_pieces=qte.toFloat();
           total_cartons=total_pieces/pieces_par_carton;
           total_m2=total_pieces/pieces_par_m2;
           prix=QString::number(prix.toFloat()/pieces_par_m2);
       }

       QString id_user="";
       qr.exec("select * from user");
       if(qr.next()){
           id_user=qr.value(0).toString();
       }

       qr.exec("select * from users where point_vente='"+id_selected+"'");
       if(qr.next()){
           id_user=qr.value("token_id").toString();
       }
       QString token_id=QString::number(QDateTime::currentDateTime().toTime_t());
       qr.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token,qte_m2,prix,unite,token_id,total_cartons,total_m2,total_pieces) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token,:qte_m2,:prix,:unite,:token_id,:total_cartons,:total_m2,:total_pieces)");

       qr.bindValue(":date",QDateTime::currentDateTime());
       qr.bindValue(":type",type);
       qr.bindValue(":produit",id_produit);
       qr.bindValue(":qte",qte);
       qr.bindValue(":user",id_user);
       qr.bindValue(":point_vente",id_selected);
       qr.bindValue(":nb_cartons",qte);
       qr.bindValue(":token","1");
       qr.bindValue(":qte_m2",qte);
       qr.bindValue(":prix",prix);
       qr.bindValue(":unite",unite);

       qr.bindValue(":token_id",token_id);
       qr.bindValue(":total_cartons",QString::number(total_cartons));
       qr.bindValue(":total_m2",QString::number(total_m2));
       qr.bindValue(":total_pieces",QString::number(total_pieces));

       if(qr.exec()){
           ui->table_produits->item(row,2)->setText("0");
       }

       //qDebug()<<"id_produit="<<id_produit;
    }

    load_produits();
    ui->btn_modifier_stock->setEnabled(false);
}

void InfoPointDeVente::on_unite_carton_clicked()
{
    load_produits();
}

void InfoPointDeVente::on_unite_m2_clicked()
{
    load_produits();
}

void InfoPointDeVente::on_unite_piece_clicked()
{
    load_produits();
}
