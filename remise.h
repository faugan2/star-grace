#ifndef REMISE_H
#define REMISE_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Remise;
}

class Remise : public QDialog
{
    Q_OBJECT

public:
    explicit Remise(float total,QWidget *parent = 0);
    ~Remise();

private slots:
    void on_a_payer_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Remise *ui;
    float total;
};

#endif // REMISE_H
