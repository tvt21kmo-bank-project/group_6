/********************************************************************************
** Form generated from reading UI file 'tyyppi.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYYPPI_H
#define UI_TYYPPI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Tyyppi
{
public:
    QPushButton *pushButtonCredit;
    QPushButton *pushButtonDebit;
    QLabel *label;
    QPushButton *pushButtonKirjauduUlos;

    void setupUi(QDialog *Tyyppi)
    {
        if (Tyyppi->objectName().isEmpty())
            Tyyppi->setObjectName(QStringLiteral("Tyyppi"));
        Tyyppi->resize(835, 448);
        pushButtonCredit = new QPushButton(Tyyppi);
        pushButtonCredit->setObjectName(QStringLiteral("pushButtonCredit"));
        pushButtonCredit->setGeometry(QRect(180, 130, 91, 31));
        pushButtonDebit = new QPushButton(Tyyppi);
        pushButtonDebit->setObjectName(QStringLiteral("pushButtonDebit"));
        pushButtonDebit->setGeometry(QRect(430, 130, 91, 31));
        label = new QLabel(Tyyppi);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 50, 191, 61));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        pushButtonKirjauduUlos = new QPushButton(Tyyppi);
        pushButtonKirjauduUlos->setObjectName(QStringLiteral("pushButtonKirjauduUlos"));
        pushButtonKirjauduUlos->setGeometry(QRect(300, 250, 111, 31));

        retranslateUi(Tyyppi);

        QMetaObject::connectSlotsByName(Tyyppi);
    } // setupUi

    void retranslateUi(QDialog *Tyyppi)
    {
        Tyyppi->setWindowTitle(QApplication::translate("Tyyppi", "Dialog", Q_NULLPTR));
        pushButtonCredit->setText(QApplication::translate("Tyyppi", "Credit", Q_NULLPTR));
        pushButtonDebit->setText(QApplication::translate("Tyyppi", "Debit", Q_NULLPTR));
        label->setText(QApplication::translate("Tyyppi", "Valitse Credit tai Debit", Q_NULLPTR));
        pushButtonKirjauduUlos->setText(QApplication::translate("Tyyppi", "Kirjaudu Ulos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Tyyppi: public Ui_Tyyppi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYYPPI_H
