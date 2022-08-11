/********************************************************************************
** Form generated from reading UI file 'listformat.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTFORMAT_H
#define UI_LISTFORMAT_H

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

class Ui_Listformat
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
    QLabel *lll;
    QLabel *label_3;
    QLineEdit *nom;
    QLineEdit *pieces_par_m2;
    QLineEdit *pieces_par_cartons;
    QLabel *label_4;
    QLineEdit *dimension;
    QLabel *label_2;
    QLineEdit *prix;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *alerte;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Listformat)
    {
        if (Listformat->objectName().isEmpty())
            Listformat->setObjectName(QStringLiteral("Listformat"));
        Listformat->resize(612, 300);
        horizontalLayout_3 = new QHBoxLayout(Listformat);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        search = new QLineEdit(Listformat);
        search->setObjectName(QStringLiteral("search"));

        horizontalLayout_2->addWidget(search);

        pushButton_2 = new QPushButton(Listformat);
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

        btn_edit = new QPushButton(Listformat);
        btn_edit->setObjectName(QStringLiteral("btn_edit"));
        btn_edit->setEnabled(false);
        btn_edit->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"padding:5px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_edit->setIcon(icon1);

        horizontalLayout_2->addWidget(btn_edit);

        btn_del = new QPushButton(Listformat);
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

        table_liste_point_vente = new QTableWidget(Listformat);
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
        table_liste_point_vente->setGridStyle(Qt::DashDotDotLine);

        verticalLayout_2->addWidget(table_liste_point_vente);


        horizontalLayout_3->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(Listformat);
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

        lll = new QLabel(groupBox);
        lll->setObjectName(QStringLiteral("lll"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lll);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        nom = new QLineEdit(groupBox);
        nom->setObjectName(QStringLiteral("nom"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nom);

        pieces_par_m2 = new QLineEdit(groupBox);
        pieces_par_m2->setObjectName(QStringLiteral("pieces_par_m2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pieces_par_m2);

        pieces_par_cartons = new QLineEdit(groupBox);
        pieces_par_cartons->setObjectName(QStringLiteral("pieces_par_cartons"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pieces_par_cartons);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        dimension = new QLineEdit(groupBox);
        dimension->setObjectName(QStringLiteral("dimension"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dimension);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        prix = new QLineEdit(groupBox);
        prix->setObjectName(QStringLiteral("prix"));

        formLayout->setWidget(4, QFormLayout::FieldRole, prix);


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


        retranslateUi(Listformat);

        QMetaObject::connectSlotsByName(Listformat);
    } // setupUi

    void retranslateUi(QDialog *Listformat)
    {
        Listformat->setWindowTitle(QApplication::translate("Listformat", "Formats de carreaux", 0));
        search->setPlaceholderText(QApplication::translate("Listformat", "Rechercher", 0));
        pushButton_2->setText(QString());
        btn_edit->setText(QString());
        btn_del->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_liste_point_vente->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Listformat", "Nom", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_liste_point_vente->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Listformat", "Pi\303\250ces/m2", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_liste_point_vente->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Listformat", "Pi\303\250ces/cartons", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_liste_point_vente->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Listformat", "Dimension en m2", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_liste_point_vente->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Listformat", "Prix", 0));
        groupBox->setTitle(QApplication::translate("Listformat", "Ajouter un format", 0));
        label->setText(QApplication::translate("Listformat", "Nom du format", 0));
        lll->setText(QApplication::translate("Listformat", "Pi\303\250ces par m2", 0));
        label_3->setText(QApplication::translate("Listformat", "Pi\303\250ces par cartons", 0));
        nom->setPlaceholderText(QApplication::translate("Listformat", "20x30", 0));
        pieces_par_m2->setPlaceholderText(QApplication::translate("Listformat", "16", 0));
        pieces_par_cartons->setPlaceholderText(QApplication::translate("Listformat", "25", 0));
        label_4->setText(QApplication::translate("Listformat", "Dimension en m2", 0));
        dimension->setPlaceholderText(QApplication::translate("Listformat", "1.5", 0));
        label_2->setText(QApplication::translate("Listformat", "Prix par m2", 0));
        pushButton->setText(QApplication::translate("Listformat", "Ajouter", 0));
        alerte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Listformat: public Ui_Listformat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTFORMAT_H
