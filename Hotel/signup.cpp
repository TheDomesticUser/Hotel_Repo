#include "signup.h"
#include "ui_signup.h"
#include <QSettings>
#include <QString>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QRegExp>
#include <QValidator>

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);

    ui->textPlaceholderLabel->setText(nullptr);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_createAccountButton_clicked()
{
    // Setup the regular expressions for validation
    QRegExp verifyUsername("\\w{3,20}");
    QRegExp verifyPassword("\\S{8,20}");

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (!verifyUsername.exactMatch(username))
        ui->textPlaceholderLabel->setText("The username must contain 3-20 characters with no special symbols!");
    else if (!verifyPassword.exactMatch(password))
        ui->textPlaceholderLabel->setText("The password must contain 8-20 characters with no spaces!");
    else if (password != confirmPassword)
        ui->textPlaceholderLabel->setText("Your password does not equal to the confirmed password!");
    else {
        QMessageBox::information(this, "Success", "You have successfully created your account!");
        this->hide();
    }

}
