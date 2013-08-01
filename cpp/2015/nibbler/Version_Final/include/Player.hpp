
#ifndef  __PLAYER_HPP__
# define __PLAYER_HPP__

class	IApplication;
class	Field;
class	Prey;

#include <iostream>
#include "toDisplay.hpp"

enum	direction
  {
    RIGHT,
    LEFT,
    UP,
    DOWN,
    FORWARD
  };

class	Player: public	toDisplay
{
private:
  size_t	_score;
  bool		_haveEatPrey;
  direction	_direction;
  Field		*_land;
  Prey		*_prey;
  size_t	_level;

  Player(Player const &);
  Player	&operator=(Player const &);

  void		updateSnake(std::pair<int, int> const &movingDirection);
  bool		checkMove(std::pair<int, int> const &movingDirection)	const;

  void		setAtInitialPosition();

public:
  Player(IApplication *app, Field *land, Prey *fruit);
  ~Player();

  void		move(direction dir);	//Move to Direction

  size_t	getScore() const;
  void		setScore(const size_t);
  void		setLevel(const size_t);
  size_t	getLevel() const;
  void		eatPrey();
  void		setPrey(Prey * fruit);
  
  int		getWidthOnScreen()	const;
  int		getHeightOnScreen()	const;
  direction	getDirection()		const;

  void		reset();
};

#endif /* ! __PLAYER_HPP__ */
