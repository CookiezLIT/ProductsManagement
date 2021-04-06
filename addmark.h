#ifndef ADDMARK_H
#define ADDMARK_H

#include <QDialog>
#include "pricecalculation.h"
#include "viewprice.h"
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
using namespace std;

namespace Ui {
class addMark;
}

class addMark : public QDialog
{
    Q_OBJECT

public:
    explicit addMark(QWidget *parent = nullptr);
    ~addMark();
    QVector <operation> vec;
    QVector <mark> markvec;
    QVector <mark> getMarks();
    bool closeWindow();
private slots:
    void handlePriceCalculationBtn();
    void handleViewTotalPriceBtn();

    void on_groupBox_clicked();

    void on_priceBtn_clicked();

    void on_saveMarkBtn_clicked();

    void on_addOperation_clicked();

    void closeEvent(QCloseEvent *event);

    void on_addNewMark_clicked();

    void on_priceLe_cursorPositionChanged(int arg1, int arg2);

private:
    priceCalculation *addCalculationWindow;
    viewPrice *viewTotalPriceWindow;
signals:
    void emitsignall();
private:
    Ui::addMark *ui;
};

#endif // ADDMARK_H
