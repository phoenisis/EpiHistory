
#include "CExceptions.hpp"

//Initialisation

CExceptions::CExceptions(void)
{
}

CExceptions::CExceptions(std::string const &msg)
	: _msg(msg)
{
}

CExceptions::CExceptions(CExceptions const &data)
{
	*this = data;
}

//Destruction

CExceptions::~CExceptions(void) throw()
{
}

//Surcharges

CExceptions			&CExceptions::operator=(CExceptions const &data)
{
  if (&data != this)
    this->_msg = data._msg;
  return (*this);
}

//Virtual

const char			*CExceptions::what(void) const throw()
{
  return (this->_msg.c_str());
}
