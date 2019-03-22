#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QSettings>

class Login;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_signUpButton_clicked();

    void on_logInButton_clicked();

private:
    Ui::Widget *ui;
    int totalUsers = 0;
    QVector<Login> accounts;
};

class Login
{
private:
    QString username;
    QString password;
public:
    QString returnUsername() { return username; }
    QString returnPassword() { return password; }
};

#endif // WIDGET_H
