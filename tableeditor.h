#ifndef TABLEEDITOR_H
#define TABLEEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlError>

namespace Ui {
class TableEditor;
}

class TableEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TableEditor(const QString &tableName, QWidget *parent = nullptr);


private slots:
    void submit();
private:
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
    QSqlTableModel *modelOrder;


private:
    Ui::TableEditor *ui;
};

#endif // TABLEEDITOR_H
