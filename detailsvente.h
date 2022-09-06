#ifndef DETAILSVENTE_H
#define DETAILSVENTE_H

#include <QDialog>
#include "includes.h"
#include "facture.h";
#include "bon.h"
#include "apercufacturewithtoken.h"

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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DetailsVente *ui;
    Facture *facture;
    ApercuFactureWithToken *apercu_facture_with_token;
    Bon *bon;
    QString token_facture;
    void print_facture(QString token);

};

#endif // DETAILSVENTE_H
