#ifndef ALLSA_H
#define ALLSA_H

#include <QDialog>
#include "includes.h"
#include "infostockalerte.h"

namespace Ui {
class AllSa;
}

class AllSa : public QDialog
{
    Q_OBJECT

public:
    explicit AllSa(QWidget *parent = 0);
    ~AllSa();

private slots:
    void on_table_sa_cellClicked(int row, int column);

private:
    Ui::AllSa *ui;
    InfoStockAlerte *info_sa;
};

#endif // ALLSA_H
