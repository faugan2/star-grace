/********************************************************************************
** Form generated from reading UI file 'droits.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROITS_H
#define UI_DROITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Droits
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *droit_transfert;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *droit_depenses;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *droit_bris;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *droit_retrait;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *droit_vente;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *droit_print_facture;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *droit_print_bon;
    QSpacerItem *horizontalSpacer_12;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *droit_point_vente;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *droit_utilisateurs;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *droit_clients;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *droit_stock;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton;

    void setupUi(QDialog *Droits)
    {
        if (Droits->objectName().isEmpty())
            Droits->setObjectName(QStringLiteral("Droits"));
        Droits->resize(377, 239);
        verticalLayout_3 = new QVBoxLayout(Droits);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        droit_transfert = new QCheckBox(Droits);
        droit_transfert->setObjectName(QStringLiteral("droit_transfert"));

        horizontalLayout->addWidget(droit_transfert);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        droit_depenses = new QCheckBox(Droits);
        droit_depenses->setObjectName(QStringLiteral("droit_depenses"));

        horizontalLayout_4->addWidget(droit_depenses);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        droit_bris = new QCheckBox(Droits);
        droit_bris->setObjectName(QStringLiteral("droit_bris"));

        horizontalLayout_3->addWidget(droit_bris);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        droit_retrait = new QCheckBox(Droits);
        droit_retrait->setObjectName(QStringLiteral("droit_retrait"));

        horizontalLayout_2->addWidget(droit_retrait);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        droit_vente = new QCheckBox(Droits);
        droit_vente->setObjectName(QStringLiteral("droit_vente"));

        horizontalLayout_9->addWidget(droit_vente);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        droit_print_facture = new QCheckBox(Droits);
        droit_print_facture->setObjectName(QStringLiteral("droit_print_facture"));

        horizontalLayout_11->addWidget(droit_print_facture);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        droit_print_bon = new QCheckBox(Droits);
        droit_print_bon->setObjectName(QStringLiteral("droit_print_bon"));

        horizontalLayout_12->addWidget(droit_print_bon);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_12);


        horizontalLayout_13->addLayout(verticalLayout);

        line = new QFrame(Droits);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_13->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        droit_point_vente = new QCheckBox(Droits);
        droit_point_vente->setObjectName(QStringLiteral("droit_point_vente"));

        horizontalLayout_8->addWidget(droit_point_vente);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        droit_utilisateurs = new QCheckBox(Droits);
        droit_utilisateurs->setObjectName(QStringLiteral("droit_utilisateurs"));

        horizontalLayout_7->addWidget(droit_utilisateurs);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        droit_clients = new QCheckBox(Droits);
        droit_clients->setObjectName(QStringLiteral("droit_clients"));

        horizontalLayout_6->addWidget(droit_clients);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        droit_stock = new QCheckBox(Droits);
        droit_stock->setObjectName(QStringLiteral("droit_stock"));

        horizontalLayout_5->addWidget(droit_stock);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_13->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);

        pushButton = new QPushButton(Droits);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_10->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_10);


        retranslateUi(Droits);

        QMetaObject::connectSlotsByName(Droits);
    } // setupUi

    void retranslateUi(QDialog *Droits)
    {
        Droits->setWindowTitle(QApplication::translate("Droits", "Droits de l'utilisateur", 0));
        droit_transfert->setText(QApplication::translate("Droits", "Transfert", 0));
        droit_depenses->setText(QApplication::translate("Droits", "D\303\251penses", 0));
        droit_bris->setText(QApplication::translate("Droits", "Bris de carreaux", 0));
        droit_retrait->setText(QApplication::translate("Droits", "Retrait du DG", 0));
        droit_vente->setText(QApplication::translate("Droits", "Effectuer une vente", 0));
        droit_print_facture->setText(QApplication::translate("Droits", "Imprmer les factures", 0));
        droit_print_bon->setText(QApplication::translate("Droits", "Imprimer les bons", 0));
        droit_point_vente->setText(QApplication::translate("Droits", "Points de vente", 0));
        droit_utilisateurs->setText(QApplication::translate("Droits", "Utilisateurs", 0));
        droit_clients->setText(QApplication::translate("Droits", "Clients", 0));
        droit_stock->setText(QApplication::translate("Droits", "Stock", 0));
        pushButton->setText(QApplication::translate("Droits", "Valider", 0));
    } // retranslateUi

};

namespace Ui {
    class Droits: public Ui_Droits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROITS_H
