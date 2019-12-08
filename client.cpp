#include "Client.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "connexion.h"


Client::Client()
{
    nom="";
    prenom="";
    adresse="";
    CIN=0;

}

 Client ::Client (int CIN ,QString nom,QString prenom , QString adresse )
{
     this->CIN=CIN;
     this->nom=nom;
     this->prenom=prenom;
     this->adresse=adresse;
 }
 QString Client::get_nom()
 {
     return  nom;
 }
  QString Client::get_prenom()
  {
      return prenom;
  }
  int Client::get_CIN()
  {
      return CIN;
  }
  QString Client::get_adresse()
  {
      return adresse;
  }


bool Client::ajouter()
{
QSqlQuery query;
Connexion co;
//co.ouvrirConnexion();

QString res= QString::number(CIN);
query.prepare("INSERT INTO TABECLIENT (CIN, NOM, PRENOM ,ADRESSE) "
                    "VALUES (:CIN, :nom, :prenom, :adresse)");
query.bindValue(":CIN", CIN);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse",adresse);

return    query.exec();
}

QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from tabeclient");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    return model;
}

bool Client::supprimer(int CIN)
{    QSqlQuery query;

    Connexion co;

//    QString res= QString::number(CIN);
      query.prepare("Delete * from tabeclient WHERE CIN =:CIN ");
      query.bindValue(":CIN",CIN);
      return    query.exec();

}

bool Client::modifier()
 {      QSqlQuery query;
        query.prepare("update TABECLIENT set  NOM=:nom,PRENOM=:prenom,,ADRESSE=:adresse where CIN=:CIN");
      //  query.bindValue(":CIN",CIN);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":adresse", adresse);
        return    query.exec();

}



QSqlQueryModel * Client::recherche(int CIN)
{QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM tabeclient WHERE CIN=:CIN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
      return model;
}
QSqlQueryModel * Client:: recherche2(QString nom , QString prenom)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM tabeclient WHERE NOM like '"+nom+"%' or PRENOM like ' "+prenom+"%' " );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
      return model;


}
