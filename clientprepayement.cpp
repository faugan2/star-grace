#include "clientprepayement.h"
#include "ui_clientprepayement.h"

ClientPrePayement::ClientPrePayement(QString id_client,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientPrePayement)
{
    ui->setupUi(this);
    this->id=id_client;
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QSqlQuery qr;
    qr.exec("select * from prepayements where client='"+id_client+"'");

    QString nom_client="";
    QString contact_client="";
    QString date="";
    QString montant="";
    QString detail="";
    QString user="";
    int row=0;
    while(qr.next()){
        id_client=qr.value("client").toString();
        montant=qr.value("montant").toString();
        detail=qr.value("detail").toString();
        date=qr.value("date").toString();
        user=qr.value("user").toString();

        ui->table->setRowCount(row+1);
        ui->table->setItem(row,0,new QTableWidgetItem(date));
        ui->table->setItem(row,1,new QTableWidgetItem(montant));
        ui->table->setItem(row,2,new QTableWidgetItem(detail));

        ui->table->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,1)->setTextAlignment(Qt::AlignCenter);


        QSqlQuery qr2;
        qr2.exec("select * from users where id='"+user+"'");
        if(qr2.next()){
             ui->table->item(row,0)->setToolTip(qr2.value("nom").toString());
        }

        row++;



    }

    qr.exec("select sum(montant) from prepayements where client='"+id_client+"'");
    if(qr.next()){
        montant=qr.value(0).toString();
    }

    qr.exec("select * from clients where token_id='"+id_client+"'");
    if(qr.next()){
        nom_client=qr.value("nom").toString();
        contact_client=qr.value("contact").toString();
    }

    ui->nom->setText(nom_client.toUpper());
    ui->contact->setText(contact_client);
    ui->montant->setText(montant+" F CFA");


}

ClientPrePayement::~ClientPrePayement()
{
    delete ui;
}

void ClientPrePayement::on_pushButton_clicked()
{
    QSqlQuery qr;
    int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer ?");
    if(res==QMessageBox::Yes){
        qr.exec("delete from prepayements where client='"+id+"'");
        this->close();
    }

}
