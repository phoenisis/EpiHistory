#include "network.h"

Network::Network(QHostAddress & address, quint16 port) {
    server_ = new QTcpSocket(this);
    connect(server_, SIGNAL(readyRead()), this, SLOT(retrieveHandshake()));
    server_->connectToHost(address, port, QIODevice::ReadWrite);
}

Network::~Network() {
}

void    Network::loginScreen(std::string login, std::string password, bool isCreateAccount, std::list<void *> contactList) {
    short    header[4];
    char   data[260];

    header[0] = 0;
    if(isCreateAccount) {
        header[1] = 1;
    }
    else {
        header[1] = 2;
    }
    header[2] = myId_;
    header[3] = myId_;
    ((short *)data)[0] = login.length();
    strcpy((char *)(((short *)data)[2]), login.c_str());
    ((short *)data)[130] = password.length();
    strcpy((char *)(((short *)data)[132]), password.c_str());
    server_->write((char *)header, 8);
    server_->write(data, 260);
}

void    Network::retrieveHandshake() {
//    char   handshake[8];

//    int rsize = server_->read(handshake, 8);
//    std::cout << "Handshake (size =" << rsize << "): " << handshake << std::endl;
//    if (((quint16 *)(handshake))[0] != 0 || ((quint16 *)(handshake))[1] != 0)
//        server_->close();
//    else {
//        if (((quint16 *)(handshake))[2] == ((quint16 *)(handshake))[3])
//        myId_ = ((quint16 *)(handshake))[3];
//    }
//    std::cout << "ID taken: " << myId_ << std::endl;
    std::cout << "FTW" << std::endl;
}
