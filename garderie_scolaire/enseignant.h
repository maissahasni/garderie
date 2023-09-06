#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QDate>

class enseignant
{
public:
    enseignant();
    enseignant(int,QString,QString,QDate,QString,int,QString) ;
      int getIde() ;
     void setIde(int);

     QString getNom_e();
     void setNom_e(QString);

     QString getPrenom_e() ;
     void setPrenom_e(QString);

     QDate getdate_e();
     void setdate_e(QDate);

     QString getspec() ;
     void setspec(QString);

     int gettel() ;
     void settel (int);

     QString getemail() ;
     void setemail(QString);

     bool ajouter();
     QSqlQueryModel* afficher();
     bool modifier(int,QString,QString,QDate,QString,int,QString) ;
     bool supprimer (int) ;




     QSqlQueryModel * trie_ID_en();
     QSqlQueryModel * trie_Nom_en();
     QSqlQueryModel * trie_Spec();



private :


    int ID_EN ;
    QString nom ;
    QString prenom ;
    QDate date_e  ;
    QString specialite ;
    int telephone ;
    QString email ;
};

#endif // ENSEIGNANT_H
