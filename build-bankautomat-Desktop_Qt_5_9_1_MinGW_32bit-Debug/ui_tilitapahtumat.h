/********************************************************************************
** Form generated from reading UI file 'tilitapahtumat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILITAPAHTUMAT_H
#define UI_TILITAPAHTUMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Tilitapahtumat
{
public:
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_NaytaLisaa;
    QPushButton *pushButton_Palaa;
    QPushButton *pushButton_KirjauduUlos;
    QLabel *label;
    QLabel *label_Eilisaa;

    void setupUi(QDialog *Tilitapahtumat)
    {
        if (Tilitapahtumat->objectName().isEmpty())
            Tilitapahtumat->setObjectName(QStringLiteral("Tilitapahtumat"));
        Tilitapahtumat->resize(896, 582);
        textBrowser_2 = new QTextBrowser(Tilitapahtumat);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(140, 110, 611, 192));
        pushButton_NaytaLisaa = new QPushButton(Tilitapahtumat);
        pushButton_NaytaLisaa->setObjectName(QStringLiteral("pushButton_NaytaLisaa"));
        pushButton_NaytaLisaa->setGeometry(QRect(760, 120, 101, 51));
        QFont font;
        font.setPointSize(18);
        pushButton_NaytaLisaa->setFont(font);
        pushButton_Palaa = new QPushButton(Tilitapahtumat);
        pushButton_Palaa->setObjectName(QStringLiteral("pushButton_Palaa"));
        pushButton_Palaa->setGeometry(QRect(20, 260, 101, 41));
        pushButton_KirjauduUlos = new QPushButton(Tilitapahtumat);
        pushButton_KirjauduUlos->setObjectName(QStringLiteral("pushButton_KirjauduUlos"));
        pushButton_KirjauduUlos->setGeometry(QRect(760, 240, 101, 51));
        pushButton_KirjauduUlos->setFont(font);
        label = new QLabel(Tilitapahtumat);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 60, 211, 41));
        QFont font1;
        font1.setPointSize(24);
        label->setFont(font1);
        label_Eilisaa = new QLabel(Tilitapahtumat);
        label_Eilisaa->setObjectName(QStringLiteral("label_Eilisaa"));
        label_Eilisaa->setGeometry(QRect(140, 110, 611, 191));
        QFont font2;
        font2.setPointSize(28);
        label_Eilisaa->setFont(font2);

        retranslateUi(Tilitapahtumat);

        QMetaObject::connectSlotsByName(Tilitapahtumat);
    } // setupUi

    void retranslateUi(QDialog *Tilitapahtumat)
    {
        Tilitapahtumat->setWindowTitle(QApplication::translate("Tilitapahtumat", "Dialog", Q_NULLPTR));
        pushButton_NaytaLisaa->setText(QApplication::translate("Tilitapahtumat", "\342\206\221", Q_NULLPTR));
        pushButton_Palaa->setText(QApplication::translate("Tilitapahtumat", "Palaa takaisin", Q_NULLPTR));
        pushButton_KirjauduUlos->setText(QApplication::translate("Tilitapahtumat", "\342\206\223", Q_NULLPTR));
        label->setText(QApplication::translate("Tilitapahtumat", "Tilitapahtumat", Q_NULLPTR));
        label_Eilisaa->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tilitapahtumat: public Ui_Tilitapahtumat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILITAPAHTUMAT_H
