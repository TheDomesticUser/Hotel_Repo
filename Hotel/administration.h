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


private:
    QString connName;
    void openDatabase(QString connName, QString executeStatement);
    Ui::Administration *ui;
};

#endif // ADMINISTRATION_H
