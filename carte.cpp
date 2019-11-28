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
QString res= QString::number(numero_carte);
query.prepare("INSERT INTO TABLECARTE (NUMERO_CARTE, POINT_DE_FIDELITE, CINc ,TYPE) "
                    "VALUES (:numero_carte, :point_de_fidelite, :CIN, :type)");
query.bindValue(":NUMERO_CARTE",numero_carte);
query.bindValue(":point_de_fielite", point_de_fidelite);
query.bindValue(":CIN",CINc );
query.bindValue(":type",type);
return query.exec();
}

QSqlQueryModel * carte::afficher2()
{

}

