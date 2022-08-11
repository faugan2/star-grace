#ifndef IMPAYE_H
#define IMPAYE_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Impaye;
}

class Impaye : public QDialog
{
    Q_OBJECT

public:
    explicit Impaye(float total,QWidget *parent = 0);
    ~Impaye();

private slots:
    void on_pushButton_clicked();

    void on_a_payer_textChanged(const QString &arg1);

private:
    Ui::Impaye *ui;
    float total;
};

#endif // IMPAYE_H
