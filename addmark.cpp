#include "addmark.h"
#include "ui_addmark.h"
#include "QtWidgets"
#include "operation.h"
#include "mark.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
addMark::addMark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMark)
{
    ui->setupUi(this);
    QVector <operation> vec;
    QVector <mark> markvec;

}

void addMark::handlePriceCalculationBtn()
{
    addCalculationWindow = new priceCalculation();
    addCalculationWindow->show();
}

void addMark::handleViewTotalPriceBtn()
{
    viewTotalPriceWindow = new viewPrice();
    viewTotalPriceWindow->show();
}

QVector <mark> addMark::getMarks()
{
    return markvec;
}

addMark::~addMark()
{
    delete ui;
}

void addMark::on_groupBox_clicked()
{

}


void addMark::on_priceBtn_clicked()
{

}

void addMark::on_addOperation_clicked()
{
    int numberOfOperations = ui->nrOperationSb->value();
    numberOfOperations++;
    QString operationName = ui->operationNameLe->text();
    int operationTime = ui->operationTimeSb->value();
    int operationPrice = ui->operationPriceSb->value();

    const operation *x = new operation(operationName,operationTime, operationPrice);
    vec.append(*x);
    ui->nrOperationSb->setValue(numberOfOperations);

}

void addMark::on_saveMarkBtn_clicked()
{
    double price;
    QString code = ui->codeLe->text();
    QString name = ui->nameLe->text();
    int qty = ui->qtySb->value();
    int weight = ui->weightSb->value();
    QString shape = ui->shapeLe->text();
    qDebug() << shape;
    QString dimension = ui->dimensionLe->text();
    QString material = ui->materialLe->text();
    QVector <double> dimensions;
    QString shape1 = shape;
    int order_number = ui->orderNumber->value();
    //Dimensiuni pentru fiecare forma in parte
    QStringList lst = dimension.split(',');
    if (shape == "corniera")
    {
        dimensions.append(lst[0].toDouble()); //h1
        dimensions.append(lst[1].toDouble()); //h2
        dimensions.append(lst[2].toDouble()); //T
        dimensions.append(lst[3].toDouble()); //L
    }
    else if(shape == "rotund")
    {
        dimensions.append(lst[0].toDouble()); //fi
        dimensions.append(lst[1].toDouble()); //L
    }
    else if(shape == "patrat")
    {
        dimensions.append(lst[0].toDouble()); //l
        dimensions.append(lst[1].toDouble()); //H
        dimensions.append(lst[2].toDouble()); //L
    }
    else if (shape == "teava_rotunda")
    {
        dimensions.append(lst[0].toDouble()); //fi
        dimensions.append(lst[0].toDouble()); //T
        dimensions.append(lst[0].toDouble()); //L
    }
    else
    {
        qDebug() << "ERoare";
    }
    mark *m = new mark(code,name,qty,weight,shape,dimensions,material,vec);
    markvec.append(*m);

    //calcularea pretului
    priceCalculation *calculator = new priceCalculation();
    price = calculator->finalPrice(*m);

    QString priceString = QString::number(price);

    //string priceSring = to_string(price);

    //ui->priceLe->finalPrice(*m);
    ui->priceLe->setText(priceString);
    ui->priceLe->setReadOnly(true);
    qDebug() << price;

    //salvare in baza de date
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    //m_db.setDatabaseName("C:/Users/Nita/Desktop/Nico2/db.sqlite");
    m_db.setDatabaseName("C:/Users/JohnDoe/Documents/Proiect/Nico/db.sqlite");

    if (!m_db.open())
       {
          qDebug() << "Error: connection with database failed";
       }
       else
       {
          qDebug() << "Database: connection mark ok";
       }
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("INSERT INTO marks(Cod,Denumire,Bucati,Greutate_reper,Forma,Dimensiuni,Material,Nr_Comanda,Pret) VALUES (:Cod,:Denumire,:Bucati,:Greutate,:Forma,:Dimensiuni,:Material,:Nr_Comanda,:Pret)");
    qry->bindValue(":Cod",code);
    qry->bindValue(":Denumire",name);
    qry->bindValue(":Bucati",qty);
    qry->bindValue(":Greutate",weight);
    qry->bindValue(":Forma",shape1);
    qry->bindValue(":Dimensiuni",dimension);
    qry->bindValue(":Material",material);
    qry->bindValue(":Nr_Comanda",order_number);
    qry->bindValue(":Pret",price);

    //qDebug()<<shape;

    if(qry->exec()){
        QMessageBox::critical(this, tr("SAVE"),tr("SAVED"));

    }
    else{
        QMessageBox::critical(this, tr("error: "), qry->lastError().text());
    }
}

void addMark::closeEvent(QCloseEvent *event)
{
    if(addMark::closeWindow())
        event->accept();
    else
        event->ignore();
}

bool addMark::closeWindow()
{
    if(!isWindowModified())
        return true;

    QMessageBox::StandardButton answer = QMessageBox::question(
                this,
                tr("Inchide fereastra"),
                tr("Vrei sa inchizi fereastra?"),
                QMessageBox::Yes | QMessageBox::No);

    return answer == QMessageBox::Yes;
}

void addMark::on_addNewMark_clicked()
{
    ui->codeLe->clear();
    ui->nameLe->clear();
    ui->qtySb->clear();
    ui->weightSb->clear();
    ui->shapeLe->clear();
    ui->dimensionLe->clear();
    ui->materialLe->clear();
    ui->operationNameLe->clear();
    ui->operationTimeSb->clear();
    ui->operationPriceSb->clear();
    ui->nrOperationSb->clear();
    ui->priceLe->clear();




}

void addMark::on_priceLe_cursorPositionChanged(int arg1, int arg2)
{

}
