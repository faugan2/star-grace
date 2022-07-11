#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
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

private:
    Ui::Login *ui;
    MainWindow *m;
};

#endif // LOGIN_H
