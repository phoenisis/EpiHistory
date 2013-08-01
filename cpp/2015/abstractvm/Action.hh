//
// Action.hh for  in /home/pidoux_q/abstractvm-2015-pidoux_q
//
// Made by Matthieu FLEUROT
// Login   <fleuro_m@epitech.net>
//
// Started on  Fri Feb 17 09:56:09 2012 Matthieu FLEUROT
// Last update Sun Feb 19 16:00:27 2012 Matthieu FLEUROT
//

#ifndef		_ACTION_HH_
# define	_ACTION_HH_

#include <string>
#include <iostream>
#include <map>
#include <list>
#include "IOperand.hpp"

class	action
{
  std::map<std::string, void (action::*)(std::string &)> _mymap;
  std::list<IOperand *> _mylist;
  void	mypush(std::string &line);
  void	mypop(std::string &line);
  void	mydump(std::string &line);
  void	myassert(std::string &line);
  void	myadd(std::string &line);
  void	mysub(std::string &line);
  void	mymul(std::string &line);
  void	mydiv(std::string &line);
  void	mymod(std::string &line);
  void	myprint(std::string &line);
  void	myexit(std::string &line);
  void	mycom(std::string &line);
  void	initmap();

protected:
  IOperand * a;
  IOperand * b;
  IOperand * res;

public :
  action();
  ~action();
   std::map<std::string, void (action::*)(std::string &)>const& getMap() const;

};

#endif		/*_ACTION_HH_*/
