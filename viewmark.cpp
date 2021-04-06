#include "viewmark.h"
#include "ui_viewmark.h"

viewMark::viewMark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewMark)
{
    ui->setupUi(this);
}

viewMark::~viewMark()
{
    delete ui;
}
