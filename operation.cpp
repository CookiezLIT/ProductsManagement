#include "operation.h"

operation::operation()
{

}


double operation::getTotalPrice(QString time, double price){
    double num, totalPrice;
    num = time.toDouble();
    totalPrice = num*price;
    return totalPrice;

}
