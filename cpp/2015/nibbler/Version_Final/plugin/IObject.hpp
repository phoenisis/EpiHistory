
#ifndef		__IOBJECT_HPP__
# define	__IOBJECT_HPP__

#include <SFML/Graphics.hpp>

class			IObject
{
public:
  virtual	 	~IObject(void) {}
  virtual void		Init(void) = 0;
  virtual void		Draw(sf::RenderWindow &) = 0;
  virtual void		setVertex(sf::Vector2f const &) = 0;
  virtual void		setScale(sf::Vector2f const &) = 0;
};

#endif		// ! __IOBJECT_HPP__
