#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <QDialog>
#include <QTableView>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class Administration;
}

class Administration : public QDialog
{
    Q_OBJECT

public:
    explicit Administration(QWidget *parent = nullptr);
    ~Administration();

private slots:
    void on_accountsButton_clicked();

private:
    Ui::Administration *ui;
};

#endif // ADMINISTRATION_H
