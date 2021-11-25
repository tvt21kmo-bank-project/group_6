/********************************************************************************
** Form generated from reading UI file 'paasivu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAASIVU_H
#define UI_PAASIVU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_paaSivu
{
public:
    QLabel *label;
    QPushButton *kirjauduNappi;
    QPushButton *takaisinNappi;
    QLineEdit *LineEdit_kayttajaTunnus;
    QLineEdit *LineEdit_pinKoodi;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelHylatty;

    void setupUi(QDialog *paaSivu)
    {
        if (paaSivu->objectName().isEmpty())
            paaSivu->setObjectName(QStringLiteral("paaSivu"));
        paaSivu->resize(580, 537);
        label = new QLabel(paaSivu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 40, 301, 91));
        QFont font;
        font.setPointSize(21);
        label->setFont(font);
        kirjauduNappi = new QPushButton(paaSivu);
        kirjauduNappi->setObjectName(QStringLiteral("kirjauduNappi"));
        kirjauduNappi->setGeometry(QRect(200, 280, 113, 32));
        takaisinNappi = new QPushButton(paaSivu);
        takaisinNappi->setObjectName(QStringLiteral("takaisinNappi"));
        takaisinNappi->setGeometry(QRect(420, 340, 113, 32));
        LineEdit_kayttajaTunnus = new QLineEdit(paaSivu);
        LineEdit_kayttajaTunnus->setObjectName(QStringLiteral("LineEdit_kayttajaTunnus"));
        LineEdit_kayttajaTunnus->setGeometry(QRect(200, 170, 113, 21));
        LineEdit_pinKoodi = new QLineEdit(paaSivu);
        LineEdit_pinKoodi->setObjectName(QStringLiteral("LineEdit_pinKoodi"));
        LineEdit_pinKoodi->setGeometry(QRect(200, 230, 113, 21));
        LineEdit_pinKoodi->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(paaSivu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 150, 101, 16));
        label_3 = new QLabel(paaSivu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 210, 60, 16));
        labelHylatty = new QLabel(paaSivu);
        labelHylatty->setObjectName(QStringLiteral("labelHylatty"));
        labelHylatty->setGeometry(QRect(136, 332, 171, 81));

        retranslateUi(paaSivu);

        QMetaObject::connectSlotsByName(paaSivu);
    } // setupUi

    void retranslateUi(QDialog *paaSivu)
    {
        paaSivu->setWindowTitle(QApplication::translate("paaSivu", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("paaSivu", "Sy\303\266t\303\244 k\303\244ytt\303\244tunnus ja PinKoodi", Q_NULLPTR));
        kirjauduNappi->setText(QApplication::translate("paaSivu", "Kirjaudu", Q_NULLPTR));
        takaisinNappi->setText(QApplication::translate("paaSivu", "Takaisin", Q_NULLPTR));
        label_2->setText(QApplication::translate("paaSivu", "K\303\244ytt\303\244j\303\244tunnus", Q_NULLPTR));
        label_3->setText(QApplication::translate("paaSivu", "PinKoodi", Q_NULLPTR));
        labelHylatty->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class paaSivu: public Ui_paaSivu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAASIVU_H
