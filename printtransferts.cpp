#include "printtransferts.h"
#include "ui_printtransferts.h"

PrintTransferts::PrintTransferts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintTransferts)
{
    ui->setupUi(this);

    QSqlQuery qr;
    QString banner="";
    qr.exec("select * from print_config");
    if(qr.next()){
        banner=qr.value("banner").toString();
    }
    ui->groupBox->hide();
    if(banner=="1"){
        QPixmap logo("./banner.jpg");
        QPixmap newPixmap = logo.scaled(QSize(this->width()-20,300),  Qt::KeepAspectRatio);
        ui->banner->setPixmap(newPixmap);
        ui->banner->setScaledContents(true);
        ui->banner->show();
        ui->text_header->hide();
        ui->groupe_client2->show();
    }else{
        ui->banner->hide();
        ui->text_header->show();
        ui->groupe_client2->hide();
        ui->tableWidget->setMinimumHeight(440);
    }
    ui->groupe_client2->hide();

    qr.exec("select * from entete");
    if(qr.next()){
        QString ets=qr.value("ets").toString();
        QString titre1=qr.value("titre1").toString();
        QString titre2=qr.value("titre2").toString();
        QString titre3=qr.value("titre3").toString();
        QString titre4=qr.value("titre4").toString();
        QString titre5=qr.value("titre5").toString();

        ui->label_header1->setText(ets);
        ui->label_header_2->setText(titre1);
        ui->label_header_3->setText(titre2);
        ui->label_header_4->setText(titre3);
        ui->label_header_5->setText(titre4);
        ui->label_header_6->setText(titre5);
    }

    qr.exec("select * from ordres");
    int row=0;
    while(qr.next()){
        QString id_order=qr.value("id_transfert").toString();
        QSqlQuery qr2;
        qr2.exec("select * from transfert where id='"+id_order+"'");
        QString du="";
        QString a="";
        QString produit="";
        QString qte="";

        if(qr2.next()){
            QString id_du=qr2.value("du").toString();
            QString id_a=qr2.value("a").toString();
            QString id_produit=qr2.value("produit").toString();
            qte=qr2.value("quantite").toString();

            QSqlQuery qr3;
            qr3.exec("select * from stock where id='"+id_produit+"'");
            if(qr3.next()){
                produit=qr3.value("nom").toString();
            }

            qr3.exec("select * from points_vente where id='"+id_du+"'");
            if(qr3.next()){
                du=qr3.value("adresse").toString();
            }

            qr3.exec("select * from points_vente where id='"+id_a+"'");
            if(qr3.next()){
                a=qr3.value("adresse").toString();
            }

            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(produit));
             ui->tableWidget->setItem(row,1,new QTableWidgetItem(qte));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(du.toLower()));
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(a.toLower()));


            ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setColumnWidth(2,180);
            ui->tableWidget->setColumnWidth(3,180);

             ui->tableWidget->resizeRowToContents(row);

            row++;
        }
    }

    ui->tableWidget->setWordWrap(true);

}

PrintTransferts::~PrintTransferts()
{
    delete ui;
}
