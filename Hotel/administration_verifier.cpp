#include "administration_verifier.h"
#include "ui_administration_verifier.h"
#include "administration.h"
#include "starting_menu.h"

Administration_verifier::Administration_verifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administration_verifier)
{
    ui->setupUi(this);

    ui->placeholderLabel->setText(nullptr);

    connect(ui->cancelButton, &QPushButton::clicked, [=](){
        this->hide();
    });
}

Administration_verifier::~Administration_verifier()
{
    delete ui;
}

void Administration_verifier::on_submitButton_clicked()
{
    QString pin = "5327192362";

    if (ui->authenticationPinLineEdit->text() == pin)
    {
        starting_menu *menu = new starting_menu;
        Administration *administration = new Administration;
        administration->open();
        menu->hide();
        this->hide();
    } else {
        ui->placeholderLabel->setText("The pin was not correct!");
    }
}
