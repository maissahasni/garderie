#include "connection.h"
#include <QDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("soumaya");//inserer le nom de la source de données ODBC
db.setUserName("soumaya");//inserer nom de l'utilisateur
db.setPassword("soumaya16");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
qDebug()<< "connection : " << test;
 return  test;
}
void Connection::closeConnection(){db.close();}
