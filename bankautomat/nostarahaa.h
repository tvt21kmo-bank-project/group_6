#ifndef NOSTARAHAA_H
#define NOSTARAHAA_H

#include <QDialog>

namespace Ui {
class NostaRahaa;
}

class NostaRahaa : public QDialog
{
    Q_OBJECT

public:
    explicit NostaRahaa(QWidget *parent = nullptr);
    ~NostaRahaa();

private slots:
    void on_pushButton_20_clicked();

private:
    Ui::NostaRahaa *ui;
};

#endif // NOSTARAHAA_H
