
#include <stdio.h>
#include "Map.hh"
#include "Character.hh"
#include "Bomb.hh"
#include <iostream>

int		main()
{
  char a;
  int		key;
  map::map	map(10, 10, 1);
  Character	perso(1, 1, "Caca");
  Bomb		bomb(1, 1, 2);
  
  map.setPos(1, 5, 5);
  map.setPos(9, 5, 6);
  map.affMap();
  while (43)
    {
      std::cin >> a;
      // std::cout << a << " " << int(a) << std::endl;
      if (a == 98)
	{
	  key = getchar();
	  std::cout << "BOMB" << std::endl;
	  bomb.explose(map, 1, 1, 1, 1, 2);
	  bomb.explose(map, -1, -1, 1, 1, 2);
	  bomb.explose(map, 1, -1, 1, 1, 2);
	  bomb.explose(map, -1, 1, 1, 1, 2);
	  map.affMap();
	}
      if (a == 119)
	{
	  key = getchar();
	  std::cout << "UP" << std::endl;
	  perso.movePlayer(map, Character::UP, map::PLAYER);
	  map.affMap();
	  // std::cout << key << std::endl;
	}
      else if (a == 115)
	{
	  key = getchar();
	  std::cout << "DOWN" << std::endl;
	  perso.movePlayer(map, Character::DOWN, map::PLAYER);
	  map.affMap();
	  // std::cout << key << std::endl;
	}
      else if (a == 97)
	{
	  key = getchar();
	  std::cout << "LEFT" << std::endl;
	  perso.movePlayer(map, Character::LEFT, map::PLAYER);
	  map.affMap();
	  // std::cout << key << std::endl;
	}
      else if (a == 100)
	{
	  key = getchar();
	  std::cout << "RIGHT" << std::endl;
	  perso.movePlayer(map, Character::RIGHT, map::PLAYER);
	  map.affMap();
	  // std::cout << key << std::endl;
	}
    }
}
