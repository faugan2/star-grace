#ifndef PARAMETRES_H
#define PARAMETRES_H

#include <QDialog>
#include "includes.h"
namespace Ui {
class Parametres;
}

class Parametres : public QDialog
{
    Q_OBJECT

public:
    explicit Parametres(QWidget *parent = 0);
    ~Parametres();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_3_clicked();

    void on_checkBox_clicked();

private:
    Ui::Parametres *ui;
};

#endif // PARAMETRES_H
