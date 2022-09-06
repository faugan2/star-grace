/********************************************************************************
** Form generated from reading UI file 'allsa.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLSA_H
#define UI_ALLSA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AllSa
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *table_sa;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *AllSa)
    {
        if (AllSa->objectName().isEmpty())
            AllSa->setObjectName(QStringLiteral("AllSa"));
        AllSa->resize(400, 269);
        verticalLayout = new QVBoxLayout(AllSa);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        table_sa = new QTableWidget(AllSa);
        if (table_sa->columnCount() < 4)
            table_sa->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_sa->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_sa->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_sa->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_sa->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_sa->setObjectName(QStringLiteral("table_sa"));
        table_sa->setAlternatingRowColors(true);
        table_sa->setGridStyle(Qt::DashDotDotLine);
        table_sa->horizontalHeader()->setStretchLastSection(true);
        table_sa->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(table_sa);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(AllSa);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:8px;\n"
"border:none;"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AllSa);

        QMetaObject::connectSlotsByName(AllSa);
    } // setupUi

    void retranslateUi(QDialog *AllSa)
    {
        AllSa->setWindowTitle(QApplication::translate("AllSa", "Tous les produits en alertes", 0));
        QTableWidgetItem *___qtablewidgetitem = table_sa->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AllSa", "Point de vente", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_sa->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AllSa", "Produits", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_sa->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AllSa", "En Stock", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_sa->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AllSa", "SA", 0));
        pushButton->setText(QApplication::translate("AllSa", "Mettre \303\240 jour", 0));
    } // retranslateUi

};

namespace Ui {
    class AllSa: public Ui_AllSa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLSA_H
