#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_createAccountButton_clicked();

private:
    Ui::SignUp *ui;
    void accountStore(QString, QString);
    QSqlDatabase db;
};

#endif // SIGNUP_H
