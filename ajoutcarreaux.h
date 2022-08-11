#ifndef AJOUTCARREAUX_H
#define AJOUTCARREAUX_H

#include <QDialog>
#include "includes.h"
#include "modifierstock.h"

namespace Ui {
class AjoutCarreaux;
}

class AjoutCarreaux : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutCarreaux(QWidget *parent = 0);
    ~AjoutCarreaux();

private slots:
    void on_pushButton_clicked();
    void load_list();
    void init();

    void on_search_textChanged(const QString &arg1);

    void on_btn_edit_clicked();

    void on_btn_del_clicked();

    void on_table_liste_point_vente_cellClicked(int row, int column);
    void load_formats();

    void on_btn_modifier_stock_clicked();

    void on_format_currentTextChanged(const QString &arg1);

    void on_table_liste_point_vente_cellChanged(int row, int column);

    void on_table_liste_point_vente_cellEntered(int row, int column);

    void on_table_liste_point_vente_activated(const QModelIndex &index);

    void on_table_liste_point_vente_entered(const QModelIndex &index);

private:
    Ui::AjoutCarreaux *ui;
    QString id_selected;
    ModifierStock *modif_stock;
    bool can_update;
};

#endif // AJOUTCARREAUX_H
