#ifndef HOTEL_LOBBY_H
#define HOTEL_LOBBY_H

#include <QDialog>
#include <QDebug>
#include <QPixmap>
#include <QLabel>

namespace Ui {
class Hotel_Lobby;
}

class Hotel_Lobby : public QDialog
{
    Q_OBJECT

public:
    explicit Hotel_Lobby(QWidget *parent = nullptr);
    ~Hotel_Lobby();

private slots:
    void on_lotteryButton_clicked();

private:
    void insertPicture(const QString &fileName, int x, int y, int width, int height);
    Ui::Hotel_Lobby *ui;
};

#endif // HOTEL_LOBBY_H
