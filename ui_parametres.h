/********************************************************************************
** Form generated from reading UI file 'parametres.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRES_H
#define UI_PARAMETRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Parametres
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *ets;
    QLineEdit *titre1;
    QLineEdit *titre2;
    QLineEdit *titre3;
    QLineEdit *titre4;
    QLineEdit *titre5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QCheckBox *checkBox;
    QLabel *label_banner;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Parametres)
    {
        if (Parametres->objectName().isEmpty())
            Parametres->setObjectName(QStringLiteral("Parametres"));
        Parametres->resize(383, 245);
        horizontalLayout_2 = new QHBoxLayout(Parametres);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(Parametres);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        ets = new QLineEdit(groupBox);
        ets->setObjectName(QStringLiteral("ets"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ets);

        titre1 = new QLineEdit(groupBox);
        titre1->setObjectName(QStringLiteral("titre1"));

        formLayout->setWidget(1, QFormLayout::FieldRole, titre1);

        titre2 = new QLineEdit(groupBox);
        titre2->setObjectName(QStringLiteral("titre2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, titre2);

        titre3 = new QLineEdit(groupBox);
        titre3->setObjectName(QStringLiteral("titre3"));

        formLayout->setWidget(3, QFormLayout::FieldRole, titre3);

        titre4 = new QLineEdit(groupBox);
        titre4->setObjectName(QStringLiteral("titre4"));

        formLayout->setWidget(4, QFormLayout::FieldRole, titre4);

        titre5 = new QLineEdit(groupBox);
        titre5->setObjectName(QStringLiteral("titre5"));

        formLayout->setWidget(5, QFormLayout::FieldRole, titre5);


        verticalLayout_5->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:8px;\n"
"border:none;"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_5->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(groupBox);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_2 = new QGroupBox(Parametres);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_3->addWidget(radioButton_4);

        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addWidget(groupBox_3);


        verticalLayout_4->addWidget(groupBox_2);

        checkBox = new QCheckBox(Parametres);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_4->addWidget(checkBox);

        label_banner = new QLabel(Parametres);
        label_banner->setObjectName(QStringLiteral("label_banner"));
        label_banner->setMinimumSize(QSize(150, 0));
        label_banner->setMaximumSize(QSize(150, 16777215));

        verticalLayout_4->addWidget(label_banner);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_4);


        retranslateUi(Parametres);

        QMetaObject::connectSlotsByName(Parametres);
    } // setupUi

    void retranslateUi(QDialog *Parametres)
    {
        Parametres->setWindowTitle(QApplication::translate("Parametres", "Param\303\250tres", 0));
        groupBox->setTitle(QApplication::translate("Parametres", "Ent\303\252te Facture", 0));
        label->setText(QApplication::translate("Parametres", "ETS", 0));
        label_2->setText(QApplication::translate("Parametres", "Titre 1", 0));
        label_3->setText(QApplication::translate("Parametres", "Titre 2", 0));
        label_4->setText(QApplication::translate("Parametres", "Titre 3", 0));
        label_5->setText(QApplication::translate("Parametres", "Titre 4", 0));
        label_6->setText(QApplication::translate("Parametres", "Titre 5", 0));
        pushButton->setText(QApplication::translate("Parametres", "Sauvegarder", 0));
        groupBox_2->setTitle(QApplication::translate("Parametres", "Impression Facture", 0));
        radioButton->setText(QApplication::translate("Parametres", "A4", 0));
        radioButton_2->setText(QApplication::translate("Parametres", "A5", 0));
        groupBox_3->setTitle(QString());
        radioButton_4->setText(QApplication::translate("Parametres", "Paysage", 0));
        radioButton_3->setText(QApplication::translate("Parametres", "Portrait", 0));
        checkBox->setText(QApplication::translate("Parametres", "Image en ent\303\252te", 0));
        label_banner->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Parametres: public Ui_Parametres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRES_H
