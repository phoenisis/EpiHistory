#include "dial.h"
#include "ui_dial.h"

Dial::Dial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dial)
{
    ui->setupUi(this);
    this->ui->LoginLabel->hide();
    this->ui->HangOutPushButton->hide();
}

Dial::~Dial()
{
    delete ui;
}

void Dial::clearScreen()
{
    this->ui->LoginLabel->show();
    this->ui->HangOutPushButton->show();
}

void Dial::printScreen()
{
    this->ui->LoginLabel->show();
    this->ui->HangOutPushButton->show();
}


void Dial::setLogin(QString login)
{
    this->ui->LoginLabel->setText(login);
}

void Dial::hangOut()
{
    this->close();
}

void Dial::connection()
{
    connect(this->ui->HangOutPushButton, SIGNAL(clicked()), this, SLOT(hangOut()));
}
