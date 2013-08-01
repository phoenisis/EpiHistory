//
//  Account.cpp
//  babel
//
//  Created by Quentin Yann PIDOUX on 27/11/12.
//  Copyright (c) 2012 Quentin Yann PIDOUX. All rights reserved.
//

#include "Account.h"



Account::Account()
{
	std::ifstream	file("Account.csv");
	char			buff[512];
	std::string		pass;
	std::string		login;

	while (file.getline(buff, 512))
	{
		std::istringstream			iss(buff);
		iss.str(buff);
		iss >> login >> pass;
		this->_accounts.insert(std::pair<std::string, std::string>(login, pass));
		pass.clear();
		login.clear();
	}
	file.close();
}

Account::~Account()
{
}


bool Account::checkIfExist(const std::string & login)
{
	if (this->_accounts.count(login) == 0)
        return false;
    else
        return true;
}

void Account::addContact(const std::string & login, const std::string & password)
{
    if (this->checkIfExist(login) == false)
	{
        std::ofstream file;

        file.open ("AccountData.csv", std::fstream::out | std::fstream::app);
    
        std::string info = login + "," + password;
		file << info << std::endl;
    
        this->_accounts.insert(std::pair<std::string, std::string>(login, password));
        file.close();
    }
    else
        std::cerr << "Error: User already exist" << std::endl;
}


const std::string & Account::getPassword(const std::string & login)
{
   return (this->_accounts[login]);
}

void		Account::addContactToListOf(const std::string & login, const std::string & added)
{
    std::ofstream file;
    std::string fileName = login + ".qns";
    
    file.open (fileName.c_str(), std::fstream::out | std::fstream::app);
    
    file << added << std::endl;
    file.close();
}

std::list<std::string> * Account::getContactListOf(const std::string & login)
{
    char *buffer = new char[512];
    std::string fileName = login + ".qns";
    std::list<std::string> *_list = new std::list<std::string>;
	std::ifstream		file(fileName.c_str());

	while (file.getline(buffer, 512))
		_list->push_front(std::string(buffer));
	return (_list);
}

void	Account::removeContactToListOf(const std::string & login, const std::string & rm)
{

    std::string fileName = login + ".qns";
	char				buffer[512];
    std::list<std::string> *_list = getContactListOf(login);
    std::fstream file(fileName.c_str(), std::fstream::in | std::fstream::out);    
	std::list<std::string>::iterator	it;

	while (file.getline(buffer, 512))
		_list->push_front(std::string(buffer));
	for (it = _list->begin(); it != _list->end(); ++it)
	{
		if ((*it) == rm)
			_list->erase(it);
	}
    file.close();
    file.open(fileName.c_str(), std::fstream::out | std::fstream::trunc);
	for (it = _list->begin(); it != _list->end(); ++it)
		file << *it << std::endl;
	file.close();
}

