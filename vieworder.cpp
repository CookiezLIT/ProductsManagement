#include "vieworder.h"
#include "ui_vieworder.h"

viewOrder::viewOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewOrder)
{
    ui->setupUi(this);
    if(createConnection()){
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery();

        QString noOorder, company, responsible;
        QDateTime date, dueDate;
        qry->prepare("select * from order");
        if(!(qry->exec())){
            QMessageBox::critical(this, tr("error: "), qry->lastError().text());

        }
    }
}

viewOrder::~viewOrder()
{
    delete ui;
}
