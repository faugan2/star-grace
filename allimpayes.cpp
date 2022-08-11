#include "allimpayes.h"
#include "ui_allimpayes.h"

AllImpayes::AllImpayes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllImpayes)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QSqlQuery qr;
    qr.exec("select * from ventes_options where impaye<>'' order by id asc");
    int row=0;
    ui->table_impaye->setRowCount(0);
    while(qr.next()){
        QString token=qr.value("token").toString();
        QString impaye=qr.value("impaye").toString().split("#").at(2);
        QString id_client=qr.value("client").toString();

        QSqlQuery qr2;
        qr2.exec("select * from clients where id='"+id_client+"'");
        QString nom_client="";
        if(qr2.next()){
            nom_client=qr2.value("nom").toString();
        }

        qr2.exec("select * from mouvements where token='"+token+"'");
        QString date="";
        if(qr2.next()){
            date=qr2.value("date").toString().split("T").at(0);
        }

        ui->table_impaye->setRowCount(row+1);

        ui->table_impaye->setItem(row,0,new QTableWidgetItem(date));
        ui->table_impaye->setItem(row,1,new QTableWidgetItem(token));
        ui->table_impaye->setItem(row,2,new QTableWidgetItem(nom_client));
        ui->table_impaye->setItem(row,3,new QTableWidgetItem(impaye));

        ui->table_impaye->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table_impaye->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table_impaye->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->table_impaye->item(row,3)->setTextAlignment(Qt::AlignCenter);

        ui->table_impaye->item(row,0)->setToolTip(token);
        ui->table_impaye->item(row,1)->setToolTip(id_client);

         row++;
    }
}

AllImpayes::~AllImpayes()
{
    delete ui;
}

void AllImpayes::on_table_impaye_cellClicked(int row, int column)
{
    QString token=ui->table_impaye->item(row,0)->toolTip();
    QString id_client=ui->table_impaye->item(row,1)->toolTip();

    QSqlQuery qr;
    qr.exec("delete from token");
    qr.exec("insert into token values('"+token+"')");

    info_client=new InfoClient(id_client,this);
    info_client->setModal(true);
    info_client->show();

}
