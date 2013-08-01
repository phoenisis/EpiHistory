
#include <cstdlib>
#include "Prey.hpp"

// _CTOR

Prey::Prey(IApplication *app, Field *land, Player *player)
  :	Case(FRUIT, (rand() % land->getWidth()) * app->getCaseWidth(),
	     (rand() % land->getHeight()) * app->getCaseHeight()),
	toDisplay(app)
{ 
  if (stillHavePlace(land, player) == false)
    this->_app->endingGame();
  else
    {
      while (this->isInSnake(player))
	{
	  this->setX((rand() % land->getWidth()) * app->getCaseWidth());
	  this->setY((rand() % land->getHeight()) * app->getCaseHeight());
	}
      this->_storage.push_back(this);
    }
}

// Check Snake and Prey

bool		Prey::isInSnake(Player *player)	const
{
  std::vector<Case *>		snake;
  std::vector<Case *>::iterator	it;

  snake = player->getStorage();
  for (it = snake.begin(); it != snake.end(); ++it)
    if (((*it)->getX() == this->getX()) && ((*it)->getY() == this->getY()))
      return (true);
  return (false);
} 

bool		Prey::stillHavePlace(Field *land, Player *player) const
{
  std::vector<Case *>		sland;
  std::vector<Case *>::iterator	sld_it;
  std::vector<Case *>		snake;
  std::vector<Case *>::iterator	snk_it;
  bool				found;
  
  found = false;
  sland = land->getStorage();
  snake = player->getStorage();
  for (sld_it = sland.begin(); sld_it != sland.end(); ++sld_it)
    {
      for (snk_it = snake.begin(); snk_it != snake.end(); ++snk_it)
	if (((*snk_it)->getX() == (*sld_it)->getX()) &&
	    ((*snk_it)->getY() == (*sld_it)->getY()))
	  {
	    found = true;
	    break;
	  }
      if (found == false)
	return (true);
    }
  return (false);
}

// _DTOR

Prey::~Prey()
{

}
