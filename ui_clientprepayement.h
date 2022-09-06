/********************************************************************************
** Form generated from reading UI file 'clientprepayement.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTPREPAYEMENT_H
#define UI_CLIENTPREPAYEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClientPrePayement
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *nom;
    QLabel *label;
    QLabel *contact;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *montant;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line;
    QTableWidget *table;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;

    void setupUi(QDialog *ClientPrePayement)
    {
        if (ClientPrePayement->objectName().isEmpty())
            ClientPrePayement->setObjectName(QStringLiteral("ClientPrePayement"));
        ClientPrePayement->resize(384, 247);
        verticalLayout = new QVBoxLayout(ClientPrePayement);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        nom = new QLabel(ClientPrePayement);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setStyleSheet(QStringLiteral("font-weight:bold;"));

        horizontalLayout->addWidget(nom);

        label = new QLabel(ClientPrePayement);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        contact = new QLabel(ClientPrePayement);
        contact->setObjectName(QStringLiteral("contact"));
        contact->setStyleSheet(QStringLiteral("font-weight:bold;"));

        horizontalLayout->addWidget(contact);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        montant = new QLabel(ClientPrePayement);
        montant->setObjectName(QStringLiteral("montant"));
        montant->setStyleSheet(QStringLiteral("font-weight:bold;"));

        horizontalLayout_3->addWidget(montant);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(ClientPrePayement);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        table = new QTableWidget(ClientPrePayement);
        if (table->columnCount() < 3)
            table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table->setObjectName(QStringLiteral("table"));
        table->setAlternatingRowColors(true);
        table->setGridStyle(Qt::DashDotDotLine);
        table->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(table);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(ClientPrePayement);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:8px;\n"
"border:none;"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ClientPrePayement);

        QMetaObject::connectSlotsByName(ClientPrePayement);
    } // setupUi

    void retranslateUi(QDialog *ClientPrePayement)
    {
        ClientPrePayement->setWindowTitle(QApplication::translate("ClientPrePayement", "Information du pr\303\251-payement", 0));
        nom->setText(QString());
        label->setText(QApplication::translate("ClientPrePayement", "/", 0));
        contact->setText(QString());
        montant->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClientPrePayement", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClientPrePayement", "Montant", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ClientPrePayement", "Details", 0));
        pushButton->setText(QApplication::translate("ClientPrePayement", "Supprimer tout", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientPrePayement: public Ui_ClientPrePayement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTPREPAYEMENT_H
