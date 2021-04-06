#ifndef PRICECALCULATION_H
#define PRICECALCULATION_H

#define _USE_MATH_DEFINES
#include <QMetaEnum>
#include "mark.h"
#include <cmath>
#include "operation.h"



#include <QDialog>

namespace Ui {
class priceCalculation;
}

class priceCalculation : public QDialog
{
    Q_OBJECT
    Q_ENUMS(profileCases)
    Q_ENUMS(materialCases)


public:
    explicit priceCalculation(QWidget *parent = nullptr);
    ~priceCalculation();
    void testMaterialprice();
public:

public:
    enum profileCases
    {
        corniera, rotund, teava_rotunda, patrat
    };

    enum materialCases
    {
        otel, aluminiu, inox, cupru, plastic
    };

public:
    double switchMarkString(mark m);
    double volumePrice(mark m);
    double materialPrice(mark m);
    double totalOperationPrice(mark m);
    double treatmentsPrice(mark m);
    double manufacturePrice(mark m);
    double finalPrice(mark m);



private:
    Ui::priceCalculation *ui;
};

#endif // PRICECALCULATION_H
