#include "viewstocks.h"
#include "ui_viewstocks.h"
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
viewStocks::viewStocks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewStocks)
{
    ui->setupUi(this);
    loadDatabase();


}
void viewStocks::loadDatabase()
{
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQueryModel *model = new QSqlQueryModel();
    //m_db.setDatabaseName("C:/Users/Nita/Desktop/Nico2/db.sqlite");
    m_db.setDatabaseName("C:/Users/JohnDoe/Documents/Proiect/Nico/db.sqlite");
    if (!m_db.open())
    {
      qDebug() << "Error: connection with database failed";
    }
    else
    {
      qDebug() << "Database: connection ok";
    }
    QSqlQuery *qry = new QSqlQuery();
    qry->prepare("select * from stocks");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}
viewStocks::~viewStocks()
{
    delete ui;
}

