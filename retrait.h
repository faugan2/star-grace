#ifndef RETRAIT_H
#define RETRAIT_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Retrait;
}

class Retrait : public QDialog
{
    Q_OBJECT

public:
    explicit Retrait(QWidget *parent = 0);
    ~Retrait();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Retrait *ui;
    void load_liste();
};

#endif // RETRAIT_H
