#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//added

#include "addcustomer.h"
#include "addorder.h"
#include "viewstocks.h"
#include "viewfinalproducts.h"
#include "connect.h"
#include "tableeditor.h"
#include "initdb.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void centerAndResize();
    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();
    ~MainWindow();

private slots:
    void handleAddCustomerBtn();
    void handleAddOrderBtn();
    void handleViewStocksBtn();
    void handleViewFinalProductsBtn();

private:
    addCustomer *addCustomerWindow;
    addOrder *addOrderWindow;
    viewStocks *viewStocksWindow;
    viewFinalProducts *viewFinalProductsWindow;


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
