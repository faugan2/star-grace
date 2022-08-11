#ifndef ALLIMPAYES_H
#define ALLIMPAYES_H

#include <QDialog>
#include "includes.h"
#include "infoclient.h"

namespace Ui {
class AllImpayes;
}

class AllImpayes : public QDialog
{
    Q_OBJECT

public:
    explicit AllImpayes(QWidget *parent = 0);
    ~AllImpayes();

private slots:
    void on_table_impaye_cellClicked(int row, int column);

private:
    Ui::AllImpayes *ui;
    InfoClient *info_client;
};

#endif // ALLIMPAYES_H
