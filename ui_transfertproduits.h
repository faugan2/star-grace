/********************************************************************************
** Form generated from reading UI file 'transfertproduits.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERTPRODUITS_H
#define UI_TRANSFERTPRODUITS_H

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

class Ui_TransfertProduits
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *search;
    QPushButton *btn_print;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_edit;
    QPushButton *btn_del;
    QTableWidget *table_liste_point_vente;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *du;
    QLabel *label_2;
    QComboBox *a;
    QTableWidget *table_produits;
    QLabel *qte_en_stock;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *alerte;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *TransfertProduits)
    {
        if (TransfertProduits->objectName().isEmpty())
            TransfertProduits->setObjectName(QStringLiteral("TransfertProduits"));
        TransfertProduits->resize(608, 300);
        horizontalLayout_3 = new QHBoxLayout(TransfertProduits);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        search = new QLineEdit(TransfertProduits);
        search->setObjectName(QStringLiteral("search"));

        horizontalLayout_2->addWidget(search);

        btn_print = new QPushButton(TransfertProduits);
        btn_print->setObjectName(QStringLiteral("btn_print"));
        btn_print->setEnabled(true);
        btn_print->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/images/imprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_print->setIcon(icon);

        horizontalLayout_2->addWidget(btn_print);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_edit = new QPushButton(TransfertProduits);
        btn_edit->setObjectName(QStringLiteral("btn_edit"));
        btn_edit->setEnabled(false);
        btn_edit->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_edit->setIcon(icon1);

        horizontalLayout_2->addWidget(btn_edit);

        btn_del = new QPushButton(TransfertProduits);
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

        table_liste_point_vente = new QTableWidget(TransfertProduits);
        if (table_liste_point_vente->columnCount() < 5)
            table_liste_point_vente->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_liste_point_vente->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table_liste_point_vente->setObjectName(QStringLiteral("table_liste_point_vente"));
        table_liste_point_vente->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_liste_point_vente->setGridStyle(Qt::DashDotDotLine);
        table_liste_point_vente->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(table_liste_point_vente);


        horizontalLayout_3->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(TransfertProduits);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(250, 0));
        groupBox->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        du = new QComboBox(groupBox);
        du->setObjectName(QStringLiteral("du"));
        du->setEditable(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, du);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        a = new QComboBox(groupBox);
        a->setObjectName(QStringLiteral("a"));
        a->setEditable(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, a);


        verticalLayout->addLayout(formLayout);

        table_produits = new QTableWidget(groupBox);
        if (table_produits->columnCount() < 3)
            table_produits->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_produits->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_produits->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_produits->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        table_produits->setObjectName(QStringLiteral("table_produits"));
        table_produits->setMinimumSize(QSize(0, 150));
        table_produits->setShowGrid(true);
        table_produits->setGridStyle(Qt::DashDotDotLine);
        table_produits->setWordWrap(true);
        table_produits->horizontalHeader()->setStretchLastSection(true);
        table_produits->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(table_produits);

        qte_en_stock = new QLabel(groupBox);
        qte_en_stock->setObjectName(QStringLiteral("qte_en_stock"));

        verticalLayout->addWidget(qte_en_stock);

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


        retranslateUi(TransfertProduits);

        QMetaObject::connectSlotsByName(TransfertProduits);
    } // setupUi

    void retranslateUi(QDialog *TransfertProduits)
    {
        TransfertProduits->setWindowTitle(QApplication::translate("TransfertProduits", "Transfert de produits", 0));
        search->setPlaceholderText(QApplication::translate("TransfertProduits", "Rechercher", 0));
        btn_print->setText(QString());
        btn_edit->setText(QString());
        btn_del->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_liste_point_vente->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TransfertProduits", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_liste_point_vente->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TransfertProduits", "Produuit", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_liste_point_vente->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TransfertProduits", "Qte en crt", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_liste_point_vente->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TransfertProduits", "Du", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_liste_point_vente->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("TransfertProduits", "A", 0));
        groupBox->setTitle(QApplication::translate("TransfertProduits", "Effectuer un transfert", 0));
        label->setText(QApplication::translate("TransfertProduits", "Du", 0));
        label_2->setText(QApplication::translate("TransfertProduits", "A", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_produits->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("TransfertProduits", "Produits", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_produits->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("TransfertProduits", "Crt", 0));
        QTableWidgetItem *___qtablewidgetitem7 = table_produits->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("TransfertProduits", "Pcs", 0));
        qte_en_stock->setText(QString());
        pushButton->setText(QApplication::translate("TransfertProduits", "Valider", 0));
        alerte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TransfertProduits: public Ui_TransfertProduits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERTPRODUITS_H
