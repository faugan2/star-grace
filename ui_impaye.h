/********************************************************************************
** Form generated from reading UI file 'impaye.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPAYE_H
#define UI_IMPAYE_H

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

class Ui_Impaye
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *montant_facture;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *a_payer;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *reste;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;

    void setupUi(QDialog *Impaye)
    {
        if (Impaye->objectName().isEmpty())
            Impaye->setObjectName(QStringLiteral("Impaye"));
        Impaye->resize(245, 171);
        verticalLayout_3 = new QVBoxLayout(Impaye);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        montant_facture = new QLabel(Impaye);
        montant_facture->setObjectName(QStringLiteral("montant_facture"));

        horizontalLayout->addWidget(montant_facture);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(Impaye);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        a_payer = new QLineEdit(Impaye);
        a_payer->setObjectName(QStringLiteral("a_payer"));

        verticalLayout_2->addWidget(a_payer);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(Impaye);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        reste = new QLineEdit(Impaye);
        reste->setObjectName(QStringLiteral("reste"));
        reste->setEnabled(false);

        verticalLayout->addWidget(reste);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(Impaye);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:8px;\n"
"border:none;"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Impaye);

        QMetaObject::connectSlotsByName(Impaye);
    } // setupUi

    void retranslateUi(QDialog *Impaye)
    {
        Impaye->setWindowTitle(QApplication::translate("Impaye", "Impay\303\251", 0));
        montant_facture->setText(QString());
        label->setText(QApplication::translate("Impaye", "A payer", 0));
        label_2->setText(QApplication::translate("Impaye", "Restant", 0));
        pushButton->setText(QApplication::translate("Impaye", "Valider", 0));
    } // retranslateUi

};

namespace Ui {
    class Impaye: public Ui_Impaye {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPAYE_H
