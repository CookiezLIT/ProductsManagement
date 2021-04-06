#ifndef VIEWFINALPRODUCTS_H
#define VIEWFINALPRODUCTS_H

#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>

namespace Ui {
class viewFinalProducts;
}

class viewFinalProducts : public QDialog
{
    Q_OBJECT

public:
    explicit viewFinalProducts(QWidget *parent = nullptr);
    ~viewFinalProducts();
    void loadDatabase();
private slots:

private:
    Ui::viewFinalProducts *ui;
};

#endif // VIEWFINALPRODUCTS_H
