/********************************************************************************
** Form generated from reading UI file 'loading.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_H
#define UI_LOADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Loading
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLabel *status;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_commencer;
    QPushButton *btn_terminer;

    void setupUi(QDialog *Loading)
    {
        if (Loading->objectName().isEmpty())
            Loading->setObjectName(QStringLiteral("Loading"));
        Loading->setEnabled(true);
        Loading->resize(313, 200);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/logo-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        Loading->setWindowIcon(icon);
        Loading->setAutoFillBackground(false);
        Loading->setStyleSheet(QStringLiteral(""));
        Loading->setModal(true);
        verticalLayout = new QVBoxLayout(Loading);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(Loading);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        status = new QLabel(Loading);
        status->setObjectName(QStringLiteral("status"));

        horizontalLayout->addWidget(status);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_commencer = new QPushButton(Loading);
        btn_commencer->setObjectName(QStringLiteral("btn_commencer"));
        btn_commencer->setStyleSheet(QStringLiteral("padding:5px;"));

        horizontalLayout->addWidget(btn_commencer);

        btn_terminer = new QPushButton(Loading);
        btn_terminer->setObjectName(QStringLiteral("btn_terminer"));
        btn_terminer->setEnabled(false);
        btn_terminer->setStyleSheet(QLatin1String("padding:5px;\n"
""));

        horizontalLayout->addWidget(btn_terminer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Loading);

        QMetaObject::connectSlotsByName(Loading);
    } // setupUi

    void retranslateUi(QDialog *Loading)
    {
        Loading->setWindowTitle(QApplication::translate("Loading", "Synchronisation des donn\303\251es", 0));
        status->setText(QString());
        btn_commencer->setText(QApplication::translate("Loading", "Commencer", 0));
        btn_terminer->setText(QApplication::translate("Loading", "Terminer", 0));
    } // retranslateUi

};

namespace Ui {
    class Loading: public Ui_Loading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_H
