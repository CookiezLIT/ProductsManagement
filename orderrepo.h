#ifndef ORDERREPO_H
#define ORDERREPO_H

#include "order.h"
#include <QVector>
#include <QString>



class orderRepo
{
    QVector<order> all;
    bool existNoOrder(const order  &o) const;
public:
    orderRepo()=default;
    //nu se permite copierea de comenzi, nr comenzii e unic
    orderRepo(const orderRepo &ot) = delete;

    //salvare comanda
    void store(const order &o);

    //cautare comanda dupa cod
    const order &findByNoOrder(QString noOrder) const;

    //cautare comanda dupa firma
    const order &findByCompany(QString company) const;

    //cautare comanda dupa responsabil
    const order &findByResponsible (QString responsible) const;

    //cautare dupa reper
    const order &findByMark (QString mark) const;

    //toate comenzile salvate
    const QVector<order>& getAll() const;

    //toate comenzile in curs
    const QVector<order>& getAllDueDate() const;

};

class orderRepoException{
    QString msg;
public:
    orderRepoException(QString m):msg{m}{}
};

#endif // ORDERREPO_H
