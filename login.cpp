#include "login.h"
#include "ui_login.h"
#include <iostream>
#include <QDebug>
#include <QThread>

using namespace std;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedSize(this->sizeHint());

    QPixmap logo(":/img/logo-removebg-preview.png");
    QPixmap newPixmap = logo.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    ui->label_2->setPixmap(newPixmap);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    ui->alerte->setText("");
    QString identifiant=ui->identifiant->text();
    QString password=ui->password->text();

    if(identifiant.isEmpty() || password.isEmpty()){
        ui->alerte->setText("certains champs sont vides");
        //return;
    }

    ui->pushButton->setEnabled(false);
    ui->pushButton->setText("Patientez...");
    this->close();
    m=new MainWindow();
    m->showMaximized();



}
