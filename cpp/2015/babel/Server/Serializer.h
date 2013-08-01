#ifndef			__SERIALIZER_H__
# define		__SERIALIZER_H__
# include		<string>
# include		<list>
# include		<utility>
# include		"DataStructures.h"

class			Serializer
{
public:
	Serializer();
	~Serializer();
	std::string *	getResult();
	void			setHeader(short int, short int, short int, short int);
	void			addInfo(std::string const &);
	void			addInfo(short int);
	void			clear();
private:
	PacketHeader	_header;
	std::list<std::string>	_datas;
};

#endif