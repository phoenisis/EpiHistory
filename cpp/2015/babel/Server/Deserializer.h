#ifndef			__DESERIALIZER_H__
# define		__DESERIALIZER_H__
# include		<string>
# include		"DataStructures.h"

class			Deserializer
{
public:
	Deserializer();
	~Deserializer();
	void			feedBuffer(std::string const &);
	short int		getCmdNumber();
	PacketHeader *	getHeader();
	AuthenticationPacket *	getAPacket();
	NetworkInformationPacket *	getNIPacket();
	ContactPacket *				getCPacket();
	void						clear();
private:
	std::string		_data;
	PacketHeader	_header;
};

#endif