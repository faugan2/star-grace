/********************************************************************************
** Form generated from reading UI file 'listeusers.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTEUSERS_H
#define UI_LISTEUSERS_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ListeUsers
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *search;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_droit;
    QPushButton *btn_edit;
    QPushButton *btn_del;
    QTableWidget *table_liste_users;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *type;
    QComboBox *point_vente;
    QLineEdit *nom;
    QLineEdit *login;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *alerte;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ListeUsers)
    {
        if (ListeUsers->objectName().isEmpty())
            ListeUsers->setObjectName(QStringLiteral("ListeUsers"));
        ListeUsers->resize(605, 300);
        ListeUsers->setMinimumSize(QSize(600, 0));
        horizontalLayout_3 = new QHBoxLayout(ListeUsers);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        search = new QLineEdit(ListeUsers);
        search->setObjectName(QStringLiteral("search"));

        horizontalLayout_2->addWidget(search);

        pushButton_2 = new QPushButton(ListeUsers);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/images/imprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_droit = new QPushButton(ListeUsers);
        btn_droit->setObjectName(QStringLiteral("btn_droit"));
        btn_droit->setAutoFillBackground(false);
        btn_droit->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/images/password.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_droit->setIcon(icon1);

        horizontalLayout_2->addWidget(btn_droit);

        btn_edit = new QPushButton(ListeUsers);
        btn_edit->setObjectName(QStringLiteral("btn_edit"));
        btn_edit->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_edit->setIcon(icon2);

        horizontalLayout_2->addWidget(btn_edit);

        btn_del = new QPushButton(ListeUsers);
        btn_del->setObjectName(QStringLiteral("btn_del"));
        btn_del->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/images/trash-outline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon3);

        horizontalLayout_2->addWidget(btn_del);


        verticalLayout_2->addLayout(horizontalLayout_2);

        table_liste_users = new QTableWidget(ListeUsers);
        if (table_liste_users->columnCount() < 5)
            table_liste_users->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_liste_users->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_liste_users->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_liste_users->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_liste_users->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_liste_users->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table_liste_users->setObjectName(QStringLiteral("table_liste_users"));
        table_liste_users->setGridStyle(Qt::DashDotDotLine);
        table_liste_users->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(table_liste_users);


        horizontalLayout_3->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(ListeUsers);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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

        type = new QComboBox(groupBox);
        type->setObjectName(QStringLiteral("type"));
        type->setEditable(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, type);

        point_vente = new QComboBox(groupBox);
        point_vente->setObjectName(QStringLiteral("point_vente"));
        point_vente->setEditable(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, point_vente);

        nom = new QLineEdit(groupBox);
        nom->setObjectName(QStringLiteral("nom"));

        formLayout->setWidget(2, QFormLayout::FieldRole, nom);

        login = new QLineEdit(groupBox);
        login->setObjectName(QStringLiteral("login"));

        formLayout->setWidget(3, QFormLayout::FieldRole, login);

        password = new QLineEdit(groupBox);
        password->setObjectName(QStringLiteral("password"));

        formLayout->setWidget(4, QFormLayout::FieldRole, password);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("border:none;\n"
"background-color:white;\n"
"padding:8px;"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        alerte = new QLabel(groupBox);
        alerte->setObjectName(QStringLiteral("alerte"));

        verticalLayout->addWidget(alerte);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(groupBox);


        retranslateUi(ListeUsers);

        QMetaObject::connectSlotsByName(ListeUsers);
    } // setupUi

    void retranslateUi(QDialog *ListeUsers)
    {
        ListeUsers->setWindowTitle(QApplication::translate("ListeUsers", "La liste des utilisateurs", 0));
        search->setPlaceholderText(QApplication::translate("ListeUsers", "Rechercher", 0));
        pushButton_2->setText(QString());
        btn_droit->setText(QString());
        btn_edit->setText(QString());
        btn_del->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_liste_users->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ListeUsers", "Nom", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_liste_users->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ListeUsers", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_liste_users->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ListeUsers", "Point de vente", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_liste_users->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ListeUsers", "Identifiant", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_liste_users->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ListeUsers", "Mot de passe", 0));
        groupBox->setTitle(QApplication::translate("ListeUsers", "Ajouter un utilisateur", 0));
        label->setText(QApplication::translate("ListeUsers", "Type", 0));
        label_2->setText(QApplication::translate("ListeUsers", "Point de vente", 0));
        label_3->setText(QApplication::translate("ListeUsers", "Nom", 0));
        label_4->setText(QApplication::translate("ListeUsers", "Identifiant", 0));
        label_5->setText(QApplication::translate("ListeUsers", "Mot de passe", 0));
        pushButton->setText(QApplication::translate("ListeUsers", "Ajouter", 0));
        alerte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListeUsers: public Ui_ListeUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTEUSERS_H
