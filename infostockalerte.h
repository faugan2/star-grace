#ifndef INFOSTOCKALERTE_H
#define INFOSTOCKALERTE_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class InfoStockAlerte;
}

class InfoStockAlerte : public QDialog
{
    Q_OBJECT

public:
    explicit InfoStockAlerte(QString id,QWidget *parent = 0);
    ~InfoStockAlerte();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InfoStockAlerte *ui;
    QString id_produit;
};

#endif // INFOSTOCKALERTE_H
