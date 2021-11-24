#ifndef TOIMINTOSIVU_H
#define TOIMINTOSIVU_H

#include <QDialog>

namespace Ui {
class Toimintosivu;
}

class Toimintosivu : public QDialog
{
    Q_OBJECT

public:
    explicit Toimintosivu(QWidget *parent = nullptr);
    ~Toimintosivu();

private:
    Ui::Toimintosivu *ui;


};

#endif // TOIMINTOSIVU_H
