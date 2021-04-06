#include "addcustomer.h"
#include "ui_addcustomer.h"
#include "QtWidgets"
addCustomer::addCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCustomer)
{
    ui->setupUi(this);
    centerAndResize();
    loadDatabase();
}






void addCustomer::centerAndResize() {
    // get the dimension available on this screen
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();
    width *= 0.55; // 35% din rezoultie
    height *= 0.55; // 55% din rezolutie
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



addCustomer::~addCustomer()
{
    delete ui;
}



void addCustomer::on_tableView_activated(const QModelIndex &index)
{

}
void addCustomer::loadDatabase(){
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQueryModel *model = new QSqlQueryModel();
    m_db.setDatabaseName("C:/Users/Nita/Desktop/Nico2/db.sqlite");
    //m_db.setDatabaseName("C:/Users/JohnDoe/Documents/Nico2/db.sqlite");
    if (!m_db.open())
    {
      qDebug() << "Error: connection with database failed";
    }
    else
    {
      qDebug() << "Database: connection ok";
    }
    QSqlQuery *qry = new QSqlQuery();
    qry->prepare("select * from customer");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

}
void addCustomer::on_saveCustomer_clicked()
{
        QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
        //m_db.setDatabaseName("C:/Users/Nita/Desktop/Nico/db.sqlite");
        m_db.setDatabaseName("C:/Users/JohnDoe/Documents/Nico2/db.sqlite");

        if (!m_db.open())
           {
              qDebug() << "Error: connection with database failed";
           }
           else
           {
              qDebug() << "Database: connection ok";
           }

        QString company, cui, bank, iban, country, phone, email, address;

        company=ui->companyNameLe->text();
        cui = ui->cuiLe->text();
        bank = ui->bankLe->text();

        iban = ui->ibanLe->text();
        country = ui->countryLe->text();
        phone = ui->phoneLe->text();
        email = ui->emaiLe->text();
        address = ui->addressLe->text();

        QSqlQuery *qry = new QSqlQuery();
        qry->prepare("insert into customer(company, cui, bank, iban, country,phone, email, address) values(:company, :cui, :bank, :iban, :country, :phone, :email, :address)");
        qry->bindValue(":company", company);
        qry->bindValue(":cui", cui);
        qry->bindValue(":bank", bank);
        qry->bindValue(":iban", iban);
        qry->bindValue(":country", country);
        qry->bindValue(":phone", phone);
        qry->bindValue(":email", email);
        qry->bindValue(":address", address);



        if(qry->exec()){
            QMessageBox::critical(this, tr("SAVE"),tr("SAVED"));
            loadDatabase();
        }
        else{
            QMessageBox::critical(this, tr("error: "), qry->lastError().text());
        }

}

