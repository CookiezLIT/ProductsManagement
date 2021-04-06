#include "mainwindow.h"
#include <QSqlTableModel>

#include <QApplication>
#include "pricecalculation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /*if(!createConnection())
        return 1*/;
    MainWindow w;
    //TableEditor editor("customer");


    //TableEditor editorOrder("order");

    w.show();

    //editor.show();
    //editorOrder.show();


    return a.exec();
}
