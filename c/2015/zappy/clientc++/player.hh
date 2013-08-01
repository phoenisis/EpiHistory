
//
// player.hh for  in /home/fleuro_m//work/Zappy/zappy-2015-2014s-herve_a/clientcpp
//
// Made by matthieu fleurot
// Login   <fleuro_m@epitech.net>
//
// Started on  Tue Jun 19 14:48:38 2012 matthieu fleurot
// Last update Sun Jul 15 09:53:55 2012 matthieu fleurot
//

#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <utility>
#include "Client.hh"

struct	object
{
public:
  std::pair<int, int>	vect;
  std::string		ress;
};

class	player
{
public:
  player();
  ~player();
  void	init();

  bool	forward();
  bool	right();
  bool	left();
  bool	watch();
  bool	inventory();
  bool	take();
  bool	drop(std::string);
  bool	expulse();
  bool	talk(std::string);
  bool	elevation();
  bool	fork();
  int	connect_nbr();
  bool	death();
  bool	needed(std::string ressource, int pos);

  void				parse(std::string);
  int				getLifetime() const;
  int				getLvl() const;
  bool				getHungry() const;
  bool				getAlive() const;
  std::map<std::string, int>	getInventory() const;
  std::map<std::string, int>	getToFind() const;
  object			&getToGet();
  int				getToMove() const;
  Client			*getSocket() const;
  void				setLifetime(int);
  void				setLvl(int);
  void				setHungry(bool);
  void				setAlive(bool);
  void				setSocket(std::string, std::string);
  void				setToMove(int);
  void				setToGet(object);

private:
  int					_lifetime;
  int					_lvl;
  bool					_hungry;
  bool					_alive;
  std::map<std::string, int>		_inventory;
  std::map<std::string, int>		_toFind;
  std::map<int, std::pair<int, int> >	_pov;
  object				_toGet;
  int					_toMove;
  Client				*_socket;
};

