#include "parametres.h"
#include "ui_parametres.h"

Parametres::Parametres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parametres)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

}

Parametres::~Parametres()
{
    delete ui;
}
