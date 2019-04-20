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

// This connects to a SQL database, accessing its query and information
bool Widget::connectToDatabase(QString database, QString databaseName, QString user, QString pass, QString host, int port)
{
    db = QSqlDatabase::addDatabase(database);
    db.setDatabaseName(databaseName);
    db.setUserName(user);
    db.setPassword(pass);
    db.setHostName(host);
    db.setPort(port);
    db.open();

    if (!db.isOpen()) return false;
    return true;
}

void Widget::closeDatabase()
{
    db.close();
}
