#include "widget.h"
#include "ui_widget.h"
#include "signup.h"
#include "login.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_signUpButton_clicked()
{
    SignUp *signUp = new SignUp(this);
    signUp->exec();
}

void Widget::on_logInButton_clicked()
{
    LogIn *logIn = new LogIn(this);
    logIn->exec();
}

// This returns a SQL database, accessing the query and information
QSqlDatabase Widget::createDatabase(QString db, QString dbName, QString connName,
                                    QString user, QString pass, QString host, int port)
{
    QSqlDatabase data = QSqlDatabase::addDatabase(db, connName);
    data.setDatabaseName(dbName);
    data.setUserName(user);
    data.setPassword(pass);
    data.setHostName(host);
    data.setPort(port);

    return data;
}
