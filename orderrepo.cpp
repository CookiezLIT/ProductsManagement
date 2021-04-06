#include "orderrepo.h"

void orderRepo::store(const order &o){
    if(existNoOrder(o)){
        throw orderRepoException("Comanda exista deja in baza de date");
    }
    all.push_back(o);
}

bool orderRepo::existNoOrder(const order &o) const{
    //verificam daca exista dupa codul comenzii
    try {
        findByNoOrder(o.getNoOrder());
        return true;
    } catch (orderRepoException &){
        return false;

    }
}

const order& orderRepo::findByNoOrder(QString noOrder) const{
    for (const auto &o :all){
        if(o.getNoOrder() == noOrder){
            return o;
        }
    }
    throw orderRepoException("Nu exista comanda in baza de date");
}

const order& orderRepo::findByCompany(QString company) const{
    for (const auto &o :all){
        if(o.getCompany() == company){
            return o;
        }
    }
    throw orderRepoException("Nu exista comanda in baza de date");


}

const order& orderRepo::findByResponsible(QString responsible) const{
    for (const auto &o  :all){
        if(o.getResponsible() == responsible){
            return o;
        }
    }
    throw orderRepoException("Nu exista comanda in baza de date");
}
/*
const order& orderRepo::findByMark(QString mark) const{
    //todo
}
*/
const QVector<order>& orderRepo::getAllDueDate() const{
    return all;
}

