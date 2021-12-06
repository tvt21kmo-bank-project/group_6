/********************************************************************************
** Form generated from reading UI file 'muusummanosto.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUUSUMMANOSTO_H
#define UI_MUUSUMMANOSTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_MuuSummaNosto
{
public:
    QLineEdit *lineEdit_MuuNosto;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_MuuSummaNosto;
    QLabel *label_MuuNosto;

    void setupUi(QDialog *MuuSummaNosto)
    {
        if (MuuSummaNosto->objectName().isEmpty())
            MuuSummaNosto->setObjectName(QStringLiteral("MuuSummaNosto"));
        MuuSummaNosto->resize(862, 483);
        lineEdit_MuuNosto = new QLineEdit(MuuSummaNosto);
        lineEdit_MuuNosto->setObjectName(QStringLiteral("lineEdit_MuuNosto"));
        lineEdit_MuuNosto->setGeometry(QRect(220, 130, 321, 71));
        textBrowser = new QTextBrowser(MuuSummaNosto);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(200, 30, 411, 51));
        pushButton_MuuSummaNosto = new QPushButton(MuuSummaNosto);
        pushButton_MuuSummaNosto->setObjectName(QStringLiteral("pushButton_MuuSummaNosto"));
        pushButton_MuuSummaNosto->setGeometry(QRect(590, 150, 80, 21));
        label_MuuNosto = new QLabel(MuuSummaNosto);
        label_MuuNosto->setObjectName(QStringLiteral("label_MuuNosto"));
        label_MuuNosto->setGeometry(QRect(150, 260, 591, 121));

        retranslateUi(MuuSummaNosto);

        QMetaObject::connectSlotsByName(MuuSummaNosto);
    } // setupUi

    void retranslateUi(QDialog *MuuSummaNosto)
    {
        MuuSummaNosto->setWindowTitle(QApplication::translate("MuuSummaNosto", "Dialog", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MuuSummaNosto", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">Valitse nostettava m\303\244\303\244r\303\244</span></p></body></html>", Q_NULLPTR));
        pushButton_MuuSummaNosto->setText(QApplication::translate("MuuSummaNosto", "PushButton", Q_NULLPTR));
        label_MuuNosto->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MuuSummaNosto: public Ui_MuuSummaNosto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUUSUMMANOSTO_H
