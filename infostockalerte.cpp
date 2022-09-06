#include "infostockalerte.h"
#include "ui_infostockalerte.h"

InfoStockAlerte::InfoStockAlerte(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoStockAlerte)
{
    ui->setupUi(this);
    QStringList l=id.split("#");
    this->id_produit=l.at(0);
    this->id_pv=l.at(1);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QSqlQuery qr;
    QString nom_pv="";
    qr.exec("select * from points_vente where token_id='"+id_pv+"'");
    if(qr.next()){
        nom_pv=qr.value("adresse").toString();
    }
    ui->point_vente->setText(nom_pv);
    qr.exec("select * from stock where token_id='"+id_produit+"'");
    if(qr.next()){
        ui->produit->setText(qr.value("nom").toString());
        id_format=qr.value("format").toString();
    }
    ui->qte->setValidator(new QIntValidator());
}

InfoStockAlerte::~InfoStockAlerte()
{
    delete ui;
}

void InfoStockAlerte::on_pushButton_clicked()
{
    QSqlQuery qr;
    QString qte=ui->qte->text();
    if(qte.isEmpty()){
        QMessageBox::warning(this,"Erreur","Renseignez la quantité");
        return;
    }

    bool unite_m2=ui->unite_m2->isChecked();
    bool unite_carton=ui->unite_carton->isChecked();
    bool unite_piece=ui->unite_piece->isChecked();


    float pieces_par_m2=0;
    float pieces_par_carton=0;
    float prix=0;
    float total_cartons=0;
    float total_m2=0;
    float total_pieces=0;

    qr.exec("select * from formats where token_id='"+id_format+"'");
    if(qr.next()){
        pieces_par_carton=qr.value("pieces_par_carton").toFloat();
        pieces_par_m2=qr.value("pieces_par_m2").toFloat();
        prix=qr.value("prix").toFloat();
    }

    QString unite="m2";
    if(unite_carton==true){
        unite="Carton";
        total_cartons=qte.toFloat();
        total_pieces=total_cartons*pieces_par_carton;
        total_m2=total_pieces/pieces_par_m2;
        prix=(prix*total_cartons)/pieces_par_m2;
    }else if(unite_piece==true){
        unite="Pièce";
        total_pieces=qte.toFloat();
        total_m2=total_pieces/pieces_par_m2;
        total_cartons=total_pieces/pieces_par_carton;
        prix=prix/pieces_par_m2;
    }else if(unite_m2==true){
        unite="m2";
        total_m2=qte.toFloat();
        total_pieces=total_m2*pieces_par_m2;
        total_cartons=total_pieces/pieces_par_carton;
    }

    QString id_user="";
    qr.exec("select * from user");
    if(qr.next()){
        id_user=qr.value(0).toString();
    }

    QString token_id=QString::number(QDateTime::currentDateTime().toTime_t());
    qr.prepare("insert into mouvements(date,type,produit,qte,user,point_vente,nb_cartons,token,qte_m2,prix,unite,token_id,total_cartons,total_m2,total_pieces) values(:date,:type,:produit,:qte,:user,:point_vente,:nb_cartons,:token,:qte_m2,:prix,:unite,:token_id,:total_cartons,:total_m2,:total_pieces)");
    qr.bindValue(":date",QDateTime::currentDateTime());
    qr.bindValue(":type","1");
    qr.bindValue(":produit",id_produit);
    qr.bindValue(":qte",qte);
    qr.bindValue(":user",id_user);
    qr.bindValue(":point_vente",id_pv);
    qr.bindValue(":nb_cartons",qte);
    qr.bindValue(":token","1");
    qr.bindValue(":qte_m2",qte);

    qr.bindValue(":prix",QString::number(prix));
    qr.bindValue(":unite",unite);
    qr.bindValue(":token_id",token_id);
    qr.bindValue(":total_cartons",QString::number(total_cartons));
    qr.bindValue(":total_m2",QString::number(total_m2));
    qr.bindValue(":total_pieces",QString::number(total_pieces));

    if(qr.exec()){
        QMessageBox::information(this,"Success","Le stock est bien mise à jour pour le point de vente");
        this->close();
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }




}
