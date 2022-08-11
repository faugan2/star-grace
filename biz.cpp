#include "biz.h"
#include "ui_biz.h"

Biz::Biz(QStringList vente_produit,QStringList vente_qte,QStringList vente_pu,QStringList vente_total,QStringList vente_cartons,QString vente_client,QStringList vente_qte_m2,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Biz)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    this->vente_produit=vente_produit;
    this->vente_qte=vente_qte;
    this->vente_pu=vente_pu;
    this->vente_total=vente_total;
    this->vente_carton=vente_cartons;
    this->vente_client=vente_client;
    this->vente_qte_m2=vente_qte_m2;

    load_produits();
    ui->options->hide();

}

Biz::~Biz()
{
    delete ui;
}

void Biz::load_produits()
{
    QSqlQuery qr;
    ui->produits->clear();
    ui->produits->addItem("Choisir un produit");
    for(int i=0 ;i<vente_produit.length(); i++){
        QString id_produit=vente_produit.at(i);
        QString nom_produit="";
        qr.exec("select * from stock where id='"+id_produit+"'");
        if(qr.next()){
            nom_produit=qr.value("nom").toString();
            ui->produits->addItem(nom_produit,qr.value(0));
        }

    }

}

void Biz::calculate_total_biz()
{
   QString qte_biz=ui->qte_biz->text();
   QString pu_biz=ui->prix_biz->text();
   if(qte_biz.isEmpty() || pu_biz.isEmpty()){
       return;
   }

   float qte=qte_biz.toFloat();
   float pu=pu_biz.toFloat();
   float total=qte*pu;

   ui->total_biz->setText(QString::number(total));

}

void Biz::on_produits_currentIndexChanged(int index)
{
    if(index==0){
        ui->options->hide();
        return;
    }
    ui->options->show();
    QString qte=vente_qte_m2.at(index-1);
    QString pu=vente_pu.at(index-1);
    QString t=vente_total.at(index-1);
    QString id_produit=ui->produits->currentData().toString();

    ui->qte->setText(qte);
    ui->prix->setText(pu);
    ui->total->setText(t);

    ui->qte_biz->clear();
    ui->prix_biz->clear();
    ui->total_biz->clear();

    QSqlQuery qr;
    qr.exec("select * from biz where produit='"+id_produit+"'");
    if(qr.next()){
        ui->qte_biz->setText(qr.value("qte").toString());
        ui->prix_biz->setText(qr.value("prix").toString());
        ui->total_biz->setText(qr.value("total").toString());
    }
}

void Biz::on_pushButton_clicked()
{
    QString qte=ui->qte_biz->text();
    QString prix=ui->prix_biz->text();
    QString total=ui->total_biz->text();
    QString produit=ui->produits->currentData().toString();

    if(qte.isEmpty() || prix.isEmpty() || total.isEmpty() ){
        QMessageBox::warning(this,"Erreur","Vous devez remplir tous les champs");
        return;
    }

    QSqlQuery qr;
    qr.exec("delete  from biz where produit='"+produit+"'");
    qr.prepare("insert into biz(produit,qte,prix,total) values(:produit,:qte,:prix,:total)");
    qr.bindValue(":produit",produit);
    qr.bindValue(":qte",qte);
    qr.bindValue(":prix",prix);
    qr.bindValue(":total",total);
    if(qr.exec()){
        ui->produits->setCurrentIndex(0);
        ui->qte->clear();
        ui->qte_biz->clear();
        ui->prix->clear();
        ui->prix_biz->clear();
        ui->total->clear();
        ui->total_biz->clear();
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }


}

void Biz::on_qte_biz_textChanged(const QString &arg1)
{
    calculate_total_biz();
}

void Biz::on_prix_biz_textChanged(const QString &arg1)
{
    calculate_total_biz();
}
