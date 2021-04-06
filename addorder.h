 #ifndef ADDORDER_H
#define ADDORDER_H

#include <QDialog>
#include "addmark.h"
#include "viewmark.h"
#include <QLabel>
#include "Hider.h"
#include "genoffert.h"
#include <QtWidgets>
#include <QPrinter>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QErrorMessage>
#include <QSqlError>


namespace Ui {
class addOrder;
}

class addOrder : public QDialog
{
    Q_OBJECT
    QWidget *wdg1;
    QDialogButtonBox m_btn;
    Q_SLOT void on_hide_clicked(){hider.hide(wdg1); }

public:
    explicit addOrder(QWidget *parent = nullptr);
    void centerAndResize();
    Hider hider;
    ~addOrder();
    QVector <mark> marksvector;
    int price;
private slots:
    void handleAddMarkBtn();
    void handleViewMarkBtn();
    void handleOffertBtn();

    void on_groupBox_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_adRep_clicked();

    void on_saveOr_clicked();

    void on_genOffert_clicked();

    void on_viewCrtMark_clicked();

private:
    addMark *addMarkWindow;
    viewMark *viewMarkWindow;
    genOffert *offertWindow;

protected:
    void closeEvent(QCloseEvent *event);

private:
    bool closeWindow();
    QLabel *label;
    Ui::addOrder *ui;
};

#endif // ADDORDER_H
