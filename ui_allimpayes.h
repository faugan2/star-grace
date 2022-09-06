/********************************************************************************
** Form generated from reading UI file 'allimpayes.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLIMPAYES_H
#define UI_ALLIMPAYES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AllImpayes
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *table_impaye;

    void setupUi(QDialog *AllImpayes)
    {
        if (AllImpayes->objectName().isEmpty())
            AllImpayes->setObjectName(QStringLiteral("AllImpayes"));
        AllImpayes->resize(489, 229);
        verticalLayout = new QVBoxLayout(AllImpayes);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        table_impaye = new QTableWidget(AllImpayes);
        if (table_impaye->columnCount() < 4)
            table_impaye->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_impaye->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_impaye->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_impaye->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_impaye->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_impaye->setObjectName(QStringLiteral("table_impaye"));
        table_impaye->setAlternatingRowColors(true);
        table_impaye->setGridStyle(Qt::DashDotDotLine);
        table_impaye->horizontalHeader()->setStretchLastSection(true);
        table_impaye->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(table_impaye);


        retranslateUi(AllImpayes);

        QMetaObject::connectSlotsByName(AllImpayes);
    } // setupUi

    void retranslateUi(QDialog *AllImpayes)
    {
        AllImpayes->setWindowTitle(QApplication::translate("AllImpayes", "Tous les clients avec des impay\303\251s", 0));
        QTableWidgetItem *___qtablewidgetitem = table_impaye->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AllImpayes", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_impaye->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AllImpayes", "Facture N\302\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_impaye->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AllImpayes", "Client", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_impaye->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AllImpayes", "A Payer", 0));
    } // retranslateUi

};

namespace Ui {
    class AllImpayes: public Ui_AllImpayes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLIMPAYES_H
