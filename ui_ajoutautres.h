/********************************************************************************
** Form generated from reading UI file 'ajoutautres.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTAUTRES_H
#define UI_AJOUTAUTRES_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AjoutAutres
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *search;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_modif_stock;
    QPushButton *btn_edit;
    QPushButton *btn_del;
    QTableWidget *table_liste_point_vente;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nom;
    QLabel *label_3;
    QLineEdit *prix_par_m2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *alerte;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AjoutAutres)
    {
        if (AjoutAutres->objectName().isEmpty())
            AjoutAutres->setObjectName(QStringLiteral("AjoutAutres"));
        AjoutAutres->resize(610, 300);
        horizontalLayout_3 = new QHBoxLayout(AjoutAutres);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        search = new QLineEdit(AjoutAutres);
        search->setObjectName(QStringLiteral("search"));

        horizontalLayout_2->addWidget(search);

        pushButton_2 = new QPushButton(AjoutAutres);
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

        btn_modif_stock = new QPushButton(AjoutAutres);
        btn_modif_stock->setObjectName(QStringLiteral("btn_modif_stock"));
        btn_modif_stock->setEnabled(false);
        btn_modif_stock->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/images/ellipsis-horizontal-circle-outline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_modif_stock->setIcon(icon1);

        horizontalLayout_2->addWidget(btn_modif_stock);

        btn_edit = new QPushButton(AjoutAutres);
        btn_edit->setObjectName(QStringLiteral("btn_edit"));
        btn_edit->setEnabled(false);
        btn_edit->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_edit->setIcon(icon2);

        horizontalLayout_2->addWidget(btn_edit);

        btn_del = new QPushButton(AjoutAutres);
        btn_del->setObjectName(QStringLiteral("btn_del"));
        btn_del->setEnabled(false);
        btn_del->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/images/trash-outline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon3);

        horizontalLayout_2->addWidget(btn_del);


        verticalLayout_2->addLayout(horizontalLayout_2);

        table_liste_point_vente = new QTableWidget(AjoutAutres);
        if (table_liste_point_vente->columnCount() < 2)
            table_liste_point_vente->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table_liste_point_vente->setObjectName(QStringLiteral("table_liste_point_vente"));
        table_liste_point_vente->setGridStyle(Qt::DashDotDotLine);

        verticalLayout_2->addWidget(table_liste_point_vente);


        horizontalLayout_3->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(AjoutAutres);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nom = new QLineEdit(groupBox);
        nom->setObjectName(QStringLiteral("nom"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nom);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        prix_par_m2 = new QLineEdit(groupBox);
        prix_par_m2->setObjectName(QStringLiteral("prix_par_m2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, prix_par_m2);


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


        retranslateUi(AjoutAutres);

        QMetaObject::connectSlotsByName(AjoutAutres);
    } // setupUi

    void retranslateUi(QDialog *AjoutAutres)
    {
        AjoutAutres->setWindowTitle(QApplication::translate("AjoutAutres", "Autres produits", 0));
        search->setPlaceholderText(QApplication::translate("AjoutAutres", "Rechercher", 0));
        pushButton_2->setText(QString());
        btn_modif_stock->setText(QString());
        btn_edit->setText(QString());
        btn_del->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_liste_point_vente->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AjoutAutres", "Nom", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_liste_point_vente->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AjoutAutres", "Prix unitaire", 0));
        groupBox->setTitle(QApplication::translate("AjoutAutres", "Ajouter un produit", 0));
        label->setText(QApplication::translate("AjoutAutres", "Nom du produit", 0));
        nom->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("AjoutAutres", "Prix unitaire", 0));
        prix_par_m2->setPlaceholderText(QApplication::translate("AjoutAutres", "25", 0));
        pushButton->setText(QApplication::translate("AjoutAutres", "Ajouter", 0));
        alerte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AjoutAutres: public Ui_AjoutAutres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTAUTRES_H
