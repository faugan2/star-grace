#ifndef DETAILSVENTE_H
#define DETAILSVENTE_H

#include <QDialog>
#include "includes.h"
#include "facture.h";
#include "bon.h"

namespace Ui {
class DetailsVente;
}

class DetailsVente : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsVente(QWidget *parent = 0);
    ~DetailsVente();

private slots:
    void on_pushButton_clicked();

    void on_bon_clicked();

private:
    Ui::DetailsVente *ui;
    Facture *facture;
    Bon *bon;
    void print_facture(QString token);

};

#endif // DETAILSVENTE_H
