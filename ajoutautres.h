#ifndef AJOUTAUTRES_H
#define AJOUTAUTRES_H

#include <QDialog>
#include "includes.h"
#include "modifierstock.h"

namespace Ui {
class AjoutAutres;
}

class AjoutAutres : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutAutres(QWidget *parent = 0);
    ~AjoutAutres();

private slots:
    void on_pushButton_clicked();
    void load_list();
    void init();

    void on_search_textChanged(const QString &arg1);

    void on_btn_edit_clicked();

    void on_btn_del_clicked();

    void on_table_liste_point_vente_cellClicked(int row, int column);
    void load_formats();

    void on_btn_modif_stock_clicked();

private:
    Ui::AjoutAutres *ui;
    QString id_selected;
    ModifierStock *modif_stock;
};

#endif // AJOUTAUTRES_H
