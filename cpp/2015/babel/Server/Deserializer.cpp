#include		<string>
#include		<cstring>
#include		<iostream>
#include		"DataStructures.h"
#include		"Deserializer.h"

Deserializer::Deserializer()
{
}

Deserializer::~Deserializer()
{
}

void			Deserializer::feedBuffer(std::string const &str)
{
	this->_data.assign(str);
	memcpy(&this->_header, this->_data.data(), sizeof(this->_header));
}

short int		Deserializer::getCmdNumber()
{
	return (this->_header.cmd);
}

PacketHeader *	Deserializer::getHeader()
{
	PacketHeader *	res = new PacketHeader;

	memcpy(res, &this->_header, sizeof(PacketHeader));
	return (res);
}

AuthenticationPacket *	Deserializer::getAPacket()
{
	AuthenticationPacket *	res = new AuthenticationPacket;

	memcpy(res, this->_data.data(), sizeof(AuthenticationPacket));
	return (res);
}

NetworkInformationPacket *	Deserializer::getNIPacket()
{
	NetworkInformationPacket *	res = new NetworkInformationPacket;

	memcpy(res, this->_data.data(), sizeof(NetworkInformationPacket));
	return (res);
}

ContactPacket *				Deserializer::getCPacket()
{
	ContactPacket *	res = new ContactPacket;

	memcpy(res, this->_data.data(), sizeof(ContactPacket));
	return (res);
}

void					Deserializer::clear()
{
	this->_data.clear();
	memset(&this->_header, 0, sizeof(this->_header));
}
