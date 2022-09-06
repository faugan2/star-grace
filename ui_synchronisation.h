/********************************************************************************
** Form generated from reading UI file 'synchronisation.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNCHRONISATION_H
#define UI_SYNCHRONISATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Synchronisation
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Synchronisation)
    {
        if (Synchronisation->objectName().isEmpty())
            Synchronisation->setObjectName(QStringLiteral("Synchronisation"));
        Synchronisation->resize(400, 163);
        verticalLayout = new QVBoxLayout(Synchronisation);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Synchronisation);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font-weight:bold;\n"
""));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Synchronisation);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        progressBar = new QProgressBar(Synchronisation);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        verticalLayout->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(Synchronisation);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("padding:8px;\n"
"background-color:indianred;\n"
"color:white;\n"
"border:none;"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(Synchronisation);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("padding:8px;\n"
"background-color:white;\n"
"border:none;"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Synchronisation);

        QMetaObject::connectSlotsByName(Synchronisation);
    } // setupUi

    void retranslateUi(QDialog *Synchronisation)
    {
        Synchronisation->setWindowTitle(QApplication::translate("Synchronisation", "Synchronisation des donn\303\251es", 0));
        label->setText(QApplication::translate("Synchronisation", "Vous \303\252tes sur le point de synchroniser les donn\303\251es", 0));
        label_2->setText(QApplication::translate("Synchronisation", "Cette op\303\251ration vous permettra de mettre \303\240 jour le serveur local et le serveur distant pour qu'ils contiennent les m\303\252mes donn\303\251es et faciliter le partage des informations avec d'autres utilisateurs du logiciel.", 0));
        pushButton_2->setText(QApplication::translate("Synchronisation", "Annuler", 0));
        pushButton->setText(QApplication::translate("Synchronisation", "Continuer", 0));
    } // retranslateUi

};

namespace Ui {
    class Synchronisation: public Ui_Synchronisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNCHRONISATION_H
