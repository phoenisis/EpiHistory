
#ifndef	__NIBBLER_HPP__
#define	__NIBBLER_HPP__

#include <iostream>
#include <string>
#include <list>
#include "Case.hpp"
#include "Prey.hpp"
#include "Field.hpp"
#include "Player.hpp"
#include "IApplication.hpp"

class				Nibbler
{
public:
  Nibbler(size_t, size_t, std::string const &);
  ~Nibbler();

public:
  void				init(int argc, char **argv);
  void				display();
  void				putOnScreen(Case const * const);
  void				loop();
  void				quit();

private:
  void				*_handle;

  IApplication			*_app;

  Field				*_field;
  Prey				*_prey;
  Player			*_player;

  std::list<toDisplay *>	_displayObj;
};

#endif	/* ! __NIBBLER_HPP__ */
