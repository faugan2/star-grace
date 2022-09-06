/********************************************************************************
** Form generated from reading UI file 'allprepayement.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLPREPAYEMENT_H
#define UI_ALLPREPAYEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AllPrePayement
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_del;
    QTableWidget *table_pre_payement;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *clients;
    QLabel *label;
    QLineEdit *montant;
    QTextEdit *details;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AllPrePayement)
    {
        if (AllPrePayement->objectName().isEmpty())
            AllPrePayement->setObjectName(QStringLiteral("AllPrePayement"));
        AllPrePayement->resize(571, 253);
        horizontalLayout_3 = new QHBoxLayout(AllPrePayement);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_del = new QPushButton(AllPrePayement);
        btn_del->setObjectName(QStringLiteral("btn_del"));
        btn_del->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/images/trash-outline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon);

        horizontalLayout->addWidget(btn_del);


        verticalLayout->addLayout(horizontalLayout);

        table_pre_payement = new QTableWidget(AllPrePayement);
        if (table_pre_payement->columnCount() < 3)
            table_pre_payement->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_pre_payement->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_pre_payement->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_pre_payement->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table_pre_payement->setObjectName(QStringLiteral("table_pre_payement"));
        table_pre_payement->setGridStyle(Qt::DashDotDotLine);
        table_pre_payement->horizontalHeader()->setStretchLastSection(true);
        table_pre_payement->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(table_pre_payement);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(AllPrePayement);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        clients = new QComboBox(groupBox);
        clients->setObjectName(QStringLiteral("clients"));
        clients->setEditable(true);

        verticalLayout_2->addWidget(clients);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        montant = new QLineEdit(groupBox);
        montant->setObjectName(QStringLiteral("montant"));

        verticalLayout_2->addWidget(montant);

        details = new QTextEdit(groupBox);
        details->setObjectName(QStringLiteral("details"));

        verticalLayout_2->addWidget(details);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:8px;\n"
"border:none;"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);


        retranslateUi(AllPrePayement);

        QMetaObject::connectSlotsByName(AllPrePayement);
    } // setupUi

    void retranslateUi(QDialog *AllPrePayement)
    {
        AllPrePayement->setWindowTitle(QApplication::translate("AllPrePayement", "Tous les d\303\251p\303\264ts", 0));
        btn_del->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_pre_payement->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AllPrePayement", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_pre_payement->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AllPrePayement", "Client", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_pre_payement->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AllPrePayement", "Montant", 0));
        groupBox->setTitle(QApplication::translate("AllPrePayement", "Enregistrez un pr\303\251-payement", 0));
        label->setText(QApplication::translate("AllPrePayement", "Montant", 0));
        details->setPlaceholderText(QApplication::translate("AllPrePayement", "D\303\251tails", 0));
        pushButton_2->setText(QApplication::translate("AllPrePayement", "Enregistrez", 0));
    } // retranslateUi

};

namespace Ui {
    class AllPrePayement: public Ui_AllPrePayement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLPREPAYEMENT_H
