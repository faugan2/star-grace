#ifndef BRIS_H
#define BRIS_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Bris;
}

class Bris : public QDialog
{
    Q_OBJECT

public:
    explicit Bris(QWidget *parent = 0);
    ~Bris();

private slots:
    void on_pushButton_clicked();

    void on_table_liste_point_vente_cellClicked(int row, int column);

    void on_btn_edit_clicked();

    void on_btn_del_clicked();

private:
    Ui::Bris *ui;
    void load_liste();
    void load_produits();
    QString selected_token;
    QStringList list_produits;
};

#endif // BRIS_H
