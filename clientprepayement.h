#ifndef CLIENTPREPAYEMENT_H
#define CLIENTPREPAYEMENT_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class ClientPrePayement;
}

class ClientPrePayement : public QDialog
{
    Q_OBJECT

public:
    explicit ClientPrePayement(QString id,QWidget *parent = 0);
    ~ClientPrePayement();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClientPrePayement *ui;
    QString id;
};

#endif // CLIENTPREPAYEMENT_H
