//
// Map.cpp for Map in /home/hubert_s//nibbler-2014-pidoux_q
// 
// Made by sevan hubert
// Login   <hubert_s@epitech.net>
// 
// Started on  Mon Mar  7 13:34:52 2011 sevan hubert
// Last update Wed Mar  9 17:08:58 2011 sevan hubert
//


#include <cstdlib>
#include "Map.hh"
#include "Snake.hh"

Map::Map()
{
  this->x = 30;
  this->y = 30;
}

Map::Map(int x, int y)
{
  this->x = x;
  this->y = y;
}

Map::~Map()
{}

int	Map::getSizeX() const
{
  return this->x;
}

int	Map::getSizeY() const
{
  return this->y;
}

bool	Map::case_is_free(int x, int y, Snake &hd) const
{
  Snake	*verif = &hd;

  if ((x < 0) || (x >= this->getSizeX())
      || (y < 0) || (y >= this->getSizeY()))
    return false;
  while (verif != NULL)
    {
      if (verif->getPosX() == x && verif->getPosY() == y)
	return false;
      verif = verif->getNext();
    }
  return true;
}
