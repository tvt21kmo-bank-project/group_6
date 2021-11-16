#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>

namespace Ui {
class paaSivu;
}

class paaSivu : public QDialog
{
    Q_OBJECT

public:
    explicit paaSivu(QWidget *parent = nullptr);
    ~paaSivu();

private:
    Ui::paaSivu *ui;
};

#endif // PAASIVU_H
