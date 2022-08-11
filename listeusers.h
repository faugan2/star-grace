#ifndef LISTEUSERS_H
#define LISTEUSERS_H

#include <QDialog>
#include "includes.h"
#include "droits.h"

namespace Ui {
class ListeUsers;
}

class ListeUsers : public QDialog
{
    Q_OBJECT

public:
    explicit ListeUsers(QSqlDatabase db, QWidget *parent = 0);
    ~ListeUsers();

private slots:
    void on_pushButton_clicked();

    void on_table_liste_users_cellClicked(int row, int column);

    void on_btn_del_clicked();

    void on_btn_edit_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_btn_droit_clicked();

private:
    Ui::ListeUsers *ui;
    QSqlDatabase db;
    QString id_selected_user;

    Droits *droits;


    void load_list();
    void load_type();
    void load_point_vente();
    void init();
};

#endif // LISTEUSERS_H
