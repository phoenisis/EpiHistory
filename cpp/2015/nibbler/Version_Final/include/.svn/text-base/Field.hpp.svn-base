
#ifndef  __FIELD_HPP__
# define __FIELD_HPP__

#include "Case.hpp"
#include "toDisplay.hpp"

class	Field: public	toDisplay
{
private:
  size_t	_width;
  size_t	_height;

  Field(Field const &);
  Field	&operator=(Field const &);

public:
  Field(IApplication *app, size_t width, size_t height);
  ~Field() {}

  size_t	getWidth()	const;
  size_t	getHeight()	const;

  Case const *	at(size_t i, size_t j) const;  
  Case const *	operator()(size_t i, size_t j) const;
};

#endif /* ! __FIELD_HPP__ */
