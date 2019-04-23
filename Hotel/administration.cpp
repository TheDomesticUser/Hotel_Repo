#include "administration.h"
#include "ui_administration.h"
#include "starting_menu.h"
#include <QFile>
#include <QDebug>

Administration::Administration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administration)
{
    ui->setupUi(this);
}

Administration::~Administration()
{
    delete ui;
}

void Administration::on_accountsButton_clicked()
{
    if (QSqlDatabase::database("admin_conn").isOpen())
        QSqlDatabase::removeDatabase("admin_conn");
    starting_menu *menu = new starting_menu;
    {
        QSqlQueryModel *queryModel = new QSqlQueryModel;
        QSqlDatabase db = menu->createDatabase("QMYSQL", "hotel", "admin_conn", "root", "incorrect", "localhost", 3306);
        db.open();

        QSqlQuery *query = new QSqlQuery(db);
        query->prepare("SELECT * FROM account");

        if (query->exec())
        {
            queryModel->setQuery(*query);
            ui->hotelTableView->setModel(queryModel);
        }

        db.close();
    }
}
