#include "enseignant.h"

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QDate>

enseignant::enseignant()
{
    ID_EN = 0;
    nom = " " ;
    prenom = " " ;
    date_e.currentDate();
    specialite = " " ;
    telephone = 0 ;
    email = " " ;
}

enseignant::enseignant(int ID_EN ,QString nom ,QString prenom ,QDate date_e,QString specialite, int telephone, QString email)
{
    this->ID_EN = ID_EN ;
    this->nom = nom ;
    this->prenom = prenom ;
    this->date_e = date_e ;
    this->specialite = specialite ;
    this->telephone = telephone ;
    this->email = email ;
}

int enseignant::getIde()
{return ID_EN; }
void enseignant::setIde(int ID_EN )
{ this->ID_EN = ID_EN ;}


QString enseignant::getNom_e()
{return nom ; }
void enseignant::setNom_e(QString nom)
{this->nom = nom ;}

QString enseignant::getPrenom_e()
{return prenom ; }
void enseignant::setPrenom_e(QString prenom)
{this->prenom = prenom ;}

QDate  enseignant::getdate_e()
{return date_e ; }
void  enseignant::setdate_e(QDate date_e)
{ this->date_e = date_e ;}


QString enseignant::getspec()
{return specialite ; }
void enseignant::setspec(QString specialite)
{this->specialite = specialite ;}


int  enseignant::gettel()
{return telephone ; }
void  enseignant::settel(int telephone)
{ this->telephone = telephone ;}
//getter w setter lel phone

QString  enseignant::getemail()
{return email ; }
void  enseignant::setemail(QString email )
{this->email = email ; }





bool enseignant::ajouter()
{
    QSqlQuery query;
    QString id_string = QString::number(ID_EN);
    QString tel_string = QString::number(telephone);

    query.prepare("INSERT INTO ENSEIGNANT (ID_EN, NOM, PRENOM, DATE_E, SPECIALITE, TELEPHONE, EMAIL) "
                  "VALUES (:ID_EN, :nom, :prenom, :date_e, :specialite, :telephone, :email)");
    query.bindValue(":ID_EN", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_e", date_e);
    query.bindValue(":specialite", specialite);
    query.bindValue(":telephone", tel_string);
    query.bindValue(":email", email);

    return query.exec();
}

QSqlQueryModel* enseignant::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM ENSEIGNANT");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("specialité"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Tel"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));


  return model;}


bool enseignant::modifier(int ID_EN ,QString nom ,QString prenom ,QDate date_e,QString specialite, int telephone, QString email)
{
    QSqlQuery query;
    QString id_string = QString::number(ID_EN);
    QString tel_string = QString::number(telephone);

          query.prepare("update ENSEIGNANT set ID_EN=:ID_EN, nom=:nom, prenom=:prenom, date_e=:date_e, specialite=:specialite, telephone=:telephone, email=:email where ID_EN=:ID_EN");
          query.bindValue(":ID_EN", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":date_e", date_e);
          query.bindValue(":specialite", specialite);
          query.bindValue(":telephone", tel_string);
          query.bindValue(":email", email);

  return query.exec();
}

bool enseignant::supprimer(int ID_EN)
{
    QSqlQuery query;
    QString id_string=QString::number(ID_EN);

          query.prepare(" Delete from ENSEIGNANT where ID_EN=:ID_EN");
          query.bindValue(0, id_string);



    return query.exec();
}





QSqlQueryModel * enseignant::trie_ID_en()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM ENSEIGNANT ORDER BY ID_EN ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("specialité"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Tel"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

    return model;
}
QSqlQueryModel * enseignant::trie_Nom_en()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM ENSEIGNANT ORDER BY NOM ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("specialité"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Tel"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

    return model;
}
QSqlQueryModel * enseignant::trie_Spec()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM ENSEIGNANT ORDER BY SPECIALITE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("specialité"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Tel"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

    return model;
}
