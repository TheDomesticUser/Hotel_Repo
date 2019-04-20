#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QSettings>
#include <QSqlDatabase>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    bool connectToDatabase(QString database, QString databaseName, QString user, QString pass, QString host, int port);

    void closeDatabase();

private slots:
    void on_signUpButton_clicked();

    void on_logInButton_clicked();

private:
    Ui::Widget *ui;
    int totalUsers = 0;
    QSqlDatabase db;
};

#endif // WIDGET_H
