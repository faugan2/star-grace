#ifndef APERCUFACTUR_H
#define APERCUFACTUR_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class ApercuFactur;
}

class ApercuFactur : public QDialog
{
    Q_OBJECT

public:
    explicit ApercuFactur(
            QStringList vente_produit,
            QStringList vente_produit_format,
            QStringList vente_qte,
            QStringList vente_qte_m2,
            QStringList vente_pu,
            QStringList vente_total,
            QStringList vente_carton,
            QStringList unites,
            QString vente_client,
            QWidget *parent = 0);
    ~ApercuFactur();

private:
    Ui::ApercuFactur *ui;
};

#endif // APERCUFACTUR_H
