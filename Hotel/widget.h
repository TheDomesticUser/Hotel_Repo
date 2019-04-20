#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QSettings>

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
};

#endif // WIDGET_H
