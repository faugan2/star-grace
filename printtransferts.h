#ifndef PRINTTRANSFERTS_H
#define PRINTTRANSFERTS_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class PrintTransferts;
}

class PrintTransferts : public QDialog
{
    Q_OBJECT

public:
    explicit PrintTransferts(QWidget *parent = 0);
    ~PrintTransferts();

private:
    Ui::PrintTransferts *ui;
};

#endif // PRINTTRANSFERTS_H
