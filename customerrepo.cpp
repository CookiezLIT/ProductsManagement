#include "customerrepo.h"


void customerRepo::store(const customer &c)
{
    if(exist(c)){
        throw customerRepoException("Clientul exista deja in baza de date");
    }
    all.push_back(c);
}

bool customerRepo::exist(const customer &c) const{
    //verificare dupa toate criteriile deodata
    try {
        find(c.getCompany(), c.getCui(), c.getBank(), c.getIban(), c.getCountry(), c.getPhone(), c.getEmail(), c.getAddress());
        return true;
    }
    catch (customerRepoException &){
        return false;
    }
}

const customer& customerRepo::find(QString company, QString cui, QString bank, QString iban,QString country, QString phone,
                                   QString email, QString address) const{
    //cautare dupa toate criteriile
    for (const auto &c :all){
        if(c.getCompany() == company && c.getCui() == cui && c.getBank() == bank && c.getIban() == iban
                && c.getCountry() == country && c.getPhone() == phone && c.getEmail() == email &&
                c.getAddress() == address){
            return c;
        }

    }
    throw customerRepoException("NU exista clientul");
}

const customer& customerRepo::findByCompany(QString company) const{
    // cautare dupa firma
    for (const auto& c: all) {
        if(c.getCompany() == company) {
            return c;
        }
    }
    //aruncam exceptie daca nu a gasit
    throw customerRepoException("Nu exista clientul in baza de date");
}

const customer& customerRepo::findByCui(QString cui) const{
    //cautare dupa cui
    for(const auto& c: all){
        if(c.getCui() == cui){
            return c;
        }
    }
    //aruncam exceptie daca nu e gasit clientul
    throw customerRepoException("Nu exista clientul in baza de date");
}

const QVector<customer>& customerRepo::getAll() const noexcept{
    return all;
}
