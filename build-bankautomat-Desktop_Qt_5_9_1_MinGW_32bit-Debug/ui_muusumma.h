/********************************************************************************
** Form generated from reading UI file 'muusumma.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUUSUMMA_H
#define UI_MUUSUMMA_H

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

class Ui_MuuSumma
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton_MuuSummaSET;
    QLineEdit *lineEdit_MuuSumma;
    QLabel *label;
    QLabel *label_Panosumma;

    void setupUi(QDialog *MuuSumma)
    {
        if (MuuSumma->objectName().isEmpty())
            MuuSumma->setObjectName(QStringLiteral("MuuSumma"));
        MuuSumma->resize(665, 471);
        textBrowser = new QTextBrowser(MuuSumma);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(130, 60, 341, 41));
        pushButton_MuuSummaSET = new QPushButton(MuuSumma);
        pushButton_MuuSummaSET->setObjectName(QStringLiteral("pushButton_MuuSummaSET"));
        pushButton_MuuSummaSET->setGeometry(QRect(490, 150, 80, 21));
        lineEdit_MuuSumma = new QLineEdit(MuuSumma);
        lineEdit_MuuSumma->setObjectName(QStringLiteral("lineEdit_MuuSumma"));
        lineEdit_MuuSumma->setGeometry(QRect(150, 120, 291, 91));
        label = new QLabel(MuuSumma);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 270, 161, 81));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_Panosumma = new QLabel(MuuSumma);
        label_Panosumma->setObjectName(QStringLiteral("label_Panosumma"));
        label_Panosumma->setGeometry(QRect(180, 290, 91, 41));

        retranslateUi(MuuSumma);

        QMetaObject::connectSlotsByName(MuuSumma);
    } // setupUi

    void retranslateUi(QDialog *MuuSumma)
    {
        MuuSumma->setWindowTitle(QApplication::translate("MuuSumma", "Dialog", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MuuSumma", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Sy\303\266t\303\244 haluamasi panom\303\244\303\244r\303\244</span></p></body></html>", Q_NULLPTR));
        pushButton_MuuSummaSET->setText(QApplication::translate("MuuSumma", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("MuuSumma", "  Onnistuneesti Pantu", Q_NULLPTR));
        label_Panosumma->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MuuSumma: public Ui_MuuSumma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUUSUMMA_H
