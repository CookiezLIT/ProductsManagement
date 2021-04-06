#ifndef VIEWORDER_H
#define VIEWORDER_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QDebug>
#include <QString>
#include "order.h"
#include "connect.h"



namespace Ui {
class viewOrder;
}

class viewOrder : public QDialog
{
    Q_OBJECT

public:
    explicit viewOrder(QWidget *parent = nullptr);
    ~viewOrder();

public: QSqlTableModel *model;

private slots:


private:
    Ui::viewOrder *ui;
};

#endif // VIEWORDER_H
