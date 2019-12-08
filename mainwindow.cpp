#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include "connexion.h"
#include<QSqlDatabase>
#include <QDebug>
#include "carte.h"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableclient->setModel(tempclient.afficher());
    ui->lCIN->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajo_clicked()
{
    int CIN = ui->lCIN->text().toInt();
    QString nom= ui->lnom->text();
    QString prenom= ui->lprenom->text();
     QString adresse= ui->ladresse->text();

  Client c(CIN,nom,prenom,adresse);
  bool test=c.ajouter();
  qDebug()<< test;
  if(test)
{ui->tableclient->setModel(tempclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_sup_clicked()
{
    int CIN = ui->lCIN->text().toInt();
    bool test=tempclient.supprimer(CIN);
    if(test)
    {qDebug() << "mmm";
                ui->tableclient->setModel(tempclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}





void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_6->text().toInt();
    QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM tabeclient WHERE CIN='"+ui->lineEdit_6->text()+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));

 ui->tabrech->setModel(model);

}

void MainWindow::on_pushButton_3_clicked()
{


 int CIN = ui->lCIN->text().toInt();
 QString nom = ui->lnom->text();
 QString prenom = ui->lprenom->text();
 QString adresse = ui->ladresse->text();

       tempclient.modifier();
}

void MainWindow::on_pushButton_clicked()
{
    int numero_carte= ui->lineEdit->text().toInt();
  int CINc= ui->lineEdit_3->text().toInt();
    int point_de_fidelite= ui->lineEdit_2->text().toInt();

     QString type= ui->lineEdit_4->text();

 carte c(numero_carte ,CINc, point_de_fidelite , type);
  bool test=c.ajouter2();
  qDebug()<< test;
  if(test)
{ui->tablecarte->setModel(tmpc.afficher2());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("carte ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_lineEdit_7_textChanged()
{
    QString nom = ui->lineEdit_7->text();
    QString prenom =ui->lineEdit_7->text();
    ui->tableclient->setModel(tempclient.recherche2(nom,prenom));
}
