#ifndef AJOUTERPOINTDEVENTE_H
#define AJOUTERPOINTDEVENTE_H

#include <QDialog>

namespace Ui {
class AjouterPointDeVente;
}

class AjouterPointDeVente : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterPointDeVente(QWidget *parent = 0);
    ~AjouterPointDeVente();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AjouterPointDeVente *ui;
};

#endif // AJOUTERPOINTDEVENTE_H
