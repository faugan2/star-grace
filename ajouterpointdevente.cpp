#include "ajouterpointdevente.h"
#include "ui_ajouterpointdevente.h"


AjouterPointDeVente::AjouterPointDeVente(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPointDeVente)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedSize(this->sizeHint());
    if(db.isOpen()){
        qDebug()<<"db is opened";
    }
}

AjouterPointDeVente::~AjouterPointDeVente()
{
    delete ui;
}

void AjouterPointDeVente::on_pushButton_clicked()
{
    QString adresse=ui->adresse->text();
    QString responsable=ui->responsable->text();
    QString contact=ui->contact->text();
    if(adresse.isEmpty() || responsable.isEmpty() || contact.isEmpty()){
        QMessageBox::warning(this,"Erreur","Vous devez saisir tous les champs");
        return;
    }

    QSqlQuery qr;
    qr.prepare("insert into points_vente(adresse,responsable,contact) values(:adresse,:responsable,:contact)");
    qr.bindValue(":adresse",adresse.toUpper());
    qr.bindValue(":responsable",responsable.toUpper());
    qr.bindValue(":contact",contact);
    if(qr.exec()){
        ui->alerte->setText("");
        ui->adresse->clear();
        ui->responsable->clear();
        ui->contact->clear();
    }else{
        ui->alerte->setText("Une erreur est survenue");
    }



}
