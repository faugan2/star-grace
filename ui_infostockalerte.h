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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoStockAlerte
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *point_vente;
    QHBoxLayout *horizontalLayout;
    QLabel *produit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *qte;
    QRadioButton *unite_m2;
    QRadioButton *unite_carton;
    QRadioButton *unite_piece;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *InfoStockAlerte)
    {
        if (InfoStockAlerte->objectName().isEmpty())
            InfoStockAlerte->setObjectName(QStringLiteral("InfoStockAlerte"));
        InfoStockAlerte->resize(386, 99);
        verticalLayout = new QVBoxLayout(InfoStockAlerte);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        point_vente = new QLabel(InfoStockAlerte);
        point_vente->setObjectName(QStringLiteral("point_vente"));
        point_vente->setStyleSheet(QLatin1String("font-weight:bold;\n"
""));
        point_vente->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(point_vente);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        produit = new QLabel(InfoStockAlerte);
        produit->setObjectName(QStringLiteral("produit"));
        produit->setStyleSheet(QLatin1String("font-weight:bold;\n"
"margin-top:16px;"));
        produit->setAlignment(Qt::AlignCenter);

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

        unite_m2 = new QRadioButton(InfoStockAlerte);
        unite_m2->setObjectName(QStringLiteral("unite_m2"));
        unite_m2->setChecked(true);

        horizontalLayout_2->addWidget(unite_m2);

        unite_carton = new QRadioButton(InfoStockAlerte);
        unite_carton->setObjectName(QStringLiteral("unite_carton"));

        horizontalLayout_2->addWidget(unite_carton);

        unite_piece = new QRadioButton(InfoStockAlerte);
        unite_piece->setObjectName(QStringLiteral("unite_piece"));

        horizontalLayout_2->addWidget(unite_piece);

        pushButton = new QPushButton(InfoStockAlerte);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:8px;"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(InfoStockAlerte);

        QMetaObject::connectSlotsByName(InfoStockAlerte);
    } // setupUi

    void retranslateUi(QDialog *InfoStockAlerte)
    {
        InfoStockAlerte->setWindowTitle(QApplication::translate("InfoStockAlerte", "Modification du stock", 0));
        point_vente->setText(QApplication::translate("InfoStockAlerte", "TextLabel", 0));
        produit->setText(QString());
        label_2->setText(QApplication::translate("InfoStockAlerte", "Qte : ", 0));
        unite_m2->setText(QApplication::translate("InfoStockAlerte", "M2", 0));
        unite_carton->setText(QApplication::translate("InfoStockAlerte", "Carton", 0));
        unite_piece->setText(QApplication::translate("InfoStockAlerte", "Pi\303\250ce", 0));
        pushButton->setText(QApplication::translate("InfoStockAlerte", "Ajouter", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoStockAlerte: public Ui_InfoStockAlerte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOSTOCKALERTE_H
