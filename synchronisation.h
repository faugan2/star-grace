#ifndef SYNCHRONISATION_H
#define SYNCHRONISATION_H

#include <QDialog>
#include "includes.h"


namespace Ui {
class Synchronisation;
}

class Synchronisation : public QDialog
{
    Q_OBJECT

public:
    explicit Synchronisation(QSqlDatabase db,QString id_user,QWidget *parent = 0);
    ~Synchronisation();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Synchronisation *ui;

    QSqlDatabase db;
    QString id_user;
};

#endif // SYNCHRONISATION_H
