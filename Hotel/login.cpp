#include "login.h"
#include "ui_login.h"
#include "hotel_lobby.h"

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_loginButton_clicked()
{
    Hotel_Lobby *hotel_lobby = new Hotel_Lobby;
    hotel_lobby->exec();
    this->hide();
}
