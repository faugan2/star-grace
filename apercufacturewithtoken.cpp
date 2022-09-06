#include "apercufacturewithtoken.h"
#include "ui_apercufacturewithtoken.h"

ApercuFactureWithToken::ApercuFactureWithToken(QString token,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApercuFactureWithToken)
{
    ui->setupUi(this);
    this->setWindowTitle("Aperçu avant impression");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setFixedSize(570,660);
    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);

    QSqlQuery qr;
    QString remise="";
    QString impaye="";
    QString biz="";
    QString banner="0";

    qr.exec("select * from print_config");
    if(qr.next()){
        banner=qr.value("banner").toString();
    }
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
        ui->tableWidget->setMinimumHeight(420);
    }
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
    qr.exec("select * from clients where token_id='"+id_client+"'");
    if(qr.next()){
        nom_client=qr.value("nom").toString().toUpper();
        contact_client=qr.value("contact").toString();
    }
    ui->label_nom_client->setText(nom_client);
    ui->label_contact_client->setText("TEL : "+contact_client);
    ui->client_2->setText(nom_client+" / TEL : "+contact_client);

    qr.exec("select * from mouvements where token='"+token+"'");

    int row=0;
    QString date="";
    float total_ht=0;
    QString vendeur="";
    while(qr.next()){
        QString id_produit=qr.value("produit").toString();
        QString nom_produit="";
        QString nom_format="";
        QString id_format="";
        QString pu=qr.value("prix").toString();
        QString qte=qr.value("qte_m2").toString().replace('-',"");
        QString qte_cartons=qr.value("nb_cartons").toString();
        QString unite=qr.value("unite").toString();

        if(unite!="m2"){
            unite+="(s)";
        }
        date=qr.value("date").toString();
        vendeur=qr.value("user").toString();


        QSqlQuery qr2;
        qr2.exec("select * from stock where token_id='"+id_produit+"'");
        if(qr2.next()){
            nom_produit=qr2.value("nom").toString();
            id_format=qr2.value("format").toString();
        }
        qr2.exec("select * from formats where token_id='"+id_format+"'");
        if(qr2.next()){
            nom_format=qr2.value("nom").toString();
            if(pu.isEmpty()){
                pu=qr2.value("prix").toString();
            }

        }

        if(!biz.isEmpty()){
            QStringList list_biz=biz.split("$");
            for(int i=0; i<list_biz.length(); i++){
                QString line=list_biz.at(i);
                if(line.isEmpty()){
                    continue;
                }
                QStringList biz_parts=line.split("#");
                QString biz_id_produit=biz_parts.at(0);
                QString biz_qte=biz_parts.at(1);
                QString biz_pu=biz_parts.at(2);
                QString biz_total=biz_parts.at(3);
                if(biz_id_produit==id_produit){
                    qte=biz_qte;
                    pu=biz_pu;
                }
            }
        }
        float total=qte.toFloat()*pu.toFloat();

        total_ht+=total;

        ui->tableWidget->setRowCount(row+1);

        ui->tableWidget->setItem(row,0,new QTableWidgetItem(nom_format));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(nom_produit));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(qte));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(unite));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(pu));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(total)));
        //ui->tableWidget->setItem(row,6,new QTableWidgetItem(qte_cartons));

        //ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        //ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,5)->setTextAlignment(Qt::AlignCenter);
       // ui->tableWidget->item(row,6)->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->item(row,0)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,1)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,2)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,3)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,4)->setTextColor(QColor("gray"));
        ui->tableWidget->item(row,5)->setTextColor(QColor("gray"));
        //ui->tableWidget->item(row,6)->setTextColor(QColor("gray"));

        ui->tableWidget->setColumnWidth(2,50);
        ui->tableWidget->setColumnWidth(3,100);
        ui->tableWidget->setColumnWidth(1,120);
        row++;
    }


    ui->date->setText(date.split("T").at(0));
    ui->heure->setText(date.split("T").at(1));
    ui->total_ht->setText(QString::number(total_ht));
    float v_remise=0;
    if(!remise.isEmpty()){
        QString montant_remise=remise.split("#").at(1);
        ui->remise->setText("-"+montant_remise);
        v_remise=montant_remise.toFloat();
    }

    float v_impaye=0;
    if(!impaye.isEmpty()){
        QString montant_impaye=impaye.split("#").at(2);
        ui->tva->setText("-"+montant_impaye);
        v_impaye=montant_impaye.toFloat();
    }
    float total_ttc=total_ht-v_remise-v_impaye;
    ui->total_ttc->setText(QString::number(total_ttc));



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

    qr.exec("select * from users where token_id='"+vendeur+"'");
    if(qr.next()){
        QString id_pv=qr.value("point_vente").toString();
        QSqlQuery qr3;
        qr3.exec("select * from points_vente where token_id='"+id_pv+"'");
        if(qr3.next()){
            QString pv=qr3.value("adresse").toString();
            ui->label_pv->setText(pv);
            ui->label_pv->setWordWrap(true);
        }else{
            ui->label_pv->setText("-");
        }
    }

    qr.exec("select* from ventes_options where token='"+token+"'");
    int max=0;
    if(qr.next()){
        max=qr.value(0).toInt();
    }
    //max++;
    ui->label_token->setText(QString::number(max));

}

ApercuFactureWithToken::~ApercuFactureWithToken()
{
    delete ui;
}
