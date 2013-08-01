//
//  Client.cpp
//  zappy
//
//  Created by Quentin PIDOUX on 29/06/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#include <string.h>
#include "Client.hh"

std::size_t&                Client::initRecieved()
{
    std::size_t *Recieved = new size_t;
    return *Recieved;
}

sf::IpAddress&              Client::initIp(const std::string str)
{
    sf::IpAddress *ip = new sf::IpAddress(str);
    return *ip;
}

sf::TcpSocket&              Client::initClient()
{
    sf::TcpSocket *client = new sf::TcpSocket;
    client->setBlocking(false);
    return *client;
}

Client::Client(const std::string ip, const std::string port)
:ip(initIp(ip)), Recieved(initRecieved())
{
    this->port = atoi(port.c_str());
}

Client::~Client()
{
    this->client.disconnect();
}

void                        Client::setInfo(const std::string ip, const std::string port)
{
    sf::IpAddress tmp(ip);
    this->ip = tmp;
    this->port = atoi(port.c_str());
}

const bool                  Client::tryConnect()
{
    if (this->client.connect(this->ip, this->port) != sf::Socket::Done){
        std::cerr << "Fail to connect to: " <<this->ip << ":" << this->port << std::endl;
        return false;
    }
    else{
        std::cout << "Connected to: " <<this->ip << ":" << this->port << std::endl;
        return true;
    }
}

const bool                  Client::sendMessage(const std::string str)
{

    std::string tmp = str;
    tmp += '\n';

    if (this->client.send(tmp.c_str(), tmp.size()) != sf::TcpSocket::Done){
        std::cerr << "Fail to send Message: " << tmp << std::endl;
        return false;
    }
    std::cout << str << std::endl;
    return true;

}

const std::string           Client::recieveMessage()
{
    char buffer[1025];
    std::size_t Recieved = 0;
    sf::Socket::Status st;
    this->msg = "";
    memset(buffer, 0, 1025);
   // this->client.setBlocking(false);

    switch (st = this->client.receive(buffer, sizeof(buffer), Recieved)) {
        case sf::TcpSocket::NotReady:
            std::cerr << "Receive Not Ready" << std::endl;
            break;
        case sf::TcpSocket::Disconnected:
            std::cerr << "Receive Disconnected"<< std::endl;
            std::exit(EXIT_FAILURE);
            break;
        case sf::TcpSocket::Error:
            std::cerr << "Receive Error" << std::endl;
            std::exit(EXIT_FAILURE);
            break;
        case sf::TcpSocket::Done:
            this->msg = buffer;
            break;
        default:
            std::cerr << "Received Default" << std::endl;
            std::exit(EXIT_FAILURE);
            break;
    }
    return this->msg;
}
