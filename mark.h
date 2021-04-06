#ifndef MARK_H
#define MARK_H

#include <QString>
#include <QVector>
#include "operation.h"

class mark
{
    QString internalCode;
    QString name;
    int qty;
    double weight;
    //double prodTime;
    QString shape;
    QVector<double> dimensions;//ok?? is mai multe dimensiuni, in functie de shape
    QString material;
    QVector<operation> operations;

public:
    mark(const QString &a, const QString &b, const int &c, const double &d,
         const QString &f, const QVector<double> &g, const QString &h,const QVector<operation> &i) :
        internalCode{a}, name{b}, qty{c}, weight{d}, shape{f},dimensions{g},
        material{h},operations{i}{};

    //copy constructor
    mark(const mark &ot) : internalCode{ot.internalCode}, name{ot.name}, qty{ot.qty}, weight{ot.weight},
        shape{ot.shape}, dimensions{ot.dimensions}, material{ot.material},
        operations{ot.operations}{};



    QString getInternalCode() const{
        return internalCode;
    }
    QString getName() const{
        return name;
    }
    int getQty(){
        return qty;
    }
    double getWeight(){
    return weight;
    }
//    int getNoOperations(){
//        return noOperations;
//    }
    QString getShape(){
        return shape;
    }
    QVector<double> getDimensions(){
        return dimensions;
    }
    QString getMaterial(){
        return material;
    }
    QVector<operation> getOperations(){
        return operations;
    }



    void setInternalCode(QString a){
        this->internalCode = a;
    }
    void setName(QString b){
        this->name = b;
    }
    void setQty(int c){
        this->qty = c;
    }
    void setWeight(double d){
        this->weight = d;
    }
//    void setNoOperations(int e){
//        this->noOperations = e;
//    }

    void setShape(QString shape){
        this->shape = shape;
    }
    void setDimensions(QVector<double> v){
        this->dimensions = v;
    }
    void setMaterial(QString m){
        this->material = m;
    }
    void setOperations(QVector<operation> op){
        this->operations = op;
    }
};

#endif // MARK_H
