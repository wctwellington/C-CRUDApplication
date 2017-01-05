#include "connectionfactory.h"
#include <QDebug>
#include <QSqlError>

QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");

void ConnectionFactory::openConnection() {

    database.setHostName("localhost");
    database.setDatabaseName("Escola");
    database.setUserName("postgres");
    database.setPassword("123");

    if (!database.open()) {
       qDebug() << database.lastError();
       qFatal("Conexão falhou!!!");
    } else {
        qDebug() << "Conexão realizada com sucesso";
    }
}

void ConnectionFactory::closeConnection() {
    database.close();
}
