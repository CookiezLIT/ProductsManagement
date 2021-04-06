#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlError>
#include "connect.h"
#include "customer.h"
#include "initdb.h"
#include <QDebug>
#include <QString>
#include <QTextEdit>
#include <QLineEdit>


namespace Ui {
class addCustomer;
}

class addCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit addCustomer(QWidget *parent = nullptr);
    void centerAndResize();


    ~addCustomer();

public:
    QSqlTableModel *model;
    void addToDB(customer *customer);



private slots:


    void on_tableView_activated(const QModelIndex &index);
    void loadDatabase();
    void on_saveCustomer_clicked();


private:
    Ui::addCustomer *ui;

};

#endif // ADDCUSTOMER_H
