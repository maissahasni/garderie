#include "eleve.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QDate>

ELEVE::ELEVE()
{
    ID_EL = 0;
    nom = " " ;
    prenom = " " ;
    naissance.currentDate();
    age = 0 ;
    classe = " " ;
}
ELEVE::ELEVE(int ID_EL ,QString nom ,QString prenom ,QDate naissance,int age , QString classe)
{
    this->ID_EL = ID_EL ;
    this->nom = nom ;
    this->prenom = prenom ;
    this->naissance = naissance ;
    this->age = age ;
    this->classe = classe ;

}
int ELEVE::getId()
{return ID_EL; }
void ELEVE::setId(int ID_EL )
{ this->ID_EL = ID_EL ;}


QString ELEVE::getNom()
{return nom ; }
void ELEVE::setNom(QString nom)
{this->nom = nom ;}

QString ELEVE::getPrenom()
{return prenom ; }
void ELEVE::setPrenom(QString prenom)
{this->prenom = prenom ;}

QDate  ELEVE::getNaissance()
{return naissance ; }
void  ELEVE::setNaissance(QDate naissance)
{ this->naissance = naissance ;}


int  ELEVE::getAge()
{return age ; }
void  ELEVE::setAge(int age)
{ this->age = age ;}
//getter w setter lel age

QString  ELEVE::getClasse()
{return classe ; }
void  ELEVE::setClasse(QString classe )
{this->classe = classe ; }

bool ELEVE::ajouter()
{
    QSqlQuery query;
    QString id_string = QString::number(ID_EL);
    QString age_string = QString::number(age);

    query.prepare("INSERT INTO ELEVE (ID_EL, NOM, PRENOM, NAISSANCE, AGE, CLASSE) "
                  "VALUES (:id_el, :nom, :prenom, :naissance, :age, :classe)");
    query.bindValue(":id_el", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":naissance", naissance);
    query.bindValue(":age", age_string);
    query.bindValue(":classe", classe);

    return query.exec();
}
QSqlQueryModel* ELEVE::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM ELEVE");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Naissance"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Classe"));


  return model;}


bool ELEVE::modifier(int ID_EL ,QString nom ,QString prenom ,QDate naissance,int age , QString classe)
{
    QSqlQuery query;
    QString id_string = QString::number(ID_EL);
    QString age_string = QString::number(age);

          query.prepare("update ELEVE set id_el=:id_el, nom=:nom, prenom=:prenom, naissance=:naissance, age=:age, classe=:classe where id_el=:id_el");
          query.bindValue(":id_el", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":naissance", naissance);
          query.bindValue(":age", age_string);
          query.bindValue(":classe", classe);


  return query.exec();
}

bool ELEVE::supprimer(int ID_EL)
{
    QSqlQuery query;
    QString id_string=QString::number(ID_EL);

          query.prepare(" Delete from ELEVE where id_el=:id_el");
          query.bindValue(0, id_string);



    return query.exec();
}



QSqlQueryModel * ELEVE::trie_ID_el()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM ELEVE ORDER BY ID_EL ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Naissance"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Classe"));

    return model;
}
QSqlQueryModel * ELEVE::trie_NOM()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM ELEVE ORDER BY NOM ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Classe"));

    return model;
}
QSqlQueryModel * ELEVE::trie_Classe()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM ELEVE ORDER BY CLASSE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Classe"));

    return model;
}
