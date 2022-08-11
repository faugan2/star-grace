#ifndef DEPENSES_H
#define DEPENSES_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Depenses;
}

class Depenses : public QDialog
{
    Q_OBJECT

public:
    explicit Depenses(QWidget *parent = 0);
    ~Depenses();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Depenses *ui;
    void load_liste();
};

#endif // DEPENSES_H
