#ifndef INFOPOINTDEVENTE_H
#define INFOPOINTDEVENTE_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class InfoPointDeVente;
}

class InfoPointDeVente : public QDialog
{
    Q_OBJECT

public:
    explicit InfoPointDeVente(QString id,QWidget *parent = 0);
    ~InfoPointDeVente();
private slots:


    void on_table_produits_cellClicked(int row, int column);

    void on_table_produits_cellActivated(int row, int column);

    void on_table_produits_cellChanged(int row, int column);

    void on_btn_modifier_stock_clicked();

    void on_unite_carton_clicked();

    void on_unite_m2_clicked();

    void on_unite_piece_clicked();

private:
    Ui::InfoPointDeVente *ui;
    QString id_selected;
    QString point_vente;

    void load_liste_users();
    void load_produits();

};

#endif // INFOPOINTDEVENTE_H
