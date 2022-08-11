/********************************************************************************
** Form generated from reading UI file 'parametres.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRES_H
#define UI_PARAMETRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Parametres
{
public:

    void setupUi(QDialog *Parametres)
    {
        if (Parametres->objectName().isEmpty())
            Parametres->setObjectName(QStringLiteral("Parametres"));
        Parametres->resize(400, 300);

        retranslateUi(Parametres);

        QMetaObject::connectSlotsByName(Parametres);
    } // setupUi

    void retranslateUi(QDialog *Parametres)
    {
        Parametres->setWindowTitle(QApplication::translate("Parametres", "Param\303\250tres", 0));
    } // retranslateUi

};

namespace Ui {
    class Parametres: public Ui_Parametres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRES_H
