/********************************************************************************
** Form generated from reading UI file 'biz.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIZ_H
#define UI_BIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Biz
{
public:
    QVBoxLayout *verticalLayout_5;
    QComboBox *produits;
    QGroupBox *options;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *qte;
    QLabel *label_2;
    QLineEdit *qte_biz;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *prix;
    QLabel *label_4;
    QLineEdit *prix_biz;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *total;
    QLabel *label_6;
    QLineEdit *total_biz;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Biz)
    {
        if (Biz->objectName().isEmpty())
            Biz->setObjectName(QStringLiteral("Biz"));
        Biz->resize(341, 255);
        Biz->setSizeGripEnabled(false);
        verticalLayout_5 = new QVBoxLayout(Biz);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        produits = new QComboBox(Biz);
        produits->setObjectName(QStringLiteral("produits"));
        produits->setEditable(true);

        verticalLayout_5->addWidget(produits);

        options = new QGroupBox(Biz);
        options->setObjectName(QStringLiteral("options"));
        verticalLayout_4 = new QVBoxLayout(options);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(options);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qte = new QLineEdit(options);
        qte->setObjectName(QStringLiteral("qte"));
        qte->setEnabled(false);

        horizontalLayout->addWidget(qte);

        label_2 = new QLabel(options);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        qte_biz = new QLineEdit(options);
        qte_biz->setObjectName(QStringLiteral("qte_biz"));

        horizontalLayout->addWidget(qte_biz);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(options);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        prix = new QLineEdit(options);
        prix->setObjectName(QStringLiteral("prix"));
        prix->setEnabled(false);

        horizontalLayout_2->addWidget(prix);

        label_4 = new QLabel(options);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        prix_biz = new QLineEdit(options);
        prix_biz->setObjectName(QStringLiteral("prix_biz"));

        horizontalLayout_2->addWidget(prix_biz);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(options);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        total = new QLineEdit(options);
        total->setObjectName(QStringLiteral("total"));
        total->setEnabled(false);

        horizontalLayout_3->addWidget(total);

        label_6 = new QLabel(options);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        total_biz = new QLineEdit(options);
        total_biz->setObjectName(QStringLiteral("total_biz"));
        total_biz->setEnabled(false);

        horizontalLayout_3->addWidget(total_biz);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(options);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:8px;"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_5->addWidget(options);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        retranslateUi(Biz);

        QMetaObject::connectSlotsByName(Biz);
    } // setupUi

    void retranslateUi(QDialog *Biz)
    {
        Biz->setWindowTitle(QApplication::translate("Biz", "Gestion de biz", 0));
        options->setTitle(QApplication::translate("Biz", "Affichage sur la facture", 0));
        label->setText(QApplication::translate("Biz", "Quantit\303\251", 0));
        label_2->setText(QApplication::translate("Biz", "=>", 0));
        label_3->setText(QApplication::translate("Biz", "Prix par m2", 0));
        label_4->setText(QApplication::translate("Biz", "= >", 0));
        label_5->setText(QApplication::translate("Biz", "Total", 0));
        label_6->setText(QApplication::translate("Biz", "= >", 0));
        pushButton->setText(QApplication::translate("Biz", "Valider", 0));
    } // retranslateUi

};

namespace Ui {
    class Biz: public Ui_Biz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIZ_H
