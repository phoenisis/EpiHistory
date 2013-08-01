#include "Color.hpp"

namespace gdl
{
  Color::Color()
    : r(255), g(255), b(255), a(255)
  {
  }

  Color::Color(uchar r, uchar g, uchar b, uchar a)
    : r(r), g(g), b(b), a(a)
  {
  }
 
  Color::Color(Color const & color)
  {
    *this = color;
  }

  Color&	Color::operator=(Color const & color)
  {
    if (this != &color)
      {
	this->r = color.r;
	this->g = color.g;
	this->b = color.b;
	this->a = color.a;
      }
    return *this;
  }

  bool Color::operator==(Color const & c) const
  {
    return c.r == r && c.g == g && c.b == b && c.a == a;
  }

  bool Color::operator!=(Color const & c) const
  {
    return !(*this == c);
  }
}

