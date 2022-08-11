/********************************************************************************
** Form generated from reading UI file 'ajouterpointdevente.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERPOINTDEVENTE_H
#define UI_AJOUTERPOINTDEVENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AjouterPointDeVente
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *adresse;
    QLineEdit *responsable;
    QLineEdit *contact;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *alerte;

    void setupUi(QDialog *AjouterPointDeVente)
    {
        if (AjouterPointDeVente->objectName().isEmpty())
            AjouterPointDeVente->setObjectName(QStringLiteral("AjouterPointDeVente"));
        AjouterPointDeVente->resize(400, 148);
        AjouterPointDeVente->setMinimumSize(QSize(400, 0));
        verticalLayout = new QVBoxLayout(AjouterPointDeVente);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(AjouterPointDeVente);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(AjouterPointDeVente);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(AjouterPointDeVente);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        adresse = new QLineEdit(AjouterPointDeVente);
        adresse->setObjectName(QStringLiteral("adresse"));

        formLayout->setWidget(0, QFormLayout::FieldRole, adresse);

        responsable = new QLineEdit(AjouterPointDeVente);
        responsable->setObjectName(QStringLiteral("responsable"));

        formLayout->setWidget(1, QFormLayout::FieldRole, responsable);

        contact = new QLineEdit(AjouterPointDeVente);
        contact->setObjectName(QStringLiteral("contact"));

        formLayout->setWidget(2, QFormLayout::FieldRole, contact);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(AjouterPointDeVente);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:8;\n"
"color:black;"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        alerte = new QLabel(AjouterPointDeVente);
        alerte->setObjectName(QStringLiteral("alerte"));

        verticalLayout->addWidget(alerte);


        retranslateUi(AjouterPointDeVente);

        QMetaObject::connectSlotsByName(AjouterPointDeVente);
    } // setupUi

    void retranslateUi(QDialog *AjouterPointDeVente)
    {
        AjouterPointDeVente->setWindowTitle(QApplication::translate("AjouterPointDeVente", "Ajouter un point de vente", 0));
        label->setText(QApplication::translate("AjouterPointDeVente", "Adresse", 0));
        label_2->setText(QApplication::translate("AjouterPointDeVente", "Responsable", 0));
        label_3->setText(QApplication::translate("AjouterPointDeVente", "Contact", 0));
        pushButton->setText(QApplication::translate("AjouterPointDeVente", "Valider", 0));
        alerte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AjouterPointDeVente: public Ui_AjouterPointDeVente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERPOINTDEVENTE_H
