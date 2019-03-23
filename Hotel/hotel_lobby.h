#ifndef HOTEL_LOBBY_H
#define HOTEL_LOBBY_H

#include <QDialog>

namespace Ui {
class Hotel_Lobby;
}

class Hotel_Lobby : public QDialog
{
    Q_OBJECT

public:
    explicit Hotel_Lobby(QWidget *parent = nullptr);
    ~Hotel_Lobby();

private:
    Ui::Hotel_Lobby *ui;
};

#endif // HOTEL_LOBBY_H
