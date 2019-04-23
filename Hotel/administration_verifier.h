#ifndef ADMINISTRATION_VERIFIER_H
#define ADMINISTRATION_VERIFIER_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Administration_verifier;
}

class Administration_verifier : public QDialog
{
    Q_OBJECT

public:
    explicit Administration_verifier(QWidget *parent = nullptr);
    ~Administration_verifier();

private slots:

    void on_submitButton_clicked();

private:
    Ui::Administration_verifier *ui;
};

#endif // ADMINISTRATION_VERIFIER_H
