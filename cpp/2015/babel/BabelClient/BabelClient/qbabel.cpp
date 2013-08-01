#include <QMessageBox>
#include <QItemSelectionModel>
#include <QVariant>
#include <QtGui>
#include "qbabel.h"
#include "ui_qbabel.h"

QBabel::QBabel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QBabel), _dial(new Dial(this))
{
    ui->setupUi(this);
    loginScreen();
    connectActionsSignals();
}

QBabel::~QBabel()
{
    delete ui;
}

void QBabel::loginScreen()
{
    //hide normal window
    this->ui->comboBox->hide();
    this->ui->tree->hide();
    this->ui->AddLineEdit->hide();
    this->ui->AddPushButton->hide();
    this->ui->CallPushButton->hide();
    this->ui->CancelPushButton->hide();

    //show setting window
    this->ui->LoginLabel->show();
    this->ui->LoginLineEdit->show();
    this->ui->ServerLabel->show();
    this->ui->PortLabel->show();
    this->ui->PasswordLabel->show();
    this->ui->SettingLabel->show();
    this->ui->ServerLineEdit->show();
    this->ui->PortLineEdit->show();
    this->ui->PasswordLineEdit->show();
    this->ui->OkPushButton->show();
    this->ui->CreatPushButton->show();
    this->ui->CancelPushButton->show();
}

void QBabel::contactScreen()
{
    //hide setting window
    this->ui->LoginLabel->hide();
    this->ui->ServerLabel->hide();
    this->ui->PortLabel->hide();
    this->ui->PasswordLabel->hide();
    this->ui->SettingLabel->hide();
    this->ui->LoginLineEdit->hide();
    this->ui->ServerLineEdit->hide();
    this->ui->PortLineEdit->hide();
    this->ui->PasswordLineEdit->hide();
    this->ui->OkPushButton->close();
    this->ui->CancelPushButton->close();
    this->ui->CreatPushButton->close();
    this->ui->gridLayoutWidget_3->setDisabled(false);
    this->ui->gridLayoutWidget->focusWidget();

    //show normal window
    this->ui->comboBox->show();
    this->ui->tree->show();
    this->ui->AddLineEdit->show();
    this->ui->AddPushButton->show();
    this->ui->CallPushButton->show();
    this->ui->CancelPushButton->hide();
}

void QBabel::connectActionsSignals()
{
    connect(this->ui->actionAbout_QBabel, SIGNAL(triggered()), this, SLOT(aboutQBabel()));
    connect(this->ui->AddPushButton, SIGNAL(clicked()), this, SLOT(addContact()));
    connect(this->ui->CallPushButton, SIGNAL(pressed()), this, SLOT(selection()));
    connect(this->ui->actionSettings, SIGNAL(triggered()), this, SLOT(settingScreen()));
    connect(this->ui->OkPushButton, SIGNAL(clicked()), this, SLOT(saveOptions()));
    connect(this->ui->CancelPushButton, SIGNAL(clicked()), this, SLOT(cancelSetting()));
    connect(this->ui->actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
    connect(this->ui->CreatPushButton, SIGNAL(clicked()), this, SLOT(creat()));
}

void QBabel::aboutQBabel()
{
    QMessageBox::about(this, "QBAbel", "Design by pidoux_q");
}

void QBabel::addContact()
{
    if (this->ui->AddLineEdit->text() == "")
    {
        QMessageBox::information(this, tr("Add Contact"),
                 tr("\nInsert a login please, I'm not a mindreader."));
        return;
    }

    else
    {
        QStringList tmp = this->list;
        this->list.append(this->ui->AddLineEdit->text().toStdString().c_str());

        QStringListModel *modele = new QStringListModel(this->list);
        this->ui->tree->setModel(modele);
        this->ui->tree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        this->ui->AddLineEdit->clear();
    }
}

void QBabel::selection()
{

}

void QBabel::settingScreen()
{
    loginScreen();
}

void QBabel::saveOptions()
{
    Q_ASSERT(this->ui);

    this->_server   = this->ui->ServerLineEdit->text();
    this->_port     = this->ui->PortLineEdit->text();
    this->_login    = this->ui->LoginLineEdit->text();
    this->_password = this->ui->PasswordLineEdit->text();

    contactScreen();
}

void QBabel::cancelSetting()
{
    contactScreen();
}

void QBabel::quit()
{
    this->close();
}

void QBabel::creat()
{
    QMessageBox::information(this, tr("Creat Account"),
             tr("\nCreat Account need to be implemented."));
}

//void QBabel::deconnexionClient()
//{}

//void QBabel::nouvelleConnexion()
//{}
