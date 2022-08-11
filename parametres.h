#ifndef PARAMETRES_H
#define PARAMETRES_H

#include <QDialog>

namespace Ui {
class Parametres;
}

class Parametres : public QDialog
{
    Q_OBJECT

public:
    explicit Parametres(QWidget *parent = 0);
    ~Parametres();

private:
    Ui::Parametres *ui;
};

#endif // PARAMETRES_H
