#include "droits.h"
#include "ui_droits.h"

Droits::Droits(QString id_user,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Droits)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QSqlQuery qr;
    this->id_user=id_user;

    qr.exec("select * from users where id='"+id_user+"'");
    if(qr.next()){
        QString type_user=qr.value("type").toString();
        if(type_user=="Admin"){
            ui->droit_transfert->setChecked(true);
            ui->droit_depenses->setChecked(true);
            ui->droit_bris->setChecked(true);
            ui->droit_retrait->setChecked(true);
            ui->droit_point_vente->setChecked(true);
            ui->droit_utilisateurs->setChecked(true);
            ui->droit_clients->setChecked(true);
            ui->droit_stock->setChecked(true);
            //ui->pushButton->setEnabled(false);
        }else{
            ui->pushButton->setEnabled(true);
            QSqlQuery qr2;
            qr2.exec("select * from droit where user='"+id_user+"'");
            if(qr2.next()){
                QString transfert=qr2.value(2).toString();
                QString depenses=qr2.value(3).toString();
                QString bris=qr2.value(4).toString();
                QString retrait=qr2.value(5).toString();
                QString point_vente=qr2.value(6).toString();
                QString utilisateurs=qr2.value(7).toString();
                QString clients=qr2.value(8).toString();
                QString stock=qr2.value(9).toString();
                QString vente=qr2.value(10).toString();
                QString facture=qr2.value(11).toString();
                QString bon=qr2.value(12).toString();

                if(transfert=="1"){
                    ui->droit_transfert->setChecked(true);
                }
                if(depenses=="1"){
                    ui->droit_depenses->setChecked(true);
                }
                if(bris=="1"){
                    ui->droit_bris->setChecked(true);
                }
                if(retrait=="1"){
                    ui->droit_retrait->setChecked(true);
                }
                if(point_vente=="1"){
                    ui->droit_point_vente->setChecked(true);
                }

                if(utilisateurs=="1"){
                    ui->droit_utilisateurs->setChecked(true);
                }

                if(clients=="1"){
                    ui->droit_clients->setChecked(true);
                }

                if(stock=="1"){
                    ui->droit_stock->setChecked(true);
                }
                if(vente=="1"){
                    ui->droit_vente->setChecked(true);
                }

                if(facture=="1"){
                    ui->droit_print_facture->setChecked(true);
                }
                if(bon=="1"){
                    ui->droit_print_bon->setChecked(true);
                }


            }
        }
    }


}

Droits::~Droits()
{
    delete ui;
}

void Droits::on_pushButton_clicked()
{
    bool d_transfert=ui->droit_transfert->isChecked();
    bool d_depense=ui->droit_depenses->isChecked();
    bool d_bris=ui->droit_bris->isChecked();
    bool d_retrait=ui->droit_retrait->isChecked();
    bool d_pv=ui->droit_point_vente->isChecked();
    bool d_utilisateurs=ui->droit_utilisateurs->isChecked();
    bool d_clients=ui->droit_clients->isChecked();
    bool d_stock=ui->droit_stock->isChecked();
    bool d_vente=ui->droit_vente->isChecked();
    bool facture=ui->droit_print_facture->isChecked();
    bool bon=ui->droit_print_bon->isChecked();

    QString str_trf="0";
    if(d_transfert==true){
        str_trf="1";
    }

    QString str_dep="0";
    if(d_depense==true){
        str_dep="1";
    }

    QString str_bri="0";
    if(d_bris==true){
        str_bri="1";
    }

    QString str_ret="0";
    if(d_retrait==true){
        str_ret="1";
    }

    QString str_pv="0";
    if(d_pv==true){
        str_pv="1";
    }

    QString str_uti="0";
    if(d_utilisateurs==true){
        str_uti="1";
    }

    QString str_cl="0";
    if(d_clients==true){
        str_cl="1";
    }

    QString str_st="0";
    if(d_stock==true){
        str_st="1";
    }

    QString str_vente="0";
    if(d_vente==true){
        str_vente="1";
    }

    QString str_facture="0";
    if(facture==true){
        str_facture="1";
    }

    QString str_bon="0";
    if(bon==true){
        str_bon="1";
    }



    QSqlQuery qr;
    qr.exec("delete from droit where user='"+id_user+"'");
    qr.prepare("insert into droit(user,transfert,depenses,bris,retrait,point_vente,utilisateurs,clients,stock,vente,facture,bon) values(:user,:transfert,:depenses,:bris,:retrait,:point_vente,:utilisateurs,:clients,:stock,:vente,:facture,:bon)");
    qr.bindValue(":user",id_user);
    qr.bindValue(":transfert",str_trf);
    qr.bindValue(":depenses",str_dep);
    qr.bindValue(":bris",str_bri);
    qr.bindValue(":retrait",str_ret);
    qr.bindValue(":point_vente",str_pv);
    qr.bindValue(":utilisateurs",str_uti);
    qr.bindValue(":clients",str_cl);
    qr.bindValue(":stock",str_st);
    qr.bindValue(":vente",str_vente);
    qr.bindValue(":facture",str_facture);
    qr.bindValue(":bon",str_bon);
    if(qr.exec()){
        QMessageBox::information(this,"Success","Droits définis avec success");
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }

}
