#ifndef APERCUFACTUREWITHTOKEN_H
#define APERCUFACTUREWITHTOKEN_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class ApercuFactureWithToken;
}

class ApercuFactureWithToken : public QDialog
{
    Q_OBJECT

public:
    explicit ApercuFactureWithToken(QString token,QWidget *parent = 0);
    ~ApercuFactureWithToken();

private:
    Ui::ApercuFactureWithToken *ui;
};

#endif // APERCUFACTUREWITHTOKEN_H
