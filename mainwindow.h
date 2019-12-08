#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"client.h"
#include "interprinc.h"
#include "carte.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_ajo_clicked();

    void on_pushButton_sup_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();


    void on_lineEdit_7_textChanged();

private:
    Ui::MainWindow *ui;
    Client tempclient,tabrech;
    carte tmpc;
    interprinc *interprinc;
};

#endif // MAINWINDOW_H
