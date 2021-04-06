#include "pricecalculation.h"
#include "ui_pricecalculation.h"
#include <QDebug>
priceCalculation::priceCalculation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::priceCalculation)
{
    ui->setupUi(this);
    testMaterialprice();
}

priceCalculation::~priceCalculation()
{
    delete ui;
}



double priceCalculation::switchMarkString(mark m){
    //volumul in mm3 in functie de forma reperului
    double volumePerBuc;
    const double pi = 3.1415926535897323846;

    QMetaObject metaObject = this->staticMetaObject;
    QMetaEnum MetaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("profileCases"));

    switch (MetaEnum.keyToValue(m.getShape().toLower().toLatin1()))
    {
    case corniera:
    {
        double h1 = m.getDimensions()[0]; // accesam prima casuta din vector
        double h2 = m.getDimensions()[1];
        double T = m.getDimensions()[2];
        double L = m.getDimensions()[3];
        volumePerBuc = (h1*T+(h2-T)*T)*L;
        return volumePerBuc;
    }
    case rotund:
    {
       double fi = m.getDimensions()[0];
       double L = m.getDimensions()[1];
       volumePerBuc = (fi/2)*(fi/2)*pi*L;
       return volumePerBuc;
    }
    case teava_rotunda:
    {
        double fi = m.getDimensions()[0];
        double T = m.getDimensions()[1];
        double L = m.getDimensions()[2];
        volumePerBuc = ((fi/2)*(fi/2)-((fi-2*T)*(fi-2*T)/4))*pi*L;
        return volumePerBuc;
    }
    case patrat:{
        double l = m.getDimensions()[0];
        double h = m.getDimensions()[1];
        double L = m.getDimensions()[2];

        volumePerBuc = l*h*L;
        return volumePerBuc;

    }
}
    return 1.0;
}

double priceCalculation::volumePrice(mark m){
    int q = m.getQty();
    double price;
    price = (double(q)+1)*switchMarkString(m);
    return price;
}

double priceCalculation::materialPrice(mark m){
    //aici tre sa vad cum sabag costul pt fiecare material, inca nu m-am gandit cum
    double price;
    double w = m.getWeight();
    double kgPrice = 4;
    double materialCost = kgPrice*(1.1);
    double volume = volumePrice(m);

    QMetaObject meta = this->staticMetaObject;
    QMetaEnum metaEnum = meta.enumerator(meta.indexOfEnumerator("materialCases"));
    switch (metaEnum.keyToValue(m.getMaterial().toLower().toLatin1()))
    {
    case otel:
    {
        double materialPrice = 7800;
        double intermediar = ((volume/m.getQty())*pow(10,-9))*materialPrice;
        double finalPrice = intermediar*materialCost;
        return finalPrice;

    }
    case aluminiu:
    {
        double materialPrice = 2700;
        double intermediar = ((volume/m.getQty())*pow(10,-9))*materialPrice;
        double finalPrice = intermediar*materialCost;
        return finalPrice;
    }
    case inox:
    {
        double materialPrice = 8000;
        double intermediar = ((volume/m.getQty())*pow(10,-9))*materialPrice;
        double finalPrice = intermediar*materialCost;
        return finalPrice;
    }
    case cupru:
    {
        double materialPrice = 8950;
        double intermediar = ((volume/m.getQty())*pow(10,-9))*materialPrice;
        double finalPrice = intermediar*materialCost;
        return finalPrice;
    }
    case plastic:
    {
        double materialPrice = 1300;
        double intermediar = ((volume/m.getQty())*pow(10,-9))*materialPrice;
        double finalPrice = intermediar*materialCost;
        return finalPrice;
    }


    }
    return 1.0;
}

void priceCalculation::testMaterialprice()
{
    QVector <double> dim(1.0,2.2);
    operation op1("1",1.0,2.0);
    operation op2("1",1.0,2.0);
    operation op3("1",1.0,2.0);
    QVector <operation> op;

    mark k("1","1",1,1.0,"corniera",dim,"plastic",op);
    double x = materialPrice(k);
    qDebug() << x << "pret";
}

double priceCalculation::totalOperationPrice(mark m){
    //calculul total al costului dupa operatii

    int qty = m.getQty();
    double total=0;
    for(int i=0; i<sizeof (m.getOperations()); i++){
            double time = m.getOperations()[i].getTime();
            double cost = m.getOperations()[i].getPrice();
            double price = time*cost/qty;
            total += price;

 }
    return total;

}

double priceCalculation::treatmentsPrice(mark m){

    double w = m.getWeight();
    double treatment=2.0;
    double transportation=2.0;

    double price =w*treatment+transportation*(double(m.getQty()));
    return price;

}

double priceCalculation::manufacturePrice(mark m){

    //todo
    double price = 10.0;
    return price;
}

double priceCalculation::finalPrice(mark m){
    double mat = materialPrice(m);
    double treat = treatmentsPrice(m);
    double op = totalOperationPrice(m);
    double man = manufacturePrice(m);
    double interm = op + man/(double(m.getQty()));
    double final =mat+treat+interm*(1+0.25);//aici e si adaosul pe manopera de 25%
    return final;

}





