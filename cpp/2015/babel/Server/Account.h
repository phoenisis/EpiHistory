//
//  Account.h
//  babel
//
//  Created by Quentin Yann PIDOUX on 30/11/12.
//  Copyright (c) 2012 Quentin Yann PIDOUX. All rights reserved.
//

#ifndef __babel__Account__
#define __babel__Account__
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

class Account {
private:
    std::map<std::string, std::string>		_accounts;
public:
    Account();
    ~Account();
    
    bool checkIfExist(const std::string &);
    void addContact(const std::string &, const std::string &);
    
    const std::list<std::string> * getLogins();
    const std::string & getPassword(const std::string &);
    
    void addContactToListOf(const std::string &, const std::string &);
    std::list<std::string> * getContactListOf(const std::string &);
    void removeContactToListOf(const std::string &, const std::string &);
};

#endif /* defined(__babel__Account__) */
