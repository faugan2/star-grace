/********************************************************************************
** Form generated from reading UI file 'infoclient.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOCLIENT_H
#define UI_INFOCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *nom;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *contact;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *num_facture;
    QLabel *label_2;
    QLabel *date;
    QLabel *label_3;
    QLabel *montant;
    QLabel *label_4;
    QLabel *remise;
    QLabel *label_5;
    QLabel *montant_paye;
    QLabel *label_6;
    QLabel *reste;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;

    void setupUi(QDialog *InfoClient)
    {
        if (InfoClient->objectName().isEmpty())
            InfoClient->setObjectName(QStringLiteral("InfoClient"));
        InfoClient->resize(316, 248);
        verticalLayout_2 = new QVBoxLayout(InfoClient);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        nom = new QLabel(InfoClient);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setStyleSheet(QLatin1String("font-weight:bold;\n"
""));

        horizontalLayout_2->addWidget(nom);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        contact = new QLabel(InfoClient);
        contact->setObjectName(QStringLiteral("contact"));
        contact->setStyleSheet(QStringLiteral("font-weight:bold;"));

        horizontalLayout->addWidget(contact);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox = new QGroupBox(InfoClient);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        num_facture = new QLabel(groupBox);
        num_facture->setObjectName(QStringLiteral("num_facture"));
        num_facture->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, num_facture);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        date = new QLabel(groupBox);
        date->setObjectName(QStringLiteral("date"));
        date->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, date);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        montant = new QLabel(groupBox);
        montant->setObjectName(QStringLiteral("montant"));
        montant->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, montant);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        remise = new QLabel(groupBox);
        remise->setObjectName(QStringLiteral("remise"));
        remise->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, remise);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        montant_paye = new QLabel(groupBox);
        montant_paye->setObjectName(QStringLiteral("montant_paye"));
        montant_paye->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, montant_paye);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        reste = new QLabel(groupBox);
        reste->setObjectName(QStringLiteral("reste"));
        reste->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, reste);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:8px;\n"
"border:none;"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(InfoClient);

        QMetaObject::connectSlotsByName(InfoClient);
    } // setupUi

    void retranslateUi(QDialog *InfoClient)
    {
        InfoClient->setWindowTitle(QApplication::translate("InfoClient", "Informations sur le client", 0));
        nom->setText(QString());
        contact->setText(QString());
        groupBox->setTitle(QApplication::translate("InfoClient", "Facture Impay\303\251e", 0));
        label->setText(QApplication::translate("InfoClient", "N\302\260 Facture", 0));
        num_facture->setText(QString());
        label_2->setText(QApplication::translate("InfoClient", "Date", 0));
        date->setText(QString());
        label_3->setText(QApplication::translate("InfoClient", "Montant", 0));
        montant->setText(QString());
        label_4->setText(QApplication::translate("InfoClient", "Remise", 0));
        remise->setText(QString());
        label_5->setText(QApplication::translate("InfoClient", "Montant pay\303\251", 0));
        montant_paye->setText(QString());
        label_6->setText(QApplication::translate("InfoClient", "Restant \303\240 payer", 0));
        reste->setText(QString());
        pushButton->setText(QApplication::translate("InfoClient", "Sold\303\251", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoClient: public Ui_InfoClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOCLIENT_H
