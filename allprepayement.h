#ifndef ALLPREPAYEMENT_H
#define ALLPREPAYEMENT_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class AllPrePayement;
}

class AllPrePayement : public QDialog
{
    Q_OBJECT

public:
    explicit AllPrePayement(QWidget *parent = 0);
    ~AllPrePayement();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AllPrePayement *ui;
    void load_clients();
    void load_liste();
};

#endif // ALLPREPAYEMENT_H
