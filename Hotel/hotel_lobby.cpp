#include "hotel_lobby.h"
#include "ui_hotel_lobby.h"

Hotel_Lobby::Hotel_Lobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hotel_Lobby)
{
    ui->setupUi(this);
}

Hotel_Lobby::~Hotel_Lobby()
{
    delete ui;
}
