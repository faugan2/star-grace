#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString get_printing_headers();

private:
    Ui::Dialog *ui;


};

#endif // DIALOG_H
