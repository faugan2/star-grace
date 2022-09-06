/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *identifiant;
    QLineEdit *password;
    QPushButton *pushButton;
    QCheckBox *serveur_distant;
    QLabel *alerte;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(336, 179);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/logo.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(Login);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(73, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setScaledContents(false);

        horizontalLayout->addWidget(label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font: 50 13pt \"MS Shell Dlg 2\";\n"
""));

        verticalLayout->addWidget(label);

        identifiant = new QLineEdit(Login);
        identifiant->setObjectName(QStringLiteral("identifiant"));
        identifiant->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(identifiant);

        password = new QLineEdit(Login);
        password->setObjectName(QStringLiteral("password"));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password);

        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color: white;\n"
"color:black;\n"
"border:none;\n"
"padding:8px;\n"
"font-weight:bold;\n"
"width:100px;"));

        verticalLayout->addWidget(pushButton);

        serveur_distant = new QCheckBox(Login);
        serveur_distant->setObjectName(QStringLiteral("serveur_distant"));

        verticalLayout->addWidget(serveur_distant);

        alerte = new QLabel(Login);
        alerte->setObjectName(QStringLiteral("alerte"));
        alerte->setStyleSheet(QLatin1String("text-align:center;\n"
"color: rgb(170, 0, 0);"));

        verticalLayout->addWidget(alerte);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(72, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Connexion", 0));
        label_2->setText(QString());
        label->setText(QApplication::translate("Login", "Connectez-vous", 0));
        identifiant->setPlaceholderText(QApplication::translate("Login", "Identifiant", 0));
        password->setPlaceholderText(QApplication::translate("Login", "Mot de passe", 0));
        pushButton->setText(QApplication::translate("Login", "Valider", 0));
        serveur_distant->setText(QApplication::translate("Login", "Utiliser le serveur distant", 0));
        alerte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
