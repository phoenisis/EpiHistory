#ifndef QBABEL_H
#define QBABEL_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QStringList>
#include <QListView>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#include "dial.h"

namespace Ui {
class QBabel;
}

class QBabel : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QBabel(QWidget *parent = 0);
    ~QBabel();

    void  loginScreen();
    void  contactScreen();
    void  connectActionsSignals(void);
    void  openOptionsDialog(void);


public slots:
    void  aboutQBabel(void);
    void  addContact(void);
    void  selection(void);
    void  settingScreen(void);
    void  saveOptions(void);
    void  cancelSetting(void);
    void  quit(void);
    void  creat(void);
  //  void  deconnexionClient(void);
  //  void  nouvelleConnexion(void);

private:
    Ui::QBabel *ui;
    QListView *vue;
    QStringList list;
    QStringListModel *modele;
    int _row;

    QString	_server;
    QString	_port;
    QString	_login;
    QString	_password;

    QUdpSocket _udp;

    Dial    *_dial;

};

#endif // QBABEL_H
