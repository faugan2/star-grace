#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "includes.h"



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

private:
    Ui::Login *ui;
    MainWindow *m;
    QSqlDatabase db;
};

#endif // LOGIN_H
