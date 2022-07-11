#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QToolBar * toolbar;
    toolbar=addToolBar("File");

    toolbar->addAction(ui->actionParametres);
    toolbar->addAction(ui->actionDeconnexion);
    toolbar->addAction(ui->actionFermer);
    toolbar->addSeparator();

    toolbar->addAction(ui->actionListe_des_points_de_vente);
    //toolbar->addAction(ui->actionAjouter_un_point_de_vent);
    toolbar->addSeparator();

    toolbar->addAction(ui->actionCarreaux);
    toolbar->addAction(ui->actionAutres_produits);
    toolbar->addSeparator();

    toolbar->addAction(ui->actionSynchroniser_les_donn_es);
    toolbar->addAction(ui->actionSauvegarder_la_base_de_donn_es);
    toolbar->addAction(ui->actionRestaurer_la_base_de_donn_es);


    QStringList data;
    data<<"point A"<<"point B"<<"Point C"<<"Point D"<<"H";
    QStringList adresses;
    adresses<<"IPG Adidogomé"<<"CEG Avedji"<<"Tokoin Séminaire"<<"Agoè Centre"<<"Awatmé Plateau";

    QStringList responsables;
    responsables<<"ALI Ben"<<"Jérémie Abalo"<<"Amouzou Jean"<<"Emmanuel Eklu"<<"Apeto Eric";

    QStringList contacts;
    contacts<<"+228 90 25 12 45"<<"+228 96 12 47 56"<<"+228 97 58 63 12"<<"+228 93 56 78 95"<<"+228 97 45 85 74";

    qreal size=data.length()/2.0;
    double nb_rows=qCeil(size);
    int index=0;

    for(int r=0; r<nb_rows; r++){
        for(int c=0; c<2; c++){
            if(data.length()==index){
                continue;
            }


            QGroupBox *a_point_vente=new QGroupBox();
            a_point_vente->setMinimumSize(50,70);

            QVBoxLayout *layout=new QVBoxLayout();

            QLabel *adresse=new QLabel(adresses.at(index));
            adresse->setStyleSheet("color:black; font-weight:bold;font-size:12px");
            adresse->setWordWrap(false);

            QLabel *responsable=new QLabel(responsables.at(index));
            QLabel *contact=new QLabel(contacts.at(index));


            layout->addWidget(adresse);
            layout->addWidget(responsable);
            layout->addWidget(contact);

            a_point_vente->setLayout(layout);



            ui->grid_point_de_vente->addWidget(a_point_vente,r,c);
            ui->grid_point_de_vente->setRowStretch(r,1);
            ui->grid_point_de_vente->setMargin(10);
            index++;
        }

    }

    QStringList autres_services;
    autres_services<<"Transfert de produits"<<"Dépenses"<<"Bris de carreaux"<<"Retrait du DG";

    QStringList icons;
    icons<<"swap-horizontal-outline.svg"<<"logo-euro.svg"<<"qr-code-outline.svg"<<"warning-outline.svg";

    qreal size2=autres_services.length()/2.0;
    double nb_rows2=qCeil(size2);
    int index2=0;

    for(int r=0; r<nb_rows2; r++){
        for(int c=0; c<2; c++){
            if(autres_services.length()==index2){
                continue;
            }

            QGroupBox *a_point_vente=new QGroupBox();
            a_point_vente->setMinimumSize(50,70);

            QVBoxLayout *layout=new QVBoxLayout();

            QLabel *titre_service=new QLabel(autres_services.at(index2));
            titre_service->setAlignment(Qt::AlignCenter);

            QLabel *icon=new QLabel();
            icon->setAlignment(Qt::AlignCenter);
            QPixmap watermark(":/img/images/"+icons.at(index2));
            QPixmap newPixmap = watermark.scaled(QSize(40,40),  Qt::KeepAspectRatio);
            icon->setPixmap(newPixmap);

            titre_service->setStyleSheet("color:black;font-size:10px;text-align:center");
            titre_service->setWordWrap(true);

            layout->addWidget(icon);
            layout->addWidget(titre_service);

            a_point_vente->setLayout(layout);



            ui->grid_autres_services->addWidget(a_point_vente,r,c);
            ui->grid_autres_services->setRowStretch(r,1);
            ui->grid_autres_services->setMargin(10);

            index2++;
        }
    }

    ui->inventaire_point_vente->addItem("Tous");
    for(int i=0; i<adresses.length(); i++){
        ui->inventaire_point_vente->addItem(adresses.at(i));
    }

    ui->inventaire_utilisateurs->addItem("Tous");
   /* ui->table_inventaire->setColumnWidth(2,70);
    ui->table_inventaire->setColumnWidth(3,50);
    ui->table_inventaire->setColumnWidth(4,50);
    ui->table_inventaire->setColumnWidth(5,70);*/

    ui->table_inventaire->setRowCount(20);
    ui->table_inventaire->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    for(int i=0; i<20; i++){
        int qte=qrand();
        int pu=i+4;
        ui->table_inventaire->setItem(i,0,new QTableWidgetItem(QDate::currentDate().toString("dd MM yyyy")));
        ui->table_inventaire->setItem(i,1,new QTableWidgetItem("Carreaux 20x30"));
        ui->table_inventaire->setItem(i,2,new QTableWidgetItem("Stock initial"));
        ui->table_inventaire->setItem(i,3,new QTableWidgetItem(QString::number(pu)));
        ui->table_inventaire->setItem(i,4,new QTableWidgetItem(QString::number(qte)));
        ui->table_inventaire->setItem(i,5,new QTableWidgetItem(QString::number(qte*pu)));

    }






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ajout_point_vente=new AjouterPointDeVente(this);
    ajout_point_vente->setModal(true);
    ajout_point_vente->show();
}

void MainWindow::on_actionFermer_triggered()
{
    this->close();
}

void MainWindow::on_actionDeconnexion_triggered()
{
    this->close();
}
