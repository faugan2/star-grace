#ifndef TRANSFERTPRODUITS_H
#define TRANSFERTPRODUITS_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class TransfertProduits;
}

class TransfertProduits : public QDialog
{
    Q_OBJECT

public:
    explicit TransfertProduits(QWidget *parent = 0);
    ~TransfertProduits();

private slots:
    void on_du_currentIndexChanged(int index);

    void on_produit_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::TransfertProduits *ui;
    void load_liste();
    void load_point_vente();
    void load_produits();
    void calculate_remaining_qte();
};

#endif // TRANSFERTPRODUITS_H
