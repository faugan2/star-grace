#include "infostockalerte.h"
#include "ui_infostockalerte.h"

InfoStockAlerte::InfoStockAlerte(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoStockAlerte)
{
    ui->setupUi(this);
    this->id_produit=id;
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QSqlQuery qr;
    qr.exec("select * from stock where id='"+id+"'");
    if(qr.next()){
        ui->produit->setText(qr.value("nom").toString());
    }
    ui->qte->setValidator(new QIntValidator());
}

InfoStockAlerte::~InfoStockAlerte()
{
    delete ui;
}

void InfoStockAlerte::on_pushButton_clicked()
{
    QSqlQuery qr;
    QString qte=ui->qte->text();
    if(qte.isEmpty()){
        QMessageBox::warning(this,"Erreur","Renseignez la quantité");
        return;
    }

    this->close();



}
