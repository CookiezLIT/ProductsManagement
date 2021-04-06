#ifndef VIEWSTOCKS_H
#define VIEWSTOCKS_H

#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>

namespace Ui {
class viewStocks;
}

class viewStocks : public QDialog
{
    Q_OBJECT

public:
    explicit viewStocks(QWidget *parent = nullptr);
    ~viewStocks();
    void loadDatabase();
private slots:


private:
    Ui::viewStocks *ui;

};

#endif // VIEWSTOCKS_H
