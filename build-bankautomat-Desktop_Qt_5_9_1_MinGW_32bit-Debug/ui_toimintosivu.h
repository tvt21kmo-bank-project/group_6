/********************************************************************************
** Form generated from reading UI file 'toimintosivu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOIMINTOSIVU_H
#define UI_TOIMINTOSIVU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Toimintosivu
{
public:
    QPushButton *pushButtonNosta;
    QPushButton *pushButtonPane;
    QPushButton *pushButtonSaldo;
    QPushButton *pushButtonTilitapahtumat;
    QPushButton *pushButtonKirjauduUlos2;
    QTextBrowser *textBrowserAsiakkaanNimi;

    void setupUi(QDialog *Toimintosivu)
    {
        if (Toimintosivu->objectName().isEmpty())
            Toimintosivu->setObjectName(QStringLiteral("Toimintosivu"));
        Toimintosivu->resize(723, 531);
        pushButtonNosta = new QPushButton(Toimintosivu);
        pushButtonNosta->setObjectName(QStringLiteral("pushButtonNosta"));
        pushButtonNosta->setGeometry(QRect(89, 60, 111, 31));
        pushButtonPane = new QPushButton(Toimintosivu);
        pushButtonPane->setObjectName(QStringLiteral("pushButtonPane"));
        pushButtonPane->setGeometry(QRect(540, 60, 101, 31));
        pushButtonSaldo = new QPushButton(Toimintosivu);
        pushButtonSaldo->setObjectName(QStringLiteral("pushButtonSaldo"));
        pushButtonSaldo->setGeometry(QRect(109, 120, 91, 31));
        pushButtonTilitapahtumat = new QPushButton(Toimintosivu);
        pushButtonTilitapahtumat->setObjectName(QStringLiteral("pushButtonTilitapahtumat"));
        pushButtonTilitapahtumat->setGeometry(QRect(540, 110, 111, 31));
        pushButtonKirjauduUlos2 = new QPushButton(Toimintosivu);
        pushButtonKirjauduUlos2->setObjectName(QStringLiteral("pushButtonKirjauduUlos2"));
        pushButtonKirjauduUlos2->setGeometry(QRect(540, 200, 101, 31));
        textBrowserAsiakkaanNimi = new QTextBrowser(Toimintosivu);
        textBrowserAsiakkaanNimi->setObjectName(QStringLiteral("textBrowserAsiakkaanNimi"));
        textBrowserAsiakkaanNimi->setGeometry(QRect(210, 50, 321, 141));

        retranslateUi(Toimintosivu);

        QMetaObject::connectSlotsByName(Toimintosivu);
    } // setupUi

    void retranslateUi(QDialog *Toimintosivu)
    {
        Toimintosivu->setWindowTitle(QApplication::translate("Toimintosivu", "Dialog", Q_NULLPTR));
        pushButtonNosta->setText(QApplication::translate("Toimintosivu", "Nosta Rahaa", Q_NULLPTR));
        pushButtonPane->setText(QApplication::translate("Toimintosivu", "Pane Rahaa", Q_NULLPTR));
        pushButtonSaldo->setText(QApplication::translate("Toimintosivu", "Saldo", Q_NULLPTR));
        pushButtonTilitapahtumat->setText(QApplication::translate("Toimintosivu", "Tilitapahtumat", Q_NULLPTR));
        pushButtonKirjauduUlos2->setText(QApplication::translate("Toimintosivu", "Kirjaudu ulos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Toimintosivu: public Ui_Toimintosivu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOIMINTOSIVU_H
