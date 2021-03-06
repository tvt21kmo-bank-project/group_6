#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QThread>

#include "paasivu.h"
#include "tyyppi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_jatka_clicked();

private:
    Ui::MainWindow *ui;
    paaSivu *olioPaaSivu;
    //Toimintosivu *olioToimintoSivu;
};
#endif // MAINWINDOW_H
