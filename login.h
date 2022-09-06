#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "includes.h"
#include "loading.h"
#include "mainwindow.h"



namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();
    void onfinish(QNetworkReply *rep);

    void on_identifiant_textChanged(const QString &arg1);

    void on_password_textChanged(const QString &arg1);

    void on_serveur_distant_clicked();
    void close_db();
    void load_server();

private:
    Ui::Login *ui;

    //MainWindow *m;
public:
    QSqlDatabase db;
    QSqlDatabase db_online;
};

#endif // LOGIN_H
