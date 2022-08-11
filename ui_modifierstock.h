/********************************************************************************
** Form generated from reading UI file 'modifierstock.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERSTOCK_H
#define UI_MODIFIERSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_ModifierStock
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *ajouter;
    QRadioButton *retirer;
    QComboBox *magazin;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *qte;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ModifierStock)
    {
        if (ModifierStock->objectName().isEmpty())
            ModifierStock->setObjectName(QStringLiteral("ModifierStock"));
        ModifierStock->resize(525, 139);
        verticalLayout_2 = new QVBoxLayout(ModifierStock);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(ModifierStock);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ajouter = new QRadioButton(groupBox);
        ajouter->setObjectName(QStringLiteral("ajouter"));

        horizontalLayout->addWidget(ajouter);

        retirer = new QRadioButton(groupBox);
        retirer->setObjectName(QStringLiteral("retirer"));

        horizontalLayout->addWidget(retirer);


        verticalLayout->addLayout(horizontalLayout);

        magazin = new QComboBox(groupBox);
        magazin->setObjectName(QStringLiteral("magazin"));

        verticalLayout->addWidget(magazin);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        qte = new QLineEdit(groupBox);
        qte->setObjectName(QStringLiteral("qte"));

        horizontalLayout_2->addWidget(qte);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        magazin->raise();

        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ModifierStock);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_2);


        verticalLayout_3->addLayout(formLayout);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(ModifierStock);

        QMetaObject::connectSlotsByName(ModifierStock);
    } // setupUi

    void retranslateUi(QDialog *ModifierStock)
    {
        ModifierStock->setWindowTitle(QApplication::translate("ModifierStock", "Modification du stock", 0));
        groupBox->setTitle(QApplication::translate("ModifierStock", "Modifier le stock", 0));
        ajouter->setText(QApplication::translate("ModifierStock", "Ajouter", 0));
        retirer->setText(QApplication::translate("ModifierStock", "Retirer", 0));
        qte->setPlaceholderText(QApplication::translate("ModifierStock", "Quantit\303\251", 0));
        pushButton->setText(QApplication::translate("ModifierStock", "Valider", 0));
        groupBox_2->setTitle(QApplication::translate("ModifierStock", "Autres parametrages", 0));
        label_2->setText(QApplication::translate("ModifierStock", "Stock d'alerte", 0));
    } // retranslateUi

};

namespace Ui {
    class ModifierStock: public Ui_ModifierStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERSTOCK_H
