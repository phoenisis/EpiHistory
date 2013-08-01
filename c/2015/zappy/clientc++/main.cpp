#include "IA.hh"
#include "player.hh"

int		main(int ac, char **av)
{
  std::string	teamname;
  std::string	host;
  std::string	port;

  if (ac < 5)
    {
      std::cout << "usage: ./client -n [team name] -p [port] (-h [host])" << std::endl;
    }
  else
    {
      if (av[1][1] == 'n')
	teamname = av[2];
      else
	std::cout << "usage: ./client -n [team name] -p [port] (-h [host])" << std::endl;
      if (av[3][1] == 'p')
	port = av[4];
      else
	std::cout << "usage: ./client -n [team name] -p [port] (-h [host])" << std::endl;
      if (ac > 5)
	{
	  if (av[5][1] == 'h')
	    host = av[6];
	  else
	    std::cout << "usage: ./client -n [team name] -p [port] (-h [host])" << std::endl;
	}
      else
	host = "localhost";
      runIA(host, port, teamname);
    }
  return (0);
}
