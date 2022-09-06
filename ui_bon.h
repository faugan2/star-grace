/********************************************************************************
** Form generated from reading UI file 'bon.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BON_H
#define UI_BON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Bon
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_header1;
    QLabel *label_header_2;
    QLabel *label_header_3;
    QLabel *label_header_4;
    QLabel *label_header_5;
    QLabel *label_header_8;
    QLabel *label_pv;
    QLabel *label_header_6;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_header_7;
    QLabel *label_nom_client;
    QLabel *label_contact_client;
    QSpacerItem *verticalSpacer_3;
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
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *banner;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Bon)
    {
        if (Bon->objectName().isEmpty())
            Bon->setObjectName(QStringLiteral("Bon"));
        Bon->resize(787, 494);
        Bon->setStyleSheet(QStringLiteral("background-color:white;"));
        verticalLayout_3 = new QVBoxLayout(Bon);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_header1 = new QLabel(Bon);
        label_header1->setObjectName(QStringLiteral("label_header1"));
        label_header1->setMinimumSize(QSize(0, 0));
        label_header1->setMaximumSize(QSize(16777215, 16777215));
        label_header1->setStyleSheet(QLatin1String("font-size:18px;\n"
"font-weight:bold;"));

        verticalLayout->addWidget(label_header1);

        label_header_2 = new QLabel(Bon);
        label_header_2->setObjectName(QStringLiteral("label_header_2"));

        verticalLayout->addWidget(label_header_2);

        label_header_3 = new QLabel(Bon);
        label_header_3->setObjectName(QStringLiteral("label_header_3"));

        verticalLayout->addWidget(label_header_3);

        label_header_4 = new QLabel(Bon);
        label_header_4->setObjectName(QStringLiteral("label_header_4"));

        verticalLayout->addWidget(label_header_4);

        label_header_5 = new QLabel(Bon);
        label_header_5->setObjectName(QStringLiteral("label_header_5"));

        verticalLayout->addWidget(label_header_5);

        label_header_8 = new QLabel(Bon);
        label_header_8->setObjectName(QStringLiteral("label_header_8"));

        verticalLayout->addWidget(label_header_8);

        label_pv = new QLabel(Bon);
        label_pv->setObjectName(QStringLiteral("label_pv"));

        verticalLayout->addWidget(label_pv);

        label_header_6 = new QLabel(Bon);
        label_header_6->setObjectName(QStringLiteral("label_header_6"));

        verticalLayout->addWidget(label_header_6);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        groupBox = new QGroupBox(Bon);
        groupBox->setObjectName(QStringLiteral("groupBox"));
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


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_3 = new QGroupBox(Bon);
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

        label_13 = new QLabel(Bon);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_3->addWidget(label_13);

        label_19 = new QLabel(Bon);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(20, 0));

        horizontalLayout_3->addWidget(label_19);

        date = new QLabel(Bon);
        date->setObjectName(QStringLiteral("date"));

        horizontalLayout_3->addWidget(date);

        label_20 = new QLabel(Bon);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(label_20);

        label_15 = new QLabel(Bon);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_3->addWidget(label_15);

        label_21 = new QLabel(Bon);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(20, 0));

        horizontalLayout_3->addWidget(label_21);

        heure = new QLabel(Bon);
        heure->setObjectName(QStringLiteral("heure"));

        horizontalLayout_3->addWidget(heure);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(Bon);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 150));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setLineWidth(0);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setGridStyle(Qt::DashDotDotLine);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(tableWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        banner = new QLabel(Bon);
        banner->setObjectName(QStringLiteral("banner"));

        horizontalLayout_4->addWidget(banner);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_4);


        retranslateUi(Bon);

        QMetaObject::connectSlotsByName(Bon);
    } // setupUi

    void retranslateUi(QDialog *Bon)
    {
        Bon->setWindowTitle(QApplication::translate("Bon", "Dialog", 0));
        label_header1->setText(QApplication::translate("Bon", "STAR GRACE", 0));
        label_header_2->setText(QApplication::translate("Bon", "Commerce G\303\251n\303\251rale Import - Export", 0));
        label_header_3->setText(QApplication::translate("Bon", "Vente de mat\303\251riaux de constructions", 0));
        label_header_4->setText(QApplication::translate("Bon", "Plomberie, carreaux, granito, baguette & divers", 0));
        label_header_5->setText(QApplication::translate("Bon", "Tel: 99 74 00 74 / 90 28 10 32", 0));
        label_header_8->setText(QApplication::translate("Bon", "nom du point de vente", 0));
        label_pv->setText(QApplication::translate("Bon", "TextLabel", 0));
        label_header_6->setText(QApplication::translate("Bon", "LOME - TOGO", 0));
        groupBox->setTitle(QString());
        label_header_7->setText(QApplication::translate("Bon", "CLIENT ", 0));
        label_nom_client->setText(QApplication::translate("Bon", "NOM DU CLIENT", 0));
        label_contact_client->setText(QApplication::translate("Bon", "CONTACT DU CLIENT", 0));
        groupBox_3->setTitle(QString());
        label_10->setText(QApplication::translate("Bon", "BON", 0));
        label_11->setText(QApplication::translate("Bon", "N\302\260  : ", 0));
        label_token->setText(QApplication::translate("Bon", "12599655", 0));
        label_13->setText(QApplication::translate("Bon", "Date :", 0));
        label_19->setText(QString());
        date->setText(QApplication::translate("Bon", "18/07/2022", 0));
        label_20->setText(QString());
        label_15->setText(QApplication::translate("Bon", "Heure : ", 0));
        label_21->setText(QString());
        heure->setText(QApplication::translate("Bon", "13 :31:42", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Bon", "Format", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Bon", "DESIGNATION", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Bon", "EMBALLAGE", 0));
        banner->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Bon: public Ui_Bon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BON_H
