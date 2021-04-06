#ifndef VIEWCUSTOMER_H
#define VIEWCUSTOMER_H

#include <QDialog>

namespace Ui {
class viewCustomer;
}

class viewCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit viewCustomer(QWidget *parent = nullptr);
    ~viewCustomer();

private:
    Ui::viewCustomer *ui;
};

#endif // VIEWCUSTOMER_H
