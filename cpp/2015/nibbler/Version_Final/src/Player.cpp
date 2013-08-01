
#include <iostream>
#include <utility>
#include <vector>
#include "IApplication.hpp"
#include "Case.hpp"
#include "Prey.hpp"
#include "Field.hpp"
#include "Player.hpp"

// _CTOR

Player::Player(IApplication* app, Field *land, Prey *fruit)
  : toDisplay(app)
{
  this->_score = 0;
  this->_level = 1;
  this->_land = land;
  this->_prey = fruit;
  this->_direction = RIGHT;
  this->_haveEatPrey = false;
  this->setAtInitialPosition();
}

// _DTOR

Player::~Player()
{
  delete (this->_land);
  delete (this->_prey);
  this->_level = 0;
}

// Set a la Position Initiale

void		Player::setAtInitialPosition()
{
  this->_storage.push_back(new Case(SNAKE_HEAD, this->_app->getScrWidth() / 2, this->_app->getScrHeight() / 2));
  this->_storage.push_back(new Case(SNAKE_BODY, this->_storage[0]->getX() - this->_app->getCaseWidth(), this->_storage[0]->getY()));
  this->_storage.push_back(new Case(SNAKE_BODY, this->_storage[1]->getX() - this->_app->getCaseWidth(), this->_storage[1]->getY()));
  this->_storage.push_back(new Case(SNAKE_BODY, this->_storage[2]->getX() - this->_app->getCaseWidth(), this->_storage[2]->getY()));
}

// Refresh Snake

void	Player::updateSnake(std::pair<int, int> const &movingDirection)
{
  std::pair<int, int>	tmp;

  tmp.first = this->_storage[0]->getX() + (this->_app->getCaseWidth() * movingDirection.first);
  tmp.second = this->_storage[0]->getY() + (this->_app->getCaseHeight() * movingDirection.second);
  this->_storage.insert(this->_storage.begin(), new Case(SNAKE_HEAD, tmp.first, tmp.second));
  this->_storage[1]->setType(SNAKE_BODY);
  if (this->_haveEatPrey == false)
    this->_storage.pop_back();
  else
    this->_haveEatPrey = false;
  if ((this->_storage[0]->getX() == this->_prey->getX()) && 
      (this->_storage[0]->getY() == this->_prey->getY()))
    this->eatPrey();
}

// Check la direction et position x & y pour la collision

bool	Player::checkMove(std::pair<int, int> const &movingDirection) const
{
  std::vector<Case *>::const_iterator	it;
  int	x;
  int	y;

  x = this->_storage[0]->getX() + (this->_app->getCaseWidth() * movingDirection.first);
  y = this->_storage[0]->getY() + (this->_app->getCaseHeight() * movingDirection.second);
  if (((x < 0) || (x >= this->_app->getScrWidth())) ||
      ((y < 0) || (y >= this->_app->getScrHeight())))
    return (false);
  for (it = this->_storage.begin(); it != this->_storage.end(); ++it)
    if ((x == (*it)->getX()) && (y == (*it)->getY()))
      return (false);
  return (true);
}

//      moving direction:
//	first:	X way;
//	second: Y way;

void		Player::move(direction dir)
{
  std::pair<int, int>	movingDirection;

  if (dir == FORWARD)
    this->move(this->_direction);
  else
    {
      movingDirection.first = 0;
      movingDirection.second = 0;
      this->_direction = dir;
      switch (dir)
	{
	case RIGHT:
	  movingDirection.first = 1;
	  break;
	case LEFT:
	  movingDirection.first = -1;
	  break;
	case UP:
	  movingDirection.second = -1;
	  break;
	case DOWN:
	  movingDirection.second = 1;
	  break;
	case FORWARD:      
	  break;
	}
      if (this->checkMove(movingDirection) == true)
	{ 
	  this->updateSnake(movingDirection);
	  this->_land->display();
	  this->_prey->display();
	  this->display();
	}
      else
	this->_app->endingGame();
    }
}

// Get Score

size_t		Player::getScore() const
{
  return (this->_score);
}

void		Player::setScore(const size_t score)
{
  this->_score = score;
}

// get and set level

size_t		Player::getLevel() const
{
  return (this->_level);
}

void		Player::setLevel(const size_t level)
{
  this->_level = level;
}

// set prey

void		Player::setPrey(Prey * fruit)
{
  this->_prey = fruit;
}

// incremente le score if snake eat the prey

void		Player::eatPrey()
{
  delete (this->_prey);
  this->_prey = new Prey(this->_app, this->_land, this);
  this->_haveEatPrey = true;
  this->_score += 5;
}

// get la dir du Snake

direction	Player::getDirection() const
{
  return (this->_direction);
}

// Reset Player

void		Player::reset()
{
  this->_storage.clear();
  this->_score = 0;
  this->_direction = RIGHT;
  this->setAtInitialPosition();
}
