#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
#include <QRegExp>
#include <QRegularExpression>
#include <QDate>

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
    QRegularExpression verifyCharacters("[^\\w]");
    QRegExp verifyLength("\\S{8,20}");

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (verifyCharacters.match(username).hasMatch())
        ui->textPlaceholderLabel->setText("The username must contain only letters and numbers!");
    else if (!verifyLength.exactMatch(username))
        ui->textPlaceholderLabel->setText("The username must contain 8-20 characters with no spaces!");
    else if (!verifyLength.exactMatch(password))
        ui->textPlaceholderLabel->setText("The password must contain 8-20 characters with no spaces!");
    else if (password != confirmPassword)
        ui->textPlaceholderLabel->setText("Your password does not equal to the confirmed password!");
    else {
        QMessageBox::information(this, "Success", "You have successfully created your account!");
        accountStore(username, password);
        this->hide();
    }
}

// Store the account into a MYSQL database called hotel
void SignUp::accountStore(QString username, QString password)
{
    Widget *widget = new Widget;
    QDate currentDate = QDate::currentDate();
    QString databaseName = "hotel";

    {
        QSqlDatabase db = widget->createDatabase("QMYSQL", databaseName, "signup_conn", "root", "incorrect", "localhost", 3306);

        db.open();

        if (!db.isOpen()) {
            QMessageBox::critical(this, "Unsuccessful", "Opening the SQL database " + databaseName + " was unsuccessful");
        } else {
            QSqlQuery query(db);
            query.prepare("INSERT INTO account(username, password, date_of_creation)"
                          "VALUES(:username, :password, :date_of_creation)");
            query.bindValue(":username", username);
            query.bindValue(":password", password);
            query.bindValue(":date_of_creation", currentDate);

            query.exec();
        }
        db.close();
    }
    QSqlDatabase::removeDatabase("signup_conn");
}
