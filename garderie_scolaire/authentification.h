#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>


class authentification
{
public:
    authentification();
    authentification(QString,QString) ;


     QString getuser();
     void setuser(QString);

     QString getpass() ;
     void setpass(QString);



     bool ajouter();
     QSqlQueryModel* afficher();
     bool modifier(QString,QString) ;
     bool supprimer (QString) ;



     QSqlQueryModel * trie_User();
     QSqlQueryModel * trie_Pass();


private :
     QString username ;
     QString password ;
};

#endif // AUTHENTIFICATION_H
