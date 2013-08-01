#include <iostream>
#include <cstdlib>

#include "Map.hh"
#include "Blocs.hh"
#include "Bonus.hh"

Map::Map(Bloc::Breakable *breakable)
{
  this->sizeX = 23;
  this->sizeY = 23;
  this->blocs = new char [(this->sizeX * this->sizeY)];
  this->generate_map();
  this->breakables = breakable;
}

Map::Map(Bloc::Breakable *breakable, int sizeX, int sizeY)
{
  this->sizeX = sizeX * 2 - 1;
  this->sizeY = sizeY * 2 - 1;
  this->blocs = new char [(this->sizeX * this->sizeY)];
  this->generate_map();
  this->breakables = breakable;
}

// # = Blocs incassables
// o = Blocs cassables
// . = Blocs vides
// B = bombe
//

void	Map::generate_map()
{
  int	i = 0;

  srand(time(NULL));
  while (i < sizeX * sizeY)
    {
      if (((i % sizeY) % 2 == 1) && ((i / sizeX) % 2 == 1))
	this->blocs[i] = '#';
      else if (rand() % 100 <= 80)
	this->blocs[i] = 'o';
      else
	this->blocs[i] = '.';
      i++;
    }
}

Map::~Map()
{
  delete this->blocs;
}

char	Map::get_bloc(int x, int y) const
{
  if ((x < 0) || (y < 0))
    return 0;
  else if ((x <= this->sizeX - 1) && (y <= this->sizeY - 1))
    return this->blocs[this->sizeX * y + x];
  else
    return 0;
}

int	Map::getSizeX() const
{
  return this->sizeX;
}

int	Map::getSizeY() const
{
  return this->sizeY;
}

int	Map::getPosX(int n) const
{
  return (n % this->sizeX);
}

int	Map::getPosY(int n) const
{
  return (n / this->sizeY);
}

int	Map::getNb_blocs() const
{
  return (this->sizeX * this->sizeY);
}

Bloc::Breakable *Map::getBreakable() const
{
  return this->breakables;
}

void	Map::set_bloc(int x, int y, char set)
{
  if ((x <= this->sizeX - 1) && (y <= this->sizeY - 1) && (x >= 0) && (y >= 0))
    this->blocs[x * this->sizeY + y] = set;
}


#include <unistd.h>
void	Map::aff_ascii()
{
  int	i = 0;

  while (i < sizeX * sizeY)
    {
      write(1, &blocs[i], 1);
      if (i % sizeX == sizeX - 1)
	std:: cout << "\n";
      i++;
    }
}
