
#include "ColorRGB.hpp"

// _CTOR

ColorRGB::ColorRGB(int color)
{
  this->_red = (color >> 16) & 0xff;
  this->_green = (color >> 8) & 0xff;
  this->_blue = color & 0xff;
}

ColorRGB::ColorRGB(ColorRGB const &rgb)
{
  this->_red = rgb._red;
  this->_green = rgb._green;
  this->_blue = rgb._blue;
}

// Surcharges

ColorRGB	&ColorRGB::operator=(ColorRGB const &rgb)
{
  if (this != &rgb)
    {
        this->_red = rgb._red;
	this->_green = rgb._green;
	this->_blue = rgb._blue;
    }
  return (*this);
}

// Getter's

int		ColorRGB::getRed()	const
{
  return (this->_red);
}

int		ColorRGB::getGreen()	const
{
  return (this->_green);
}

int		ColorRGB::getBlue()	const
{
  return (this->_blue);
}
