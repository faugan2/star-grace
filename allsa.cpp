#include "allsa.h"
#include "ui_allsa.h"

AllSa::AllSa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllSa)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QSqlQuery qr;
    qr.exec("select * from stock where alerte <>''");
    int row=0;
    while(qr.next()){
        QString id_produit=qr.value("id").toString();
        QString sa=qr.value("alerte").toString();
        QString produit=qr.value("nom").toString();

        QString in_stock=0;
        QSqlQuery qr2;
        qr2.exec("select sum(qte) from mouvements where produit='"+id_produit+"'");
        if(qr2.next()){
            in_stock=qr2.value(0).toString();
        }
        if(in_stock.toFloat()>sa.toFloat()){
            return;
        }
        ui->table_sa->setRowCount(row+1);
        ui->table_sa->setItem(row,0,new QTableWidgetItem(produit));
        ui->table_sa->setItem(row,1,new QTableWidgetItem(in_stock));
        ui->table_sa->setItem(row,2,new QTableWidgetItem(sa));


        ui->table_sa->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table_sa->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table_sa->item(row,2)->setTextAlignment(Qt::AlignCenter);

        ui->table_sa->item(row,0)->setToolTip(id_produit);


        row++;

    }
}

AllSa::~AllSa()
{
    delete ui;
}

void AllSa::on_table_sa_cellClicked(int row, int column)
{
    QString id_produit=ui->table_sa->item(row,0)->toolTip();
    info_sa=new InfoStockAlerte(id_produit,this);
    info_sa->setModal(true);
    info_sa->show();
}
