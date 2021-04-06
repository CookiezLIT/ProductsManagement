#ifndef INITDB_H
#define INITDB_H

#include <QString>




class initDB
{
public:
    initDB();
    bool DatabaseConnect();
    void DatabaseInit();
    void populateBD();
    bool addCustomer(const QString &company, const QString &CUI, const QString &bank, const QString &iban, const QString &country, const QString &phone, const QString &email, const QString &address);
    bool removeCustomerComp(const QString &company);
    bool customerExists(const QString &company);
    void on_searchBox(const QString &company);
};

#endif // INITDB_H
