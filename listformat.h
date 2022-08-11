#ifndef LISTFORMAT_H
#define LISTFORMAT_H

#include <QDialog>
#include "includes.h"
namespace Ui {
class Listformat;
}

class Listformat : public QDialog
{
    Q_OBJECT

public:
    explicit Listformat(QWidget *parent = 0);
    ~Listformat();

private slots:
    void on_pushButton_clicked();
    void load_list();
    void init();

    void on_btn_del_clicked();

    void on_table_liste_point_vente_clicked(const QModelIndex &index);

    void on_table_liste_point_vente_cellClicked(int row, int column);

    void on_search_textChanged(const QString &arg1);

    void on_btn_edit_clicked();

private:
    Ui::Listformat *ui;
    QString id_selected;
};

#endif // LISTFORMAT_H
