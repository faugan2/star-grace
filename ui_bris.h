/********************************************************************************
** Form generated from reading UI file 'bris.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIS_H
#define UI_BRIS_H

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

class Ui_Bris
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *search;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_edit;
    QPushButton *btn_del;
    QTableWidget *table_liste_point_vente;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *pieces_cassees;
    QLineEdit *lot_obtenu;
    QComboBox *produit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *alerte;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Bris)
    {
        if (Bris->objectName().isEmpty())
            Bris->setObjectName(QStringLiteral("Bris"));
        Bris->resize(598, 300);
        horizontalLayout_3 = new QHBoxLayout(Bris);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        search = new QLineEdit(Bris);
        search->setObjectName(QStringLiteral("search"));
        search->setEnabled(true);

        horizontalLayout_2->addWidget(search);

        pushButton_2 = new QPushButton(Bris);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/images/imprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_edit = new QPushButton(Bris);
        btn_edit->setObjectName(QStringLiteral("btn_edit"));
        btn_edit->setEnabled(false);
        btn_edit->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_edit->setIcon(icon1);

        horizontalLayout_2->addWidget(btn_edit);

        btn_del = new QPushButton(Bris);
        btn_del->setObjectName(QStringLiteral("btn_del"));
        btn_del->setEnabled(false);
        btn_del->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/images/trash-outline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon2);

        horizontalLayout_2->addWidget(btn_del);


        verticalLayout_2->addLayout(horizontalLayout_2);

        table_liste_point_vente = new QTableWidget(Bris);
        if (table_liste_point_vente->columnCount() < 4)
            table_liste_point_vente->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_liste_point_vente->setObjectName(QStringLiteral("table_liste_point_vente"));
        table_liste_point_vente->setGridStyle(Qt::DashDotDotLine);

        verticalLayout_2->addWidget(table_liste_point_vente);


        horizontalLayout_3->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(Bris);
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

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        pieces_cassees = new QLineEdit(groupBox);
        pieces_cassees->setObjectName(QStringLiteral("pieces_cassees"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pieces_cassees);

        lot_obtenu = new QLineEdit(groupBox);
        lot_obtenu->setObjectName(QStringLiteral("lot_obtenu"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lot_obtenu);

        produit = new QComboBox(groupBox);
        produit->setObjectName(QStringLiteral("produit"));
        produit->setEditable(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, produit);


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


        retranslateUi(Bris);

        QMetaObject::connectSlotsByName(Bris);
    } // setupUi

    void retranslateUi(QDialog *Bris)
    {
        Bris->setWindowTitle(QApplication::translate("Bris", "Bris de carreaux", 0));
        search->setPlaceholderText(QApplication::translate("Bris", "Rechercher", 0));
        pushButton_2->setText(QString());
        btn_edit->setText(QString());
        btn_del->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_liste_point_vente->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Bris", "Dates", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_liste_point_vente->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Bris", "Carreaux", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_liste_point_vente->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Bris", "Pi\303\250ces cass\303\251es", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_liste_point_vente->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Bris", "Lots obtenus", 0));
        groupBox->setTitle(QApplication::translate("Bris", "Gestion de bris", 0));
        label->setText(QApplication::translate("Bris", "Carreaux", 0));
        label_2->setText(QApplication::translate("Bris", "Pi\303\250ces cass\303\251es", 0));
        label_3->setText(QApplication::translate("Bris", "Lots obtenus", 0));
        pieces_cassees->setPlaceholderText(QApplication::translate("Bris", "12", 0));
        lot_obtenu->setPlaceholderText(QApplication::translate("Bris", "2", 0));
        pushButton->setText(QApplication::translate("Bris", "Ajouter", 0));
        alerte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Bris: public Ui_Bris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIS_H
