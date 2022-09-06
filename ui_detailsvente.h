/********************************************************************************
** Form generated from reading UI file 'detailsvente.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILSVENTE_H
#define UI_DETAILSVENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DetailsVente
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *table_vente;
    QHBoxLayout *horizontalLayout_3;
    QLabel *valeur_total;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *bon;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *remise;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *impaye;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_biz;
    QTableWidget *table_biz;
    QSpacerItem *verticalSpacer;
    QGroupBox *non_livre;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DetailsVente)
    {
        if (DetailsVente->objectName().isEmpty())
            DetailsVente->setObjectName(QStringLiteral("DetailsVente"));
        DetailsVente->resize(645, 282);
        verticalLayout_3 = new QVBoxLayout(DetailsVente);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox = new QGroupBox(DetailsVente);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        table_vente = new QTableWidget(groupBox);
        if (table_vente->columnCount() < 4)
            table_vente->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_vente->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_vente->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_vente->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_vente->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_vente->setObjectName(QStringLiteral("table_vente"));
        table_vente->setAutoFillBackground(false);
        table_vente->setAlternatingRowColors(true);
        table_vente->setGridStyle(Qt::DashDotDotLine);
        table_vente->horizontalHeader()->setStretchLastSection(true);
        table_vente->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(table_vente);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        valeur_total = new QLabel(groupBox);
        valeur_total->setObjectName(QStringLiteral("valeur_total"));
        valeur_total->setStyleSheet(QStringLiteral("font-weight:bold;"));

        horizontalLayout_3->addWidget(valeur_total);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        bon = new QCheckBox(groupBox);
        bon->setObjectName(QStringLiteral("bon"));

        horizontalLayout_3->addWidget(bon);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:8px;\n"
"border:none;"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:5px;\n"
"border:none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/images/imprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(DetailsVente);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        remise = new QLabel(groupBox_2);
        remise->setObjectName(QStringLiteral("remise"));

        horizontalLayout->addWidget(remise);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        impaye = new QLabel(groupBox_2);
        impaye->setObjectName(QStringLiteral("impaye"));

        horizontalLayout_2->addWidget(impaye);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_biz = new QLabel(groupBox_2);
        label_biz->setObjectName(QStringLiteral("label_biz"));

        horizontalLayout_4->addWidget(label_biz);


        verticalLayout->addLayout(horizontalLayout_4);

        table_biz = new QTableWidget(groupBox_2);
        if (table_biz->columnCount() < 4)
            table_biz->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_biz->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_biz->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_biz->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_biz->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        table_biz->setObjectName(QStringLiteral("table_biz"));
        table_biz->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_biz->setAlternatingRowColors(true);
        table_biz->setGridStyle(Qt::DashDotDotLine);
        table_biz->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(table_biz);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_6->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        non_livre = new QGroupBox(DetailsVente);
        non_livre->setObjectName(QStringLiteral("non_livre"));
        horizontalLayout_5 = new QHBoxLayout(non_livre);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        pushButton_2 = new QPushButton(non_livre);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("background-color:green;\n"
"color:white;\n"
"padding:8px;\n"
"border:none;\n"
"font-weight:bold;"));

        horizontalLayout_5->addWidget(pushButton_2);


        verticalLayout_3->addWidget(non_livre);


        retranslateUi(DetailsVente);

        QMetaObject::connectSlotsByName(DetailsVente);
    } // setupUi

    void retranslateUi(QDialog *DetailsVente)
    {
        DetailsVente->setWindowTitle(QApplication::translate("DetailsVente", "D\303\251tails de la vente", 0));
        groupBox->setTitle(QApplication::translate("DetailsVente", "Vente", 0));
        QTableWidgetItem *___qtablewidgetitem = table_vente->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DetailsVente", "Produit", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_vente->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DetailsVente", "Qte", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_vente->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DetailsVente", "Pu", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_vente->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DetailsVente", "Valeur", 0));
        valeur_total->setText(QString());
        bon->setText(QApplication::translate("DetailsVente", "Bon", 0));
        pushButton_3->setText(QApplication::translate("DetailsVente", "Aper\303\247u", 0));
        pushButton->setText(QString());
        groupBox_2->setTitle(QApplication::translate("DetailsVente", "Options", 0));
        label->setText(QApplication::translate("DetailsVente", "Remise", 0));
        remise->setText(QApplication::translate("DetailsVente", "-", 0));
        label_3->setText(QApplication::translate("DetailsVente", "Impay\303\251", 0));
        impaye->setText(QApplication::translate("DetailsVente", "-", 0));
        label_5->setText(QApplication::translate("DetailsVente", "Biz", 0));
        label_biz->setText(QApplication::translate("DetailsVente", "-", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_biz->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("DetailsVente", "Produit", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_biz->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("DetailsVente", "Qte", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_biz->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("DetailsVente", "Prix", 0));
        QTableWidgetItem *___qtablewidgetitem7 = table_biz->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("DetailsVente", "Total", 0));
        non_livre->setTitle(QApplication::translate("DetailsVente", "NON LIVRE", 0));
        pushButton_2->setText(QApplication::translate("DetailsVente", "Marquer comme livr\303\251", 0));
    } // retranslateUi

};

namespace Ui {
    class DetailsVente: public Ui_DetailsVente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILSVENTE_H
