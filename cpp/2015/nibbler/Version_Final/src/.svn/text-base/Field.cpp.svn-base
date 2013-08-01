
#include "Field.hpp"

// _CTOR

Field::Field(IApplication *app, size_t width, size_t height)
  :	toDisplay(app)
{
  size_t	caseWidth;
  size_t	caseHeight;

  this->_width = width;
  this->_height = height;
  caseWidth = this->_app->getCaseWidth();
  caseHeight = this->_app->getCaseHeight();
  for (size_t j = 0; j < this->_height; j++)
    for (size_t i = 0; i < this->_width; i++)
      this->_storage.push_back(new Case(GRASS, i * caseWidth, j * caseHeight));
}

/*
** Getter's
*/

size_t	Field::getWidth() const
{
  return (this->_width);
}

size_t	Field::getHeight() const
{
  return (this->_height);
}

Case const *	Field::at(size_t i, size_t j) const
{
  return (this->_storage[j * this->_height + i]);
}

// Surcharge

Case const *	Field::operator()(size_t i, size_t j) const
{
  return (this->_storage[j * this->_height + i]);
}
