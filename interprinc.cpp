#include "interprinc.h"
#include "ui_interprinc.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include<QSystemTrayIcon>
#include "mainwindow.h"
interprinc::interprinc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interprinc)
{
    ui->setupUi(this);
    this->setWindowTitle("login");

}


interprinc::~interprinc()
{
    delete ui;
}

void interprinc::on_pushButton_clicked()
{
    MainWindow w;

    QSqlQuery query;
        QString select = "SELECT * FROM COMPTES WHERE LOGIN_ID=? AND LOGIN_PASS=?";
       // qDebug() << select;
        query.prepare(select);
        query.addBindValue(ui->lineEdit->text());
        query.addBindValue(ui->lineEdit_2->text());
     query.exec();
     if (query.exec())
          {

              if (query.next())
              {  qDebug() << "mmm";
                  hide();
              }
                      else
                       {
                           qDebug() << "Login failed. Invalid username or password.";
                       }
                   }
}


