#include "../inc/Map.hh"

map::map::map(int length, int width, int nbPlayer): _length(length), _width(width), _nbPlayer(nbPlayer)
{
  int   i;
  if (this->_length % 2 == 0)
    ++this->_length;
  if (this->_width % 2 == 0)
    ++this->_width;
  if (((((this->_length - 2) * 2) + ((this->_width - 2) * 2) - 4) / this->_nbPlayer) < 11)
    {
      std::cout << "too many player for this map" << std::endl;
      this->posibility = false;
      return;
    }
  else
    {
      this->posibility = true;
      this->_mymap = new int*[this->_width + 1];
      for(i = 0; i < this->_width; i++)
        this->_mymap[i] = new int[this->_length + 1];
      this->generateMap();
    }
}

map::map::~map()
{
  int i;

  if (this->posibility == true)
    {
      for(i = 0; this->_mymap[i]; i++)
	delete[] this->_mymap[i];
      delete[] this->_mymap;
    }
}

void    map::map::generateMap()
{
  int   i;
  int   y;
  int   x;
  int   space;

  for(i = 0; i < this->_width; i++)
    for(y = 0; y < this->_length; y++)
      {
	if (i == 0 || y == 0 || y == (this->_length - 1) || i == (this->_width - 1))
	  this->_mymap[i][y] = 3;
	else
	  this->_mymap[i][y] = 2;
      }

  space = (((this->_length - 2) * 2) + ((this->_width - 2) * 2) - 4) / this->_nbPlayer;
  x = -1;
  i = 1;

  for(y = 1; y < this->_length -2; y++)
    {
      if ((i == 1 && y != 0) || (y == 1 && i != 0) || (y == (this->_length - 2) && i != 0) || (i == (this->_width - 2) && y != 0))
	x++;
      if (x == space)
	{
	  this->_mymap[i][y] = 1;
	  x = 0;
	}
    }

  for(i = 1; i < this->_width -2; i++)
    {
      if ((i == 1 && y != 0) || (y == 1 && i != 0) || (y == (this->_length - 2) && i != 0) || (i == (this->_width - 2) && y != 0))
	x++;
      if (x == space)
	{
	  this->_mymap[i][y] = 1;
	  x = 0;
	}
    }

  for( ; y > 1; y--)
    {
      if ((i == 1 && y != 0) || (y == 1 && i != 0) || (y == (this->_length - 2) && i != 0) || (i == (this->_width - 2) && y != 0))
	x++;
      if (x == space)
	{
	  this->_mymap[i][y] = 1;
	  x = 0;
	}
    }

  for( ; i >= 1; i--)
    {
      if ((i == 1 && y != 0) || (y == 1 && i != 0) || (y == (this->_length - 2) && i != 0) || (i == (this->_width - 2) && y != 0))
	x++;
      if (x == space)
	{
	  this->_mymap[i][y] = 1;
	  x = 0;
	}
    }
  //Placement des espaces autour des joueurs

  for(i = 0; i < this->_width; i++)
    for(y = 0; y < this->_length; y++)
      {
	if (this->_mymap[i][y] == 1 && this->_mymap[i][y+1] != 3)
	  this->_mymap[i][y+1] = 9;
	if (this->_mymap[i][y] == 1 && this->_mymap[i][y-1] != 3)
	  this->_mymap[i][y-1] = 9;
	if (this->_mymap[i][y] == 1 && this->_mymap[i+1][y] != 3)
	  this->_mymap[i+1][y] = 9;
	if (this->_mymap[i][y] == 1 && this->_mymap[i-1][y] != 3)
	  this->_mymap[i-1][y] = 9;
      }

  for(i = 0; i < this->_width; i++)
    for(y = 0; y < this->_length; y++)
      {
	if (i%2 == 0 && y%2 == 0)
	  this->_mymap[i][y] = 3;
      }
}

void    map::map::affMap() const
{
  int   i;
  int   y;

  if (this->posibility == true)
    for(i = 0; this->_mymap[i]; i++)
      {
	for(y = 0; this->_mymap[i][y]; y++)
	  {
	    std::cout << this->_mymap[i][y];
	  }
	std::cout << std::endl;
      }
}

void	map::map::setPos(int bloc, int x, int y)
{
  this->_mymap[y][x] = bloc;
}

int	map::map::getPos(int x, int y) const
{
  return (this->_mymap[y][x]);
}
