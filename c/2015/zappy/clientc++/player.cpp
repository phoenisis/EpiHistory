//
// player.cpp for  in /home/fleuro_m//work/Zappy/zappy-2015-2014s-herve_a/clientcpp
//
// Made by matthieu fleurot
// Login   <fleuro_m@epitech.net>
//
// Started on  Tue Jun 19 14:47:50 2012 matthieu fleurot
// Last update Sun Jul 15 13:14:28 2012 matthieu fleurot
//

#include "player.hh"

player::player()
{
  this->init();
  this->_lifetime = 1260;
  this->_lvl = 1;
  this->_hungry = false;
  this->_alive = true;
  this->_toMove = 0;
}

player::~player()
{
}

int				player::getLifetime() const
{
  return (this->_lifetime);
}

int				player::getLvl() const
{
  return (this->_lvl);
}

bool				player::getHungry() const
{
  return (this->_hungry);
}

bool				player::getAlive() const
{
  return (this->_alive);
}

std::map<std::string, int>	player::getInventory() const
{
  return (this->_inventory);
}

std::map<std::string, int>	player::getToFind() const
{
  return (this->_toFind);
}

object				&player::getToGet()
{
  return (this->_toGet);
}

int				player::getToMove() const
{
  return (this->_toMove);
}

Client				*player::getSocket() const
{
  return (this->_socket);
}

void				player::setLifetime(int time)
{
  this->_lifetime = time;
}

void				player::setLvl(int lvl)
{
  this->_lvl = lvl;
}

void				player::setHungry(bool hungry)
{
  this->_hungry = hungry;
}

void				player::setAlive(bool alive)
{
  this->_alive = alive;
}

void				player::setToGet(object newObject)
{
  this->_toGet = newObject;
}

void				player::setToMove(int move)
{
  this->_toMove = move;
}

void				player::setSocket(std::string host, std::string port)
{
  this->_socket = new Client(host, port);
}

bool	player::forward()
{
  std::string	str;

  this->_lifetime -= 7;
  this->_socket->sendMessage("avance");
  str = this->_socket->recieveMessage();
  if (str.compare("ok\n") == 0)
    return true;
  return false;
}

bool	player::right()
{
  std::string	str;

  this->_lifetime -= 7;
  this->_socket->sendMessage("droite");
  str = this->_socket->recieveMessage();
  if (str.compare("ok\n") == 0)
    return true;
  return false;
}

bool	player::left()
{
  std::string	str;

  this->_lifetime -= 7;
  this->_socket->sendMessage("gauche");
  str = this->_socket->recieveMessage();
  if (str.compare("ok\n") == 0)
    return true;
  return false;
}

bool	player::watch()
{
  std::string	str;

  this->_lifetime -= 7;
  this->_socket->sendMessage("voir");
  str = this->_socket->recieveMessage();
  this->parse(str);
  return true;
}

bool	player::inventory()
{
  return true;
}

bool	player::take()
{
  std::string	str;

  this->_lifetime -= 7;
  str = "prend ";
  str += this->_toGet.ress;
  this->_socket->sendMessage(str);
  str = this->_socket->recieveMessage();
  if (str.compare("ko\n") == 0)
    {
      this->_toGet.ress = "";
      return false;
    }
  if (str.compare("ok\n") == 0)
    {
      this->_toFind.find(this->_toGet.ress)->second--;
      if (this->_toGet.ress.compare("nourriture") == 0)
	this->_lifetime += 126;
      this->_toGet.ress = "";
      return true;
    }
}

bool	player::drop(std::string ress)
{
  std::string	str;
  bool		i;

  this->_lifetime -= 7;
  str = "pose ";
  str += ress;
  this->_socket->sendMessage(str);
  while (i)
    {
      if (str.compare("ok") == 0)
	i = false;
      if (str.compare("ko") == 0)
	i = false;
      str = this->_socket->recieveMessage();
    }
  if (str.compare("ok") == 0)
    {
      // diminuer la ressource poser
    }
  return true;
}

bool	player::expulse()
{
  std::string	str;

  this->_lifetime -= 7;
  this->_socket->sendMessage("expulse");
  while (str.compare("ok") != 0 || str.compare("ko") != 0)
    str = this->_socket->recieveMessage();
  return true;
}

bool	player::talk(std::string message)
{
  std::string	str;

  this->_lifetime -= 7;
  str = "broadcast ";
  str += message;
  this->_socket->sendMessage(str);
  while (str.compare("ok") != 0)
    str = this->_socket->recieveMessage();
  return true;
}

bool	player::elevation()
{
  std::string	str;

  this->_lifetime -= 300;
  this->_socket->sendMessage("incantation");
  while (str.find("elevation") != std::string::npos)
    str = this->_socket->recieveMessage();
  return true;
}

bool	player::fork()
{
  std::string	str;

  this->_lifetime -= 42;
  this->_socket->sendMessage("fork");
  str = this->_socket->recieveMessage();
  if (str.compare("ok\n") == 0)
    return true;
  return false;
}

int	player::connect_nbr()
{
  std::string	str;
  int		nb;

  this->_socket->sendMessage("connect_nbr");
  str = this->_socket->recieveMessage();
  nb = std::atoi(str.c_str());
  return (nb);
}

bool	player::death()
{
  this->_alive = false;
  return false;
}

bool	player::needed(std::string ressource, int pos)
{
  std::map<std::string, int>::iterator	it;

  it = this->_toFind.find(ressource);
  if (_hungry == false)
    {
      if (ressource.compare("nourriture") != 0)
	if (it != this->_toFind.end())
	  if (it->second > 0)
	    {
	      it->second--;
	      this->_toGet.ress = ressource;
	      this->_toGet.vect = this->_pov.find(pos)->second;
	      return (true);
	    }
    }
  else
    {
      if (it != this->_toFind.end())
	if (ressource.compare("nourriture") == 0)
	  {
	    this->_toGet.ress = ressource;
	    this->_toGet.vect = this->_pov.find(pos)->second;
	    return (true);
	  }
    }
  return (false);
}
