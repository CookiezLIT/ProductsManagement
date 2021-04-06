#ifndef CUSTOMERREPO_H
#define CUSTOMERREPO_H

#include <QVector>
#include <QString>
#include "customer.h"

using std::vector;

class customerRepo
{
    QVector<customer> all;
    bool exist(const customer &c) const;

public:
    customerRepo() = default;
    //nu se permite copierea de obiecte
    customerRepo(const customerRepo &ot) = delete;


    //salvare client
    void store(const customer &c);

    //cautare client
    const customer & find(QString company, QString cui, QString bank, QString iban, QString country, QString phone,
                          QString email, QString address) const;

    //cautare client dupa firma
    const customer& findByCompany(QString company ) const;

    //cautare client dupa cui
    const customer& findByCui(QString cui) const;

    //returnam toti clientii salvati
    const QVector<customer>& getAll() const noexcept;
};

//semnalam eventuale exceptii ce apar in repo

class customerRepoException{
    QString msg;

public:
    customerRepoException(QString m) : msg{m}{}

};

#endif // CUSTOMERREPO_H
