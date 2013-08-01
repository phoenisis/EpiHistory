
#include <iostream>
#include <sstream>
#include <unistd.h>
#include "Error.hpp"
#include "Nibbler.hpp"
#include "Player.hpp"
#include "DLLoader.hpp"

int	main(int argc, char **argv)
{
  std::stringstream	av1(std::ios::in | std::ios::out);
  std::stringstream	av2(std::ios::in | std::ios::out);
  std::string		lib;
  int			width;
  int			height;
  Error			check;

  lib = check.check_argv(argc, argv);

  if (argc != 4)
    {
      std::cerr << "usage: ./nibbler width height graph-library." << std::endl;
      return (-1);
    }
  else
    {
      av1 << argv[1];
      av1 >> width;
      av2 << argv[2];
      av2 >> height;
      if ((width < 20) || (height < 20))
	{
	  check.print_usage_min(width, height);
	  return (1);
	}
      if ((width > 50) || (height > 50))
	{
	  check.print_usage_max(width, height);
	  return (-1);
	}
      DLLoader	loader(lib);
      Nibbler	snake(width, height, lib);

      snake.init(argc, argv);
      snake.display();
      snake.loop();

      return (0);
    }
}
