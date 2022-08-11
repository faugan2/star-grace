/********************************************************************************
** Form generated from reading UI file 'infostockalerte.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOSTOCKALERTE_H
#define UI_INFOSTOCKALERTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoStockAlerte
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *produit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *qte;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *InfoStockAlerte)
    {
        if (InfoStockAlerte->objectName().isEmpty())
            InfoStockAlerte->setObjectName(QStringLiteral("InfoStockAlerte"));
        InfoStockAlerte->resize(239, 71);
        verticalLayout = new QVBoxLayout(InfoStockAlerte);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        produit = new QLabel(InfoStockAlerte);
        produit->setObjectName(QStringLiteral("produit"));
        produit->setStyleSheet(QStringLiteral("font-weight:bold;"));

        horizontalLayout->addWidget(produit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(InfoStockAlerte);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        qte = new QLineEdit(InfoStockAlerte);
        qte->setObjectName(QStringLiteral("qte"));

        horizontalLayout_2->addWidget(qte);

        pushButton = new QPushButton(InfoStockAlerte);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(InfoStockAlerte);

        QMetaObject::connectSlotsByName(InfoStockAlerte);
    } // setupUi

    void retranslateUi(QDialog *InfoStockAlerte)
    {
        InfoStockAlerte->setWindowTitle(QApplication::translate("InfoStockAlerte", "Gestion de l'alerte du produit", 0));
        produit->setText(QApplication::translate("InfoStockAlerte", "Nom du produit", 0));
        label_2->setText(QApplication::translate("InfoStockAlerte", "Qte : ", 0));
        pushButton->setText(QApplication::translate("InfoStockAlerte", "Ajouter", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoStockAlerte: public Ui_InfoStockAlerte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOSTOCKALERTE_H
