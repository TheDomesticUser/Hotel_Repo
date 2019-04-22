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

    QSqlDatabase createDatabase(QString db, QString dbName, QString connName, QString user,
                                   QString pass, QString host, int port);

private slots:
    void on_signUpButton_clicked();

    void on_logInButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
