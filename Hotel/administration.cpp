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

    connName = "admin_conn";

    starting_menu *menu = new starting_menu;
    menu->createDatabase("QMYSQL", "hotel", connName, "root", "incorrect", "localhost", 3306);

    // Connect the databases to the buttons
    connect(ui->accountsButton, &QPushButton::clicked, [&](){
        openDatabase(connName, "SELECT * FROM account");
    });

    connect(ui->cashAmountButton, &QPushButton::clicked, [&](){
        openDatabase(connName, "SELECT * FROM amount_of_cash");
    });
}

Administration::~Administration()
{
    delete ui;
}

void Administration::openDatabase(QString connName, QString executeStatement)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel;
    QSqlDatabase db = QSqlDatabase::database(connName);
    if (!db.isOpen()) db.open();

    QSqlQuery *query = new QSqlQuery(db);
    query->prepare(executeStatement);

    if (query->exec())
    {
        queryModel->setQuery(*query);
        ui->hotelTableView->setModel(queryModel);
    }
    db.close();
}
