#include "facture.h"
#include "ui_facture.h"

Facture::Facture(QString token,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Facture)
{
    ui->setupUi(this);
    ui->label_token->setText(token);

    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);


    QSqlQuery qr;
    QString remise="";
    QString impaye="";
    QString biz="";
    qr.exec("select * from ventes_options where token='"+token+"'");
    QString id_client="";
    if(qr.next()){
        id_client=qr.value("client").toString();
        remise=qr.value("remise").toString();
        impaye=qr.value("impaye").toString();
        biz=qr.value("biz").toString();
    }
    QString nom_client="";
    QString contact_client="";
    qr.exec("select * from clients where id='"+id_client+"'");
    if(qr.next()){
        nom_client=qr.value("nom").toString().toUpper();
        contact_client=qr.value("contact").toString();
    }
    ui->label_nom_client->setText(nom_client);
    ui->label_contact_client->setText("TEL : "+contact_client);

    qr.exec("select * from mouvements where token='"+token+"'");

    int row=0;
    QString date="";
    float total_ht=0;
    while(qr.next()){
        QString id_produit=qr.value("produit").toString();
        QString nom_produit="";
        QString nom_format="";
        QString id_format="";
        QString pu="";
        QString qte=qr.value("qte_m2").toString();
        QString qte_cartons=qr.value("nb_cartons").toString();
        date=qr.value("date").toString();

        QSqlQuery qr2;
        qr2.exec("select * from stock where id='"+id_produit+"'");
        if(qr2.next()){
            nom_produit=qr2.value("nom").toString();
            id_format=qr2.value("format").toString();
        }
        qr2.exec("select * from formats where id='"+id_format+"'");
        if(qr2.next()){
            nom_format=qr2.value("nom").toString();
            pu=qr2.value("prix").toString();
        }
        float total=qte.toFloat()*pu.toFloat();
        total_ht+=total;

        ui->tableWidget->setRowCount(row+1);

        ui->tableWidget->setItem(row,0,new QTableWidgetItem(nom_format));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(nom_produit));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(qte));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem("M2"));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(pu));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(total)));
        ui->tableWidget->setItem(row,6,new QTableWidgetItem(qte_cartons));

        //ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        //ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,5)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,6)->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->item(row,0)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,1)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,2)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,3)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,4)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,5)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,6)->setTextColor(QColor("gray"));

        ui->tableWidget->setColumnWidth(2,50);
        ui->tableWidget->setColumnWidth(3,50);
        ui->tableWidget->setColumnWidth(1,180);
        row++;
    }


    ui->date->setText(date.split("T").at(0));
    ui->heure->setText(date.split("T").at(1));
    ui->total_ht->setText(QString::number(total_ht));
    float v_remise=0;
    if(!remise.isEmpty()){
        QString montant_remise=remise.split("#").at(1);
        ui->remise->setText(montant_remise);
        v_remise=montant_remise.toFloat();
    }
    float total_ttc=total_ht-v_remise;
    ui->total_ttc->setText(QString::number(total_ttc));

}

Facture::~Facture()
{
    delete ui;
}
