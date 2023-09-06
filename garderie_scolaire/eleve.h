#ifndef ELEVE_H
#define ELEVE_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QDate>

class ELEVE
{
public:
    ELEVE();
    ELEVE(int,QString,QString,QDate,int,QString) ;
      int getId() ;
     void setId(int);

     QString getNom();
     void setNom(QString);

     QString getPrenom() ;
     void setPrenom(QString);

     QDate getNaissance();
     void setNaissance(QDate);

     int getAge() ;
     void setAge (int);

     QString getClasse() ;
     void setClasse(QString);



      bool ajouter();
      QSqlQueryModel* afficher();
      bool modifier(int,QString,QString,QDate,int,QString) ;
      bool supprimer (int) ;




      QSqlQueryModel * trie_ID_el();
      QSqlQueryModel * trie_NOM();
      QSqlQueryModel * trie_Classe();


private :


    int ID_EL ;
    QString nom ;
    QString prenom ;
    QDate naissance  ;
    int age ;
    QString classe ;

};

#endif // ELEVE_H
