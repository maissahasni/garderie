#include "authentification.h"

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QDate>

authentification::authentification()
{
   username = " " ;
   password = " " ;
}
authentification::authentification(QString username ,QString password)
{
    this->username = username ;
    this->password = password ;

}


QString authentification::getuser()
{return username ; }
void authentification::setuser(QString username)
{this->username = username ;}



QString authentification::getpass()
{return password ; }
void authentification::setpass(QString password)
{this->password = password ;}


bool authentification::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO AUTH (USERNAME,PASSWORD) "
                  "VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    return query.exec();
}

QSqlQueryModel* authentification::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM AUTH");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Username"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Password"));


  return model;}


bool authentification::supprimer(QString)
{
    QSqlQuery query;

          query.prepare(" Delete from AUTH where username=:username");
          query.bindValue(0, username);

    return query.exec();
}

bool authentification::modifier(QString username ,QString password)
{
    QSqlQuery query;

          query.prepare("update AUTH set username=:username, password=:password where username=:username");
          query.bindValue(":username", username);
          query.bindValue(":password", password);

  return query.exec();
}


QSqlQueryModel * authentification::trie_User()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM AUTH ORDER BY USERNAME ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Username"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Password"));

    return model;
}
QSqlQueryModel * authentification::trie_Pass()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM AUTH ORDER BY PASSWORD ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Username"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Password"));

    return model;
}
