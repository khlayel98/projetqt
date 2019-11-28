#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include "connexion.h"
#include<QSqlDatabase>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableclient->setModel(tempclient.afficher());
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
 ui->tabrech->setModel(tempclient.recherche( id));

}

void MainWindow::on_pushButton_3_clicked()
{
   QString txt="";

  ui->lCIN->clear();



        bool test=tempclient.modifier();
}
