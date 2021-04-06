#include "addorder.h"
#include "ui_addorder.h"
#include "QtWidgets"
#include "addmark.h"
#include <QLabel>
#include <pricecalculation.h>
#include <order.h>

addOrder::addOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addOrder)
{
    ui->setupUi(this);
    centerAndResize();

    QVector <mark> marksvector;
    int price;
    //setWindowModified(true);

}



void addOrder::handleAddMarkBtn(){
    addMarkWindow = new addMark();

    addMarkWindow->show();
}

void addOrder::handleViewMarkBtn(){
    viewMarkWindow = new viewMark();
    viewMarkWindow->show();
}

void addOrder::handleOffertBtn(){


}

void addOrder::centerAndResize() {
    // get the dimension available on this screen
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();
    width *= 0.9; // 35% din rezoultie
    height *= 0.9; // 55% din rezolutie
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


//inchiderea ferestrei dupa ce a fost modificata
void addOrder::closeEvent(QCloseEvent *event)
{
    if(addOrder::closeWindow())
        event->accept();
    else
        event->ignore();
}

bool addOrder::closeWindow()
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
addOrder::~addOrder()
{
    delete ui;
}

void addOrder::on_groupBox_clicked()
{

}

void addOrder::on_tableView_activated(const QModelIndex &index)
{

}

void addOrder::on_adRep_clicked()
{
    addMark view;
    view.setModal(true);
    view.exec();
}

void addOrder::on_saveOr_clicked()
{
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/Users/Nita/Desktop/Nico2/db.sqlite");
    //m_db.setDatabaseName("C:/Users/JohnDoe/Documents/Proiect/Nico/db.sqlite");

    if (!m_db.open())
       {
          qDebug() << "Error: connection with database failed";
       }
       else
       {
          qDebug() << "Database: connection order ok";
       }

    QString noOrder, company, responsible;
    QString date;

    noOrder = ui->noOrderLe->text();
    company = ui->companyLe->text();
    date = ui->dueDateLe->text();
    responsible = ui->responsibleLe->text();

    if(m_db.tables().contains(QLatin1String("order")))
        qDebug() << "exista";
    QSqlQuery *qry2 = new QSqlQuery(m_db);
    qry2->prepare("select * from order");
    if(!(qry2->exec()))
            QMessageBox::critical(this, tr("error"), qry2->lastError().text());


    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("INSERT INTO [order] ( Nr_Comanda, Firma, Data, Responsabil ) VALUES ( :Nr_Comanda, :Firma, :Data, :Responsabil );");
    qry->bindValue(":Nr_Comanda", noOrder);
    qry->bindValue(":Firma",company);
    qry->bindValue(":Data", date);
    qry->bindValue(":Responsabil", responsible);



    if(qry->exec()){
        QMessageBox::critical(this, tr("SAVE"),tr("SAVED"));

    }
    else{
        QMessageBox::critical(this, tr("error : "), qry->lastError().text());
        //aici pusca
    }


}

void addOrder::on_genOffert_clicked()
{
    offertWindow = new genOffert();

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()){fileName.append(".pdf");}

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml("<!DOCTYPE html>\n<html>\n<head>\n\t<title>Oferta</title>\n\t<style>\ntable, th, td {\n  border: 1px solid black;\n}\n</style>\n</head>\n<body>\n\t<p>Offer number: <strong>BTX392</strong></p>\n\t<p>Date: 24-07-2020</p>\n\t<p>Client: GORMET SRL</p>\n\t<p>CONTACT SC BRAINTRONIX SA:</p>\n\t<p>Phone: +40752136201</p>\n\t<p>Email: office@braintronix.eu</p>\n\t<table style=\"width:100%\">\n\t\t<tr>\n\t\t\t<th>Description</th>\n\t\t\t<th>Original price/piece</th>\n\t\t\t<th>Discount</th>\n\t\t\t<th>Final price/piece</th>\n\t\t\t<th>Quantity</th>\n\t\t\t<th>Total</th>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-389</td>\n\t\t\t<td>123.5</td>\n\t\t\t<td>0</td>\n\t\t\t<td>123.5</td>\n\t\t\t<td>34</td>\n\t\t\t<td>4199</td>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-38</td>\n\t\t\t<td>14.5</td>\n\t\t\t<td>0</td>\n\t\t\t<td>14.5</td>\n\t\t\t<td>22</td>\n\t\t\t<td>319</td>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-89</td>\n\t\t\t<td>22.5</td>\n\t\t\t<td>0</td>\n\t\t\t<td>22.5</td>\n\t\t\t<td>13</td>\n\t\t\t<td>244</td>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-22</td>\n\t\t\t<td>12</td>\n\t\t\t<td>0</td>\n\t\t\t<td>12</td>\n\t\t\t<td>3</td>\n\t\t\t<td>36</td>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-333</td>\n\t\t\t<td>4.56</td>\n\t\t\t<td>0</td>\n\t\t\t<td>4.56</td>\n\t\t\t<td>100</td>\n\t\t\t<td>456</td>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-41</td>\n\t\t\t<td>16</td>\n\t\t\t<td>25</td>\n\t\t\t<td>12</td>\n\t\t\t<td>5</td>\n\t\t\t<td>60</td>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-52</td>\n\t\t\t<td>150</td>\n\t\t\t<td>50</td>\n\t\t\t<td>100</td>\n\t\t\t<td>34</td>\n\t\t\t<td>3400</td>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-23</td>\n\t\t\t<td>22</td>\n\t\t\t<td>0</td>\n\t\t\t<td>22</td>\n\t\t\t<td>5</td>\n\t\t\t<td>110</td>\n\t\t</tr>\n\t\t<tr>\n\t\t\t<td>INDD 0000000391-66</td>\n\t\t\t<td>123.5</td>\n\t\t\t<td>0</td>\n\t\t\t<td>123.5</td>\n\t\t\t<td>34</td>\n\t\t\t<td>4199</td>\n\t\t</tr>\n\t</table>\n\t<p><strong>OFFER TOTAL:13023 EURO</strong></p>\n\t<p>Observations: <br> -All prices are expressed in EURO and do not include VAT. <br> -Please pay within 0 days. <br>-Offer valid for 30 days.</p>\n</body>\n<br>\n<br>\n<br>\n<footer>\n\t<p>IBAN(EURO):RO11BTLREURCRT12123222</p>\n\t<p>IBAN(RON):RO23BTLRONCRT3434334343</p>\n</footer>\t\n</html>");
    doc.print(&printer);


}

void addOrder::on_viewCrtMark_clicked()
{
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQueryModel *model = new QSqlQueryModel();
    m_db.setDatabaseName("C:/Users/Nita/Desktop/Nico2/db.sqlite");
    //m_db.setDatabaseName("C:/Users/JohnDoe/Documents/Proiect/Nico/db.sqlite");
    if (!m_db.open())
    {
      qDebug() << "Error: connection with database failed";
    }
    else
    {
      qDebug() << "Database: connection ok";
    }
    QSqlQuery *qry = new QSqlQuery();
    QString noOrder;
    noOrder = ui->noOrderLe->text();
    qry->prepare("select * from marks where Nr_Comanda =?");
    qry->addBindValue(ui->noOrderLe->text());
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

}
