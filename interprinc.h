#ifndef INTERPRINC_H
#define INTERPRINC_H

#include <QDialog>
namespace Ui {
class interprinc;
}

class interprinc : public QDialog
{
    Q_OBJECT

public:
    explicit interprinc(QWidget *parent = nullptr);
    ~interprinc();

private slots:
    void on_pushButton_clicked();
    
private:
    Ui::interprinc *ui;
    QString username;
    QString password;

};

#endif // INTERPRINC_H
