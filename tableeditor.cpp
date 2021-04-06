#include "tableeditor.h"
#include "ui_tableeditor.h"

TableEditor::TableEditor(const QString &tableName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableEditor)
{
    ui->setupUi(this);
    //client
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0,Qt::Horizontal, tr("Company"));
    model->setHeaderData(1,Qt::Horizontal, tr ("CUI"));
    model->setHeaderData(2, Qt::Horizontal, tr("Bank"));
    model->setHeaderData(3, Qt::Horizontal, tr("IBAN"));
    model->setHeaderData(4,Qt::Horizontal, tr("Country"));
    model->setHeaderData(5, Qt::Horizontal, tr("Phone"));
    model->setHeaderData(6, Qt::Horizontal, tr("Email"));
    model->setHeaderData(7, Qt::Horizontal, tr("Address"));

    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();

    submitButton = new QPushButton(tr("Submit"));
    submitButton->setDefault(true);
    revertButton = new QPushButton(tr("&Revert"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(submitButton, &QPushButton::clicked, this, &TableEditor::submit);
    connect(revertButton, &QPushButton::clicked, model, &QSqlTableModel::revertAll);
    connect(quitButton, &QPushButton::clicked, this, &TableEditor::close);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("Cached Table"));



    //comanda
    modelOrder = new QSqlTableModel(this);
    modelOrder->setTable(tableName);
    modelOrder->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelOrder->select();


    modelOrder->setHeaderData(0,Qt::Horizontal, tr("no. Order"));
    modelOrder->setHeaderData(1,Qt::Horizontal, tr("Company"));
    modelOrder->setHeaderData(2,Qt::Horizontal, tr("Respponsible"));
    modelOrder->setHeaderData(3,Qt::Horizontal, tr("Date"));
    modelOrder->setHeaderData(4,Qt::Horizontal, tr("Due Date"));

    QTableView *viewOrder = new QTableView;
    viewOrder->setModel(modelOrder);
    viewOrder->resizeColumnsToContents();

    mainLayout->addWidget(viewOrder);





}

void TableEditor::submit()
{
    model->database().transaction();
    if( model->submitAll()){
        model->database().commit();
    }
    else
    {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("Eroare in legatura cu baza de date: %1").arg(model->lastError().text()));
                                }
}
