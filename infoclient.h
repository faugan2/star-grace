#ifndef INFOCLIENT_H
#define INFOCLIENT_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class InfoClient;
}

class InfoClient : public QDialog
{
    Q_OBJECT

public:
    explicit InfoClient(QString id,QWidget *parent = 0);
    ~InfoClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InfoClient *ui;
    QString id_client;
    QString token;
};

#endif // INFOCLIENT_H
