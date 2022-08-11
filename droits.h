#ifndef DROITS_H
#define DROITS_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Droits;
}

class Droits : public QDialog
{
    Q_OBJECT

public:
    explicit Droits(QString id_user, QWidget *parent = 0);
    ~Droits();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Droits *ui;
    QString id_user;
};

#endif // DROITS_H
