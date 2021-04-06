#include "viewprice.h"
#include "ui_viewprice.h"

viewPrice::viewPrice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewPrice)
{
    ui->setupUi(this);
}

viewPrice::~viewPrice()
{
    delete ui;
}
