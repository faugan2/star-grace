#ifndef LOADING_H
#define LOADING_H

#include <QDialog>
#include "includes.h"
#include "mainwindow.h"

namespace Ui {
class Loading;
}

class Loading : public QDialog
{
    Q_OBJECT

public:
    explicit Loading(QSqlDatabase db, QString id_user, bool auto_start,QWidget *parent = 0);
    ~Loading();

private slots:


    void update();
    void onfinish(QNetworkReply*);

    void load_bris();
    void load_clients();
    void load_depenses();
    void load_droit();
    void load_formats();
    //##############################
    void load_points_vente();
    void load_prepayements();
    void load_retrait();
    void load_stock();
    void load_transfert();
    void load_users();
    void load_vente_options();
    //##############################

    void load_mouvements();


    void load_offline_data();




    void update_final();

    void online_to_local(QList<QStringList> *from,QList<QStringList> *to,QString table,QStringList columns);
    void load_table_data(QString table,QStringList cols,QList<QStringList> **storage);

    void delay(){
        qDebug()<<"going to delay";
    }


    void on_btn_commencer_clicked();

    void on_btn_terminer_clicked();

private:
    Ui::Loading *ui;
    QSqlDatabase db;
    QSqlDatabase db_offline;
    QString id_user;

    QList<QStringList> *online_bris;
    QList<QStringList> *online_clients;
    QList<QStringList> *online_depenses;
    QList<QStringList> *online_droits;
    QList<QStringList> *online_formats;
    QList<QStringList> *online_points_vente;
    QList<QStringList> *online_prepayements;
    QList<QStringList> *online_retrait;
    QList<QStringList> *online_stock;
    QList<QStringList> *online_transfert;
    QList<QStringList> *online_users;
    QList<QStringList> *online_vente_options;
    QList<QStringList> *online_mouvements;

    QList<QStringList> *offline_bris;
    QList<QStringList> *offline_clients;
    QList<QStringList> *offline_depenses;
    QList<QStringList> *offline_droits;
    QList<QStringList> *offline_formats;
    QList<QStringList> *offline_points_vente;
    QList<QStringList> *offline_prepayements;
    QList<QStringList> *offline_retrait;
    QList<QStringList> *offline_stock;
    QList<QStringList> *offline_transfert;
    QList<QStringList> *offline_users;
    QList<QStringList> *offline_vente_options;
    QList<QStringList> *offline_mouvements;


};


#endif // LOADING_H
