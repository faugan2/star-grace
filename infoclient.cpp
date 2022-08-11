#include "infoclient.h"
#include "ui_infoclient.h"

InfoClient::InfoClient(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoClient)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    this->id_client=id;
    QSqlQuery qr;
    qr.exec("select * from clients where id='"+id+"'");
    if(qr.next()){
        QString nom=qr.value("nom").toString().toUpper();
        QString contact=qr.value("contact").toString();

        ui->nom->setText(nom);
        ui->contact->setText("Tel : "+contact);
    }
    ui->contact->setStyleSheet("font-size:18px");
    ui->nom->setStyleSheet("font-size:18px");

    qr.exec("select * from token");
    token="";
    if(qr.next()){
        token=qr.value("token").toString();
        ui->num_facture->setText(token);
    }

    if(token.isEmpty()){
        ui->groupBox->hide();
        return;
    }

    qr.exec("select * from ventes_options where token='"+token+"'");
    if(qr.next()){
        QString remise=qr.value("remise").toString();
        QString impaye=qr.value("impaye").toString();
        QString montant="";
        QString mt_impaye="";
        QString reste="";
        QString mt_remise="";

        if(!impaye.isEmpty()){
            QStringList parts=impaye.split("#");
            montant=parts.at(0);
            mt_impaye=parts.at(1);
            reste=parts.at(2);
        }
        if(!remise.isEmpty()){
            mt_remise=remise.split("#").at(1);
        }

        float mt_impayer=montant.toFloat();
        if(!mt_remise.isEmpty()){
            mt_impayer-=mt_remise.toFloat();
        }
        if(!reste.isEmpty()){
            mt_impayer-=reste.toFloat();
        }

        ui->montant->setText(montant);
        ui->remise->setText("-"+mt_remise);
        ui->montant_paye->setText("-"+QString::number(mt_impayer));
        ui->reste->setText(reste);

        ui->reste->setStyleSheet("font-weight:bold; border-top:1px solid gray");
    }

}

InfoClient::~InfoClient()
{
    delete ui;
}



void InfoClient::on_pushButton_clicked()
{
    if(token.isEmpty()){
        return;
    }
    QSqlQuery qr;
    int rep=QMessageBox::question(this,"Confirmation","Voulez-vous soldé cette vente ?");
    if(rep==QMessageBox::Yes){
        qr.exec("update ventes_options set impaye='' where token='"+token+"'");
        this->close();
    }

}
