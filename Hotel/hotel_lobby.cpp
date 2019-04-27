#include "hotel_lobby.h"
#include "ui_hotel_lobby.h"
#include <QPushButton>

Hotel_Lobby::Hotel_Lobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hotel_Lobby)
{
    ui->setupUi(this);

    // Set the lottery pixmap label to the lottery icon
    insertPicture("://Pictures/lottery_icon.png", 20, 20, 80, 80);
}

Hotel_Lobby::~Hotel_Lobby()
{
    delete ui;
}

void Hotel_Lobby::insertPicture(const QString &fileName, int x, int y, int width, int height)
{
    QLabel *label = new QLabel(this);
    label->setScaledContents(true);
    label->setPixmap(QPixmap(fileName));
    label->setGeometry(x, y, width, height);
}

void Hotel_Lobby::on_lotteryButton_clicked()
{

}
