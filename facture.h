#ifndef FACTURE_H
#define FACTURE_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Facture;
}

class Facture : public QDialog
{
    Q_OBJECT

public:
    explicit Facture(QString token,QWidget *parent = 0);
    ~Facture();

private:
    Ui::Facture *ui;
    QString numberToText(uint number);
};

#endif // FACTURE_H
