#ifndef CONNECTIONFACTORY_H
#define CONNECTIONFACTORY_H
#include <QSqlDatabase>


class ConnectionFactory
{
    public:
        void openConnection();
        void closeConnection();
};

#endif // CONNECTIONFACTORY_H
