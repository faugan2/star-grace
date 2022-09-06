/********************************************************************************
** Form generated from reading UI file 'facture.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACTURE_H
#define UI_FACTURE_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Facture
{
public:
    QVBoxLayout *verticalLayout_6;
    QLabel *banner;
    QGroupBox *text_header;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_header1;
    QLabel *label_header_2;
    QLabel *label_header_3;
    QLabel *label_header_4;
    QLabel *label_header_5;
    QLabel *label_pv;
    QLabel *label_header_6;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_header_7;
    QLabel *label_nom_client;
    QLabel *label_contact_client;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupe_client2;
    QVBoxLayout *verticalLayout_3;
    QLabel *client_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_token;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_13;
    QLabel *label_19;
    QLabel *date;
    QLabel *label_20;
    QLabel *label_15;
    QLabel *label_21;
    QLabel *heure;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_30;
    QGroupBox *formGroupBox;
    QFormLayout *formLayout;
    QLabel *label_22;
    QLabel *total_ht;
    QLabel *label_23;
    QLabel *remise;
    QLabel *label_24;
    QLabel *tva;
    QLabel *label_29;
    QLabel *total_ttc;

    void setupUi(QDialog *Facture)
    {
        if (Facture->objectName().isEmpty())
            Facture->setObjectName(QStringLiteral("Facture"));
        Facture->resize(787, 815);
        Facture->setMinimumSize(QSize(0, 0));
        Facture->setStyleSheet(QStringLiteral("background-color:white;"));
        verticalLayout_6 = new QVBoxLayout(Facture);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        banner = new QLabel(Facture);
        banner->setObjectName(QStringLiteral("banner"));

        verticalLayout_6->addWidget(banner);

        text_header = new QGroupBox(Facture);
        text_header->setObjectName(QStringLiteral("text_header"));
        horizontalLayout = new QHBoxLayout(text_header);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_header1 = new QLabel(text_header);
        label_header1->setObjectName(QStringLiteral("label_header1"));
        label_header1->setMinimumSize(QSize(0, 0));
        label_header1->setMaximumSize(QSize(16777215, 16777215));
        label_header1->setStyleSheet(QLatin1String("font-size:18px;\n"
"font-weight:bold;"));

        verticalLayout->addWidget(label_header1);

        label_header_2 = new QLabel(text_header);
        label_header_2->setObjectName(QStringLiteral("label_header_2"));

        verticalLayout->addWidget(label_header_2);

        label_header_3 = new QLabel(text_header);
        label_header_3->setObjectName(QStringLiteral("label_header_3"));

        verticalLayout->addWidget(label_header_3);

        label_header_4 = new QLabel(text_header);
        label_header_4->setObjectName(QStringLiteral("label_header_4"));

        verticalLayout->addWidget(label_header_4);

        label_header_5 = new QLabel(text_header);
        label_header_5->setObjectName(QStringLiteral("label_header_5"));

        verticalLayout->addWidget(label_header_5);

        label_pv = new QLabel(text_header);
        label_pv->setObjectName(QStringLiteral("label_pv"));

        verticalLayout->addWidget(label_pv);

        label_header_6 = new QLabel(text_header);
        label_header_6->setObjectName(QStringLiteral("label_header_6"));

        verticalLayout->addWidget(label_header_6);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        groupBox = new QGroupBox(text_header);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_header_7 = new QLabel(groupBox);
        label_header_7->setObjectName(QStringLiteral("label_header_7"));
        label_header_7->setStyleSheet(QLatin1String("font-size:15px;\n"
"font-weight:bold;"));
        label_header_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_header_7);

        label_nom_client = new QLabel(groupBox);
        label_nom_client->setObjectName(QStringLiteral("label_nom_client"));
        label_nom_client->setStyleSheet(QLatin1String("font-size:15px;\n"
"font-weight:bold;"));
        label_nom_client->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_nom_client);

        label_contact_client = new QLabel(groupBox);
        label_contact_client->setObjectName(QStringLiteral("label_contact_client"));
        label_contact_client->setStyleSheet(QLatin1String("font-size:15px;\n"
"font-weight:bold;"));
        label_contact_client->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_contact_client);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_6->addWidget(text_header);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        groupe_client2 = new QGroupBox(Facture);
        groupe_client2->setObjectName(QStringLiteral("groupe_client2"));
        verticalLayout_3 = new QVBoxLayout(groupe_client2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        client_2 = new QLabel(groupe_client2);
        client_2->setObjectName(QStringLiteral("client_2"));

        verticalLayout_3->addWidget(client_2);


        horizontalLayout_5->addWidget(groupe_client2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_3 = new QGroupBox(Facture);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("font-size:13px;\n"
"font-weight:bold;"));

        horizontalLayout_2->addWidget(label_10);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QLatin1String("font-size:13px;\n"
"font-weight:bold;"));

        horizontalLayout_2->addWidget(label_11);

        label_token = new QLabel(groupBox_3);
        label_token->setObjectName(QStringLiteral("label_token"));
        label_token->setStyleSheet(QLatin1String("font-size:13px;\n"
"font-weight:bold;"));

        horizontalLayout_2->addWidget(label_token);


        horizontalLayout_3->addWidget(groupBox_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_13 = new QLabel(Facture);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_3->addWidget(label_13);

        label_19 = new QLabel(Facture);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(20, 0));

        horizontalLayout_3->addWidget(label_19);

        date = new QLabel(Facture);
        date->setObjectName(QStringLiteral("date"));

        horizontalLayout_3->addWidget(date);

        label_20 = new QLabel(Facture);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(label_20);

        label_15 = new QLabel(Facture);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_3->addWidget(label_15);

        label_21 = new QLabel(Facture);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(20, 0));

        horizontalLayout_3->addWidget(label_21);

        heure = new QLabel(Facture);
        heure->setObjectName(QStringLiteral("heure"));

        horizontalLayout_3->addWidget(heure);


        verticalLayout_6->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(Facture);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 380));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setLineWidth(0);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setGridStyle(Qt::DashDotDotLine);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(tableWidget);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        groupBox_4 = new QGroupBox(Facture);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setStyleSheet(QLatin1String("font-size:12px;\n"
"font-weight:bold;\n"
"font-style:italic;"));
        label_18->setWordWrap(true);

        verticalLayout_4->addWidget(label_18);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        label_30 = new QLabel(groupBox_4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setStyleSheet(QLatin1String("font-size:10px;\n"
"font-weight:bold;"));
        label_30->setWordWrap(true);

        verticalLayout_4->addWidget(label_30);


        horizontalLayout_4->addLayout(verticalLayout_4);

        formGroupBox = new QGroupBox(groupBox_4);
        formGroupBox->setObjectName(QStringLiteral("formGroupBox"));
        formGroupBox->setMinimumSize(QSize(250, 0));
        formGroupBox->setMaximumSize(QSize(250, 16777215));
        formGroupBox->setFlat(false);
        formLayout = new QFormLayout(formGroupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_22 = new QLabel(formGroupBox);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setStyleSheet(QLatin1String("font-size:13px;\n"
""));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_22);

        total_ht = new QLabel(formGroupBox);
        total_ht->setObjectName(QStringLiteral("total_ht"));
        total_ht->setStyleSheet(QLatin1String("font-weight:bold;\n"
"font-size:13px;"));
        total_ht->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, total_ht);

        label_23 = new QLabel(formGroupBox);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setStyleSheet(QLatin1String("font-size:13px;\n"
""));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_23);

        remise = new QLabel(formGroupBox);
        remise->setObjectName(QStringLiteral("remise"));
        remise->setStyleSheet(QLatin1String("font-weight:bold;\n"
"font-size:13px;"));
        remise->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, remise);

        label_24 = new QLabel(formGroupBox);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setStyleSheet(QLatin1String("font-size:13px;\n"
""));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_24);

        tva = new QLabel(formGroupBox);
        tva->setObjectName(QStringLiteral("tva"));
        tva->setStyleSheet(QLatin1String("font-weight:bold;\n"
"font-size:13px;"));
        tva->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, tva);

        label_29 = new QLabel(formGroupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setStyleSheet(QLatin1String("font-size:13px;\n"
""));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_29);

        total_ttc = new QLabel(formGroupBox);
        total_ttc->setObjectName(QStringLiteral("total_ttc"));
        total_ttc->setStyleSheet(QLatin1String("font-weight:bold;\n"
"font-size:13px;"));
        total_ttc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, total_ttc);


        horizontalLayout_4->addWidget(formGroupBox);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_6->addWidget(groupBox_4);

        text_header->raise();
        tableWidget->raise();
        groupBox_4->raise();
        banner->raise();

        retranslateUi(Facture);

        QMetaObject::connectSlotsByName(Facture);
    } // setupUi

    void retranslateUi(QDialog *Facture)
    {
        Facture->setWindowTitle(QApplication::translate("Facture", "Dialog", 0));
        banner->setText(QString());
        label_header1->setText(QApplication::translate("Facture", "STAR GRACE", 0));
        label_header_2->setText(QApplication::translate("Facture", "Commerce G\303\251n\303\251rale Import - Export", 0));
        label_header_3->setText(QApplication::translate("Facture", "Vente de mat\303\251riaux de constructions", 0));
        label_header_4->setText(QApplication::translate("Facture", "Plomberie, carreaux, granito, baguette & divers", 0));
        label_header_5->setText(QApplication::translate("Facture", "Tel: 99 74 00 74 / 90 28 10 32", 0));
        label_pv->setText(QApplication::translate("Facture", "TextLabel", 0));
        label_header_6->setText(QApplication::translate("Facture", "LOME - TOGO", 0));
        groupBox->setTitle(QString());
        label_header_7->setText(QApplication::translate("Facture", "CLIENT ", 0));
        label_nom_client->setText(QApplication::translate("Facture", "NOM DU CLIENT", 0));
        label_contact_client->setText(QApplication::translate("Facture", "CONTACT DU CLIENT", 0));
        groupe_client2->setTitle(QApplication::translate("Facture", "CLIENT", 0));
        client_2->setText(QString());
        groupBox_3->setTitle(QString());
        label_10->setText(QApplication::translate("Facture", "FACTURE", 0));
        label_11->setText(QApplication::translate("Facture", "N\302\260  : ", 0));
        label_token->setText(QApplication::translate("Facture", "12599655", 0));
        label_13->setText(QApplication::translate("Facture", "Date :", 0));
        label_19->setText(QString());
        date->setText(QApplication::translate("Facture", "18/07/2022", 0));
        label_20->setText(QString());
        label_15->setText(QApplication::translate("Facture", "Heure : ", 0));
        label_21->setText(QString());
        heure->setText(QApplication::translate("Facture", "13 :31:42", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Facture", "Format", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Facture", "DESIGNATION", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Facture", "QTE", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Facture", "Unit\303\251", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Facture", "Prix Unitaire", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Facture", "Montant Total", 0));
        groupBox_4->setTitle(QString());
        label_18->setText(QApplication::translate("Facture", "Arr\303\252t\303\251 la pr\303\251sente facture \303\240 a somme de cent cinq mille francs cfa", 0));
        label_30->setText(QApplication::translate("Facture", "NB : Les marchandises vendues ne sont ni reprises ni \303\251chang\303\251es. merci pour votre Achat", 0));
        label_22->setText(QApplication::translate("Facture", "Total HT ( F CFA )", 0));
        total_ht->setText(QApplication::translate("Facture", "0", 0));
        label_23->setText(QApplication::translate("Facture", "Total Remise ( F CFA )", 0));
        remise->setText(QApplication::translate("Facture", "0", 0));
        label_24->setText(QApplication::translate("Facture", "Total Impay\303\251 ( F CFA )", 0));
        tva->setText(QApplication::translate("Facture", "0", 0));
        label_29->setText(QApplication::translate("Facture", "Total TTC ( F CFA )", 0));
        total_ttc->setText(QApplication::translate("Facture", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class Facture: public Ui_Facture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACTURE_H
