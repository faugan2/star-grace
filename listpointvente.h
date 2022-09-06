#ifndef LISTPOINTVENTE_H
#define LISTPOINTVENTE_H

#include <QDialog>
#include "includes.h"
#include "infopointdevente.h"
namespace Ui {
class listpointvente;
}

class listpointvente : public QDialog
{
    Q_OBJECT

public:
    explicit listpointvente(QWidget *parent = 0);
    ~listpointvente();

private slots:
    void on_pushButton_clicked();

    void load_list();
    void init();
    void on_table_liste_point_vente_cellClicked(int row, int column);

    void on_btn_edit_clicked();

    void on_btn_del_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::listpointvente *ui;
    QString id_selected;
    InfoPointDeVente *info_point_vente;
};

#endif // LISTPOINTVENTE_H
