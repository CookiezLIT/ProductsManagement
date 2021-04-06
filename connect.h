#ifndef CONNECT_H
#define CONNECT_H


#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connect
{
public:
    connect();
    static bool createConnection();

};

#endif // CONNECT_H
