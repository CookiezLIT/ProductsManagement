#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

class customer
{
    QString company;
    QString cui;
    QString bank;
    QString iban;
    QString country;
    QString phone;
    QString email;
    QString address;
public:
    customer();
    customer(const QString a, const QString b, const QString c, const QString d, const QString e, const QString f,
             const QString g, const QString h) : company{a}, cui{b}, bank{c}, iban{d}, country{e}, phone{f},
             email{g}, address{h} {};

    //copy constructor
    customer(const customer &other) : company{other.company}, cui{other.cui}, bank{other.bank}, iban{other.iban},
        country{other.country}, phone{other.country}, email{other.email}, address{other.address}{};


    QString getCompany() const{
        return company;
    }
    QString getCui() const{
        return cui;
    }
    QString getBank() const{
        return bank;
    }
    QString getIban() const{
        return iban;
    }
    QString getCountry() const{
        return country;
    }
    QString getPhone() const{
        return phone;
    }
    QString getEmail() const{
        return email;
    }
    QString getAddress() const{
        return address;
    }

    void setCompany(QString a){
        this->company = a;
    }
    void setCui(QString b){
        this->cui = b;
    }
    void setBank(QString c){
        this->bank = c;
    }
    void setIban(QString d){
        this->iban = d;
    }
    void setCountry(QString e){
        this->country = e;
    }
    void setPhone(QString f){
        this->phone = f;
    }
    void setEmail(QString g){
        this->email = g;
    }
    void setAddress(QString h){
        this->address = h;
    }


};

#endif // CUSTOMER_H
