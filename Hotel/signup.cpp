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
    QRegExp rx("[A-Z][a-z][0-9]");
    QRegExpValidator validator(rx);
    int pos = 0;

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->passwordLineEdit->text();

    if (validator.validate(username, pos) == QRegExpValidator::Acceptable and
        validator.validate(password, pos) == QRegExpValidator::Acceptable)
    {
        if (username.length() < 3 || username.length() > 20) ui->textPlaceholderLabel->setText("Username must be 3 to 20 characters!");
        else if (password.length() < 8 || password.length() > 20) ui->textPlaceholderLabel->setText("Password must be between 8 to 20 characters!");
        else if (password != confirmPassword) ui->textPlaceholderLabel->setText("The password does not equal to the confirmed password!");
        else {
            QMessageBox::information(this, "Success", "You have successfully created your account!");
            this->hide();
        }
        return;
    }

    ui->textPlaceholderLabel->setText("There cannot be special characters in your username and password!");
}
