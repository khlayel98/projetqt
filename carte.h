#ifndef CARTE_H
#define CARTE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class carte
{
public:
    carte();
    carte (int,int,int,QString);
    int get_numero_carte();
    int get_point_de_fidelite();
    QString get_type();
    bool ajouter2();
    QSqlQueryModel * afficher2();
private:
    int numero_carte,point_de_fidelite,CINc;
    QString type;
};


#endif // CARTE_H
