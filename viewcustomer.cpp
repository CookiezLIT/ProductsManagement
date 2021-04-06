#include "viewcustomer.h"
#include "ui_viewcustomer.h"

viewCustomer::viewCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewCustomer)
{
    ui->setupUi(this);
}

viewCustomer::~viewCustomer()
{
    delete ui;
}
