#ifndef ORDER_H
#define ORDER_H
#include <QString>
#include <QDateTime>
#include <QVector>
#include "mark.h"
#include "genoffert.h"

class order
{
    QString noOrder;
    QString company;
    QString responsible;
    QDateTime date;
    QDateTime dueDate;
    QVector<mark> marks;


public:
    order(const QString &a, const QString &b, const QString &c, const QDateTime &d, const QDateTime &e, const QVector<mark> &f):
        noOrder{a}, company{b}, responsible{c}, date{d}, dueDate{e}, marks{f}{};
    //copy constructor

    order(const order &ot) : noOrder{ot.noOrder}, company{ot.company}, responsible{ot.responsible},
        date{ot.date}, dueDate{ot.dueDate}{};

    QString getNoOrder() const{
        return noOrder;
    }
    QString getCompany() const{
        return company;

    }
    QString getResponsible() const{
        return responsible;
    }
    QDateTime getDate() const{
        return date;
    }
    QDateTime getDueDate() const{
        return dueDate;
    }
    QVector<mark> getMarks() const{
        return marks;
    }

    void setNoOrder(QString a){
        this->noOrder = a;// nu ar trb sa fie unic?????????
    }
    void setCompany(QString b){
        this->company = b;
    }
    void setResponsible(QString c){
        this->responsible = c;
    }
    void setDate(QDateTime d){
        this->date = d;
    }
    void setDueDate(QDateTime e){
        this->dueDate = e;
    }
    void setMarks(QVector<mark> f){
        this->marks = f;
    }


};

#endif // ORDER_H
