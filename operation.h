#ifndef OPERATION_H
#define OPERATION_H

#include <QString>
#include <QDateTime>

class operation
{
    QString name;
    double time;
    double price;
public:
    operation();
    operation(const QString a, const double b, const double c) : name{a}, time{b}, price{c}{};

    //copy constructor
    operation(const operation &other) : name{other.name}, time{other.time}, price{other.price}{};

    QString getName() const{
        return name;
    }
    double getTime() const{
        return time;
    }
    double getPrice() const{
        return price;
    }

    void setName(QString a){
        this->name = a;
    }
    void setTime(double a){
        this->time = a;
    }
    void setPrice(double a){
        this->price = a;
    }

    double getTotalPrice(QString time, double price);
};

#endif // OPERATION_H
