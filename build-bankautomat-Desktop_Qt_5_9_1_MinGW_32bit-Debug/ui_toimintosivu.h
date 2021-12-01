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
    QTextBrowser *textBrowserSaldo;
    QTextBrowser *textBrowserAsiakkaanNimi;
    QTextBrowser *textBrowserTiliTapahtumat;

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
        textBrowserSaldo = new QTextBrowser(Toimintosivu);
        textBrowserSaldo->setObjectName(QStringLiteral("textBrowserSaldo"));
        textBrowserSaldo->setGeometry(QRect(210, 90, 321, 61));
        textBrowserAsiakkaanNimi = new QTextBrowser(Toimintosivu);
        textBrowserAsiakkaanNimi->setObjectName(QStringLiteral("textBrowserAsiakkaanNimi"));
        textBrowserAsiakkaanNimi->setGeometry(QRect(210, 50, 321, 41));
        textBrowserTiliTapahtumat = new QTextBrowser(Toimintosivu);
        textBrowserTiliTapahtumat->setObjectName(QStringLiteral("textBrowserTiliTapahtumat"));
        textBrowserTiliTapahtumat->setGeometry(QRect(20, 240, 681, 161));

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
        textBrowserTiliTapahtumat->setHtml(QApplication::translate("Toimintosivu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	TILITAPAHTUMAT</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Toimintosivu: public Ui_Toimintosivu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOIMINTOSIVU_H
