#include "carte.h"
#include "client.h"
carte::carte()
{

}
 carte::carte (int ,int , int , QString)
 {

 }
 int carte:: get_numero_carte() {return numero_carte;}


 int carte:: get_point_de_fidelite(){return  point_de_fidelite;}

 QString carte::get_type(){return type;}

bool carte ::ajouter2()

{QSqlQuery query;

query.prepare("INSERT INTO TABLECARTE (NUMERO_CARTE, POINT_DE_FIDELITE, CINC ,TYPE) "
                    "VALUES (:numero_carte, :point_de_fidelite, :CIN, :type)");
query.bindValue(":numero_carte",numero_carte);
query.bindValue(":point_de_fielite", point_de_fidelite);
query.bindValue(":CIN",CINc );
query.bindValue(":type",type);
return query.exec();
}

QSqlQueryModel * carte::afficher2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from tabeclient");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO_CARTE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("POINT_DE_FIDELITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CINC"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE"));
        return model;
}

