/********************************************************************************
** Form generated from reading UI file 'infopointdevente.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOPOINTDEVENTE_H
#define UI_INFOPOINTDEVENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoPointDeVente
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *table_produits;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *unite_carton;
    QRadioButton *unite_m2;
    QRadioButton *unite_piece;
    QPushButton *btn_modifier_stock;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_adresse;
    QLabel *label_responsable;
    QLabel *label_contact;
    QLabel *label;
    QTableWidget *table_users;

    void setupUi(QDialog *InfoPointDeVente)
    {
        if (InfoPointDeVente->objectName().isEmpty())
            InfoPointDeVente->setObjectName(QStringLiteral("InfoPointDeVente"));
        InfoPointDeVente->resize(654, 300);
        horizontalLayout_2 = new QHBoxLayout(InfoPointDeVente);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(InfoPointDeVente);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        table_produits = new QTableWidget(groupBox);
        if (table_produits->columnCount() < 3)
            table_produits->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_produits->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_produits->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_produits->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table_produits->setObjectName(QStringLiteral("table_produits"));
        table_produits->setGridStyle(Qt::DashDotDotLine);
        table_produits->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(table_produits);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        unite_carton = new QRadioButton(groupBox);
        unite_carton->setObjectName(QStringLiteral("unite_carton"));
        unite_carton->setChecked(true);

        horizontalLayout->addWidget(unite_carton);

        unite_m2 = new QRadioButton(groupBox);
        unite_m2->setObjectName(QStringLiteral("unite_m2"));

        horizontalLayout->addWidget(unite_m2);

        unite_piece = new QRadioButton(groupBox);
        unite_piece->setObjectName(QStringLiteral("unite_piece"));

        horizontalLayout->addWidget(unite_piece);

        btn_modifier_stock = new QPushButton(groupBox);
        btn_modifier_stock->setObjectName(QStringLiteral("btn_modifier_stock"));
        btn_modifier_stock->setEnabled(false);
        btn_modifier_stock->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:8px;"));

        horizontalLayout->addWidget(btn_modifier_stock);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(InfoPointDeVente);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_adresse = new QLabel(groupBox_2);
        label_adresse->setObjectName(QStringLiteral("label_adresse"));
        label_adresse->setStyleSheet(QLatin1String("font-size:10px;\n"
"font-weight:bold;"));

        verticalLayout->addWidget(label_adresse);

        label_responsable = new QLabel(groupBox_2);
        label_responsable->setObjectName(QStringLiteral("label_responsable"));
        label_responsable->setStyleSheet(QStringLiteral("font-size:10px;"));

        verticalLayout->addWidget(label_responsable);

        label_contact = new QLabel(groupBox_2);
        label_contact->setObjectName(QStringLiteral("label_contact"));
        label_contact->setStyleSheet(QStringLiteral("font-size:10px;"));

        verticalLayout->addWidget(label_contact);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        table_users = new QTableWidget(groupBox_2);
        if (table_users->columnCount() < 3)
            table_users->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_users->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_users->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_users->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        table_users->setObjectName(QStringLiteral("table_users"));
        table_users->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_users->setGridStyle(Qt::DashDotDotLine);

        verticalLayout->addWidget(table_users);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(groupBox_2);


        retranslateUi(InfoPointDeVente);

        QMetaObject::connectSlotsByName(InfoPointDeVente);
    } // setupUi

    void retranslateUi(QDialog *InfoPointDeVente)
    {
        InfoPointDeVente->setWindowTitle(QApplication::translate("InfoPointDeVente", "Informations sur le point de vente", 0));
        groupBox->setTitle(QApplication::translate("InfoPointDeVente", "Stock", 0));
        QTableWidgetItem *___qtablewidgetitem = table_produits->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InfoPointDeVente", "Produit", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_produits->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InfoPointDeVente", "En Stock", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_produits->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("InfoPointDeVente", "Ajouter", 0));
        unite_carton->setText(QApplication::translate("InfoPointDeVente", "Carton", 0));
        unite_m2->setText(QApplication::translate("InfoPointDeVente", "M2", 0));
        unite_piece->setText(QApplication::translate("InfoPointDeVente", "Pi\303\250ce", 0));
        btn_modifier_stock->setText(QApplication::translate("InfoPointDeVente", "Modifier", 0));
        groupBox_2->setTitle(QApplication::translate("InfoPointDeVente", "A propos", 0));
        label_adresse->setText(QApplication::translate("InfoPointDeVente", "Point de vente", 0));
        label_responsable->setText(QApplication::translate("InfoPointDeVente", "Responsable", 0));
        label_contact->setText(QApplication::translate("InfoPointDeVente", "Contact", 0));
        label->setText(QApplication::translate("InfoPointDeVente", "Liste des utilisateurs", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_users->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("InfoPointDeVente", "Nom", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_users->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("InfoPointDeVente", "Identifiant", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_users->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("InfoPointDeVente", "Mot de passe", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoPointDeVente: public Ui_InfoPointDeVente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOPOINTDEVENTE_H
