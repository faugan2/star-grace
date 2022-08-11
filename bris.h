#ifndef BRIS_H
#define BRIS_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Bris;
}

class Bris : public QDialog
{
    Q_OBJECT

public:
    explicit Bris(QWidget *parent = 0);
    ~Bris();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Bris *ui;
    void load_liste();
    void load_produits();
};

#endif // BRIS_H
