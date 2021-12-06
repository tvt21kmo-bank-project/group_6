/********************************************************************************
** Form generated from reading UI file 'saldosivu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDOSIVU_H
#define UI_SALDOSIVU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Saldosivu
{
public:
    QTextBrowser *textBrowser_Saldo;
    QPushButton *pushButton_takaisin;
    QTextBrowser *textBrowser_Tilitapahtumat;

    void setupUi(QDialog *Saldosivu)
    {
        if (Saldosivu->objectName().isEmpty())
            Saldosivu->setObjectName(QStringLiteral("Saldosivu"));
        Saldosivu->resize(625, 454);
        textBrowser_Saldo = new QTextBrowser(Saldosivu);
        textBrowser_Saldo->setObjectName(QStringLiteral("textBrowser_Saldo"));
        textBrowser_Saldo->setGeometry(QRect(130, 90, 431, 41));
        pushButton_takaisin = new QPushButton(Saldosivu);
        pushButton_takaisin->setObjectName(QStringLiteral("pushButton_takaisin"));
        pushButton_takaisin->setGeometry(QRect(40, 270, 80, 21));
        textBrowser_Tilitapahtumat = new QTextBrowser(Saldosivu);
        textBrowser_Tilitapahtumat->setObjectName(QStringLiteral("textBrowser_Tilitapahtumat"));
        textBrowser_Tilitapahtumat->setGeometry(QRect(130, 130, 431, 191));

        retranslateUi(Saldosivu);

        QMetaObject::connectSlotsByName(Saldosivu);
    } // setupUi

    void retranslateUi(QDialog *Saldosivu)
    {
        Saldosivu->setWindowTitle(QApplication::translate("Saldosivu", "Dialog", Q_NULLPTR));
        pushButton_takaisin->setText(QApplication::translate("Saldosivu", "Takaisin", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Saldosivu: public Ui_Saldosivu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDOSIVU_H
