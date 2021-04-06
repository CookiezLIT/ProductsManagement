
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>



MainWindow::MainWindow(QWidget *parent)
{
    this->setWindowTitle("Fereastra principala");
    centerAndResize();
    QWidget *wdg = new QWidget(this);
    QPushButton *addCustomerBtn = new QPushButton("Adaugare client");
    QPushButton *addOrderBtn = new QPushButton("Adaugare comanda");
    QPushButton *viewStocksBtn = new QPushButton("Vizualizare stocuri");
    QPushButton *viewFinalProductsBtn = new QPushButton("Vizualizare produse finite");

    QVBoxLayout *vlay = new QVBoxLayout(wdg);

//    QHBoxLayout *clients = new QHBoxLayout();
//    clients->addWidget(addCustomerBtn);


//    QHBoxLayout *order = new QHBoxLayout();
//    order->addWidget(addOrderBtn);

//    QHBoxLayout *products = new QHBoxLayout();
//    products->addWidget(viewStocksBtn);
//    products->addWidget(viewFinalProductsBtn);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(addCustomerBtn);
    layout->addWidget(addOrderBtn);
    layout->addWidget(viewStocksBtn);
    layout->addWidget(viewFinalProductsBtn);


//    vlay->addLayout(clients);
//    vlay->addLayout(order);
//    vlay->addLayout(products);
    vlay->addLayout(layout);
    vlay->setContentsMargins(1,1,1,1);
    vlay->addSpacing(12);
    wdg->setLayout(vlay);
    setCentralWidget(wdg);

    connect(addCustomerBtn, SIGNAL (released()), this, SLOT (handleAddCustomerBtn()));
    connect(addOrderBtn, SIGNAL (released()), this, SLOT (handleAddOrderBtn()));
    connect(viewStocksBtn, SIGNAL (released()), this, SLOT (handleViewStocksBtn()));
    connect(viewFinalProductsBtn, SIGNAL (released()), this, SLOT (handleViewFinalProductsBtn()));
}

void MainWindow::handleAddCustomerBtn(){
    addCustomerWindow = new addCustomer();
    addCustomerWindow->show();


}






void MainWindow::handleAddOrderBtn(){
    addOrderWindow = new addOrder();
    addOrderWindow->show();
}



void MainWindow::handleViewStocksBtn(){
    viewStocksWindow = new viewStocks();
    viewStocksWindow->show();
}

void MainWindow::handleViewFinalProductsBtn(){
    viewFinalProductsWindow = new viewFinalProducts();
    viewFinalProductsWindow->show();
}

void MainWindow::centerAndResize() {
    // get the dimension available on this screen
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();
    width *= 0.35; // 35% din rezoultie
    height *= 0.35; // 35% din rezolutie
    QSize newSize( width, height );

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            newSize,
            qApp->desktop()->availableGeometry()
        )
    );
}

//void DatabaseConnect(){
//    initDB *db = new initDB();
//    if(db->DatabaseConnect())
//        qDebug() << "last error";
//}





MainWindow::~MainWindow()
{
    delete ui;
}

