#include "initdb.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlDriver>
#include <QDebug>
#include <QString>
#include <QTableView>
#include <QSqlTableModel>


bool initDB::DatabaseConnect()
{//conectare la baza de date
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName(":memory:");

        if(!db.open())
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
        return false;
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
    return  true;
}

void initDB::DatabaseInit()
{  //creare si initializare pt tabela clienti
    QSqlQuery query("CREATE TABLE customers (company varchar(100) PRIMARY KEY, CUI varchar(50), bank varchar(100), IBAN varchar(50), country varchar(50), phone varchar(50), email varchar(50), address varchar(100))");

    if(!query.isActive())
        qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();

}



bool initDB::addCustomer(const QString &company, const QString &CUI, const QString &bank, const QString &iban, const QString &country, const QString &phone, const QString &email, const QString &address)
{ //adaugare client nou
    bool success=false;

    QSqlQuery queryAdd;

    queryAdd.prepare("INSERT INTO customers(company,CUI,bank,IBAN,country,phone,email,address) VALUES (:company, :CUI,:bank,:IBAN,:country,:phone,:email,:address)");
    queryAdd.bindValue(":company",company);
    queryAdd.bindValue(":CUI",CUI);
    queryAdd.bindValue(":bank",bank);
    queryAdd.bindValue(":IBAN",iban);
    queryAdd.bindValue(":country",country);
    queryAdd.bindValue(":phone",phone);
    queryAdd.bindValue(":email",email);
    queryAdd.bindValue(":address",address);

    if(queryAdd.exec())
    {
        success = true;

    }
    else
    {
        qDebug()<<"add op failed: "<<queryAdd.lastError();
    }
    return success;

}

bool initDB::removeCustomerComp(const QString &company)
{ //eliminare din baza de date dupa numele companiei
    bool success=false;

    if(customerExists(company))
    {

            QSqlQuery queryRemove;
            queryRemove.prepare("DELETE FROM customers WHERE company = (:company)");
            queryRemove.bindValue(":company",company);
            success = queryRemove.exec();

            if(!success)
            {
                qDebug() << "removing persong failed" <<queryRemove.lastError();
            }

    }
    else
    {
        qDebug() << "removing customer failed: customer not in the db";
    }

    return success;
}


bool initDB::customerExists(const QString &company)
{//verificam daca persoana exista in baza de date dupa numele companiei
    bool exists=false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM customers WHERE company= (:company)");
    checkQuery.bindValue(":company", company);

    if(checkQuery.exec())
    {
        if(checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "check failed: " << checkQuery.lastError();
    }
    return exists;
}
