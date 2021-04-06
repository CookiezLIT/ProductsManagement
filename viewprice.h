#ifndef VIEWPRICE_H
#define VIEWPRICE_H

#include <QDialog>

namespace Ui {
class viewPrice;
}

class viewPrice : public QDialog
{
    Q_OBJECT

public:
    explicit viewPrice(QWidget *parent = nullptr);
    ~viewPrice();

private:
    Ui::viewPrice *ui;
};

#endif // VIEWPRICE_H
