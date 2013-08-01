
#ifndef __PREY_HPP__
# define __PREY_HPP__

#include "Case.hpp"
#include "Field.hpp"
#include "toDisplay.hpp"
#include "Player.hpp"

class	Prey: public Case, public toDisplay
{
private:
  Prey(Prey const &);
  Prey	&operator=(Prey const &);

  bool		isInSnake(Player *player) const;
  bool		stillHavePlace(Field *land, Player *player) const;

public:
  Prey(IApplication *app, Field *land, Player *player);
  ~Prey();
};

#endif /* ! __PREY_HPP__ */
