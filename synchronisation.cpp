#include "synchronisation.h"
#include "ui_synchronisation.h"

Synchronisation::Synchronisation(QSqlDatabase db,QString id_user,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Synchronisation)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setFixedWidth(400);
    ui->progressBar->hide();
    this->id_user=id_user;
    this->db=db;
}

Synchronisation::~Synchronisation()
{
    delete ui;
}

void Synchronisation::on_pushButton_2_clicked()
{
    this->close();
}

void Synchronisation::on_pushButton_clicked()
{
    //ui->progressBar->show();
    //Loading* loading=new Loading(db,id_user,this);
   // loading->show();
    //this->close();
}
