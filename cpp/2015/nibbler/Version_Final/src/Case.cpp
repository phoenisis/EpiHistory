
#include "Case.hpp"

// _CTOR

Case::Case(NibbleType type, unsigned int posX, unsigned int posY)
{
  this->_type = type;
  this->_posX = posX;
  this->_posY = posY;
}

/*
** Getter positions of x & y and type of nibbler(lib)
*/

int		Case::getX() const
{
  return (this->_posX);
}

int		Case::getY() const
{
  return (this->_posY);
}

NibbleType	Case::getType()	const
{
  return (this->_type);
}

/*
** Setter positions of x & y and type of nibbler(lib)
*/

void			Case::setX(unsigned int x)
{
  this->_posX = x;
}

void			Case::setY(unsigned int y)
{
  this->_posY = y;
}

void			Case::setType(NibbleType type)
{
  this->_type = type;
}
