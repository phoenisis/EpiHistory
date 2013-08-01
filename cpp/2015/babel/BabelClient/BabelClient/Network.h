#ifndef NETWORK_H
#define NETWORK_H

#include <cstdlib>
#include <iostream>
#include <list>
#include <QWidget>
#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QIODevice>


class Network: public QWidget {
    Q_OBJECT

private:
    QTcpSocket  *server_;
    short         myId_;
public:
    Network(QHostAddress &, quint16);
    ~Network();
    void    loginScreen(std::string, std::string, bool, std::list<void *>);
public slots:
    void    retrieveHandshake();
};

#endif // NETWORK_H
