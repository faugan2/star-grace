#ifndef BON_H
#define BON_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Bon;
}

class Bon : public QDialog
{
    Q_OBJECT

public:
    explicit Bon(QString token,QWidget *parent = 0);
    ~Bon();

private:
    Ui::Bon *ui;
};

#endif // BON_H
