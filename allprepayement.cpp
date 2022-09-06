#include "allprepayement.h"
#include "ui_allprepayement.h"

AllPrePayement::AllPrePayement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllPrePayement)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    load_clients();
    load_liste();
}

AllPrePayement::~AllPrePayement()
{
    delete ui;
}

void AllPrePayement::load_clients()
{
    QSqlQuery qr;
    qr.exec("select * from clients");
    ui->clients->clear();
    ui->clients->addItem("Choisissez un client");
    while(qr.next()){
        QString nom_client=qr.value("nom").toString();

        ui->clients->addItem(nom_client,qr.value(0));
    }
}

void AllPrePayement::load_liste()
{
    QSqlQuery qr;
    qr.exec("select count(*) from prepayements");
    int total=0;
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_pre_payement->setRowCount(total);

    qr.exec("select * from prepayements");
    int row=0;
    while(qr.next()){
        QString id_client=qr.value("client").toString();
        QString montant=qr.value("montant").toString();
        QString date=qr.value("date").toString();

        QString nom_client="";
        QSqlQuery qr2;
        qr2.exec("select * from clients where token_id='"+id_client+"'");
        if(qr2.next()){
            nom_client=qr2.value("nom").toString();
        }
        ui->table_pre_payement->setItem(row,0,new QTableWidgetItem(date));
        ui->table_pre_payement->setItem(row,1,new QTableWidgetItem(nom_client));
        ui->table_pre_payement->setItem(row,2,new QTableWidgetItem(montant));

        ui->table_pre_payement->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table_pre_payement->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table_pre_payement->item(row,2)->setTextAlignment(Qt::AlignCenter);

        row++;
    }

}

void AllPrePayement::on_pushButton_2_clicked()
{
    if(ui->clients->currentIndex()==0 || ui->montant->text().isEmpty() || ui->details->toPlainText().isEmpty()){
        QMessageBox::warning(this,"Erreur","Vous devez saisir tous les champs");
        return;
    }

    QString id_client=ui->clients->currentData().toString();
    QString montant=ui->montant->text();
    QString detail=ui->details->toPlainText();

    QSqlQuery qr;
    QString id_user="";
    qr.exec("select * from user");
    if(qr.next()){
        id_user=qr.value(0).toString();
    }
    QString token_id=QString::number(QDateTime::currentDateTime().toTime_t());
    qr.prepare("insert into prepayements(client,montant,detail,date,user,token_id) values(:client,:montant,:detail,:date,:user,:token_id)");
    qr.bindValue(":client",id_client);
    qr.bindValue(":montant",montant);
    qr.bindValue(":detail",detail);
    qr.bindValue(":date",QDate::currentDate());
    qr.bindValue(":user",id_user);
    qr.bindValue(":token_id",token_id);

    if(qr.exec()){
        ui->clients->setCurrentIndex(0);
        ui->montant->clear();
        ui->details->clear();
        ui->btn_del->setEnabled(false);
        load_liste();
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }

}
