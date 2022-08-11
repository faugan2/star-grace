#ifndef BIZ_H
#define BIZ_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class Biz;
}

class Biz : public QDialog
{
    Q_OBJECT

public:
    explicit Biz(QStringList vente_produit,QStringList vente_qte,QStringList vente_pu,QStringList vente_total,QStringList vente_cartons,QString vente_client,QStringList vente_qte_m2,QWidget *parent = 0);
    ~Biz();

private slots:
    void on_produits_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_qte_biz_textChanged(const QString &arg1);

    void on_prix_biz_textChanged(const QString &arg1);

private:
    Ui::Biz *ui;
    QStringList vente_produit;
    QStringList vente_produit_format;
    QStringList vente_qte;
    QStringList vente_pu;
    QStringList vente_total;
    QStringList vente_carton;
    QString vente_client;
    QStringList vente_qte_m2;

    void load_produits();
    void calculate_total_biz();
};

#endif // BIZ_H
