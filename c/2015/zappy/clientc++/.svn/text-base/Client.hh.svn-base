//
//  Client.h
//  zappy
//
//  Created by Quentin PIDOUX on 29/06/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#ifndef zappy_Client_hh
# define zappy_Client_hh
# include <iostream>
# include <string>
# include <map>
# include <utility>
# include <iterator>
# include <sstream>
# include <SFML/Network.hpp>
# include <fstream>
# include <limits.h>

class Client {
public:
    std::size_t&                initRecieved();
    sf::IpAddress&              initIp(const std::string);
    sf::TcpSocket&              initClient();
    
    Client(const std::string, const std::string);
    ~Client();
    void                        setInfo(const std::string, const std::string);
    const bool                  tryConnect();
    const bool                  sendMessage(const std::string);
    const std::string           recieveMessage();
    sf::TcpSocket               client;

private:
    int                         port;
    sf::IpAddress               &ip;
    std::size_t                 &Recieved;
    std::string                 msg;
};

#endif