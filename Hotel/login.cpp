#include "login.h"
#include "ui_login.h"
#include "hotel_lobby.h"
#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);

    ui->placeholderTextLabel->setText(nullptr);
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_loginButton_clicked()
{
    Widget *widget = new Widget;
    Hotel_Lobby *hotel_lobby = new Hotel_Lobby;
    QString databaseName = "hotel";

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    {
        QSqlDatabase db = widget->createDatabase("QMYSQL", databaseName, "login_conn", "root", "incorrect", "localhost", 3306);

        db.open();

        // Iterates through the usernames and passwords, checking if any of them match the user's input
        if (!db.isOpen()) {
            QMessageBox::critical(this, "Error", "The database failed to connect!");
        } else {
            QSqlQuery query(db);
            query.prepare(QString("SELECT username, password FROM account WHERE username = '%1' AND password = '%2'")
                          .arg(username).arg(password));

            if (query.exec())
            {
                if (query.size() > 0)
                {
                    hotel_lobby->show();
                    this->hide();
                    widget->hide();
                } else {
                    ui->placeholderTextLabel->setText("The username or password you inputted was incorrect!");
                }
            }
        }
        db.close();
    }
    QSqlDatabase::removeDatabase("login_conn");
}
