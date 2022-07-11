#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ajouterpointdevente.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionFermer_triggered();

    void on_actionDeconnexion_triggered();

private:
    Ui::MainWindow *ui;
    AjouterPointDeVente *ajout_point_vente;
};

#endif // MAINWINDOW_H
