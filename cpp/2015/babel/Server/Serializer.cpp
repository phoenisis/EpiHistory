#include		<string>
#include		<cstring>
#include		<iostream>
#include		<list>
#include		<utility>
#include		"Serializer.h"
#include		"DataStructures.h"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

void				Serializer::setHeader(short int status, short int cmd, short int idSource, short int idTarget)
{
	this->_header.status = status;
	this->_header.cmd = cmd;
	this->_header.sourceId = idSource;
	this->_header.targetId = idTarget;
}

void				Serializer::addInfo(std::string const &str)
{
	char			*tmp = new char[str.size()];
	short int		len = str.size();

	memcpy(tmp, &len, sizeof(short int));
	memcpy(tmp + sizeof(short int), str.data(), len);
	this->_datas.push_back(std::string(tmp, len + sizeof(short int)));
	delete tmp;
}

void				Serializer::addInfo(short int infos)
{
	char			*tmp = new char[sizeof(short int)];

	memcpy(tmp, &infos, sizeof(short int));
	this->_datas.push_back(std::string(tmp, sizeof(short int)));
	delete tmp;
}

std::string	*		Serializer::getResult()
{
	char			*tmp = new char[sizeof(PacketHeader)];
	std::string		*res = new std::string();
	std::list<std::string>::iterator		it;
	short int								dataLen = 0;

	memcpy(tmp, &this->_header, sizeof(PacketHeader));
	res->assign(tmp, sizeof(PacketHeader));
	memset(tmp, 0, sizeof(PacketHeader));
	if (!this->_datas.empty())
	{
		for (it = this->_datas.begin(); it != this->_datas.end(); ++it)
			dataLen += (*it).size();
		memcpy(tmp, &dataLen, sizeof(short int));
		res->append(tmp, sizeof(short int));
		for (it = this->_datas.begin(); it != this->_datas.end(); ++it)
			res->append(*it);
	}
	delete tmp;
	return (res);
}

void				Serializer::clear()
{
	memset(&this->_header, 0, sizeof(PacketHeader));
	this->_datas.clear();
}
