#include "ajouterpointdevente.h"
#include "ui_ajouterpointdevente.h"

AjouterPointDeVente::AjouterPointDeVente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPointDeVente)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedSize(this->sizeHint());
}

AjouterPointDeVente::~AjouterPointDeVente()
{
    delete ui;
}

void AjouterPointDeVente::on_pushButton_clicked()
{
    this->close();
}
