#ifndef MODIFIERSTOCK_H
#define MODIFIERSTOCK_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class ModifierStock;
}

class ModifierStock : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierStock(QString id,QWidget *parent = 0);
    ~ModifierStock();

private slots:
    void on_pushButton_clicked();
    void load_magazing();

private:
    Ui::ModifierStock *ui;
    QString id_selected;
    QStringList points_vente;
};

#endif // MODIFIERSTOCK_H
