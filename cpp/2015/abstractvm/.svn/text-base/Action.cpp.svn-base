//
// Action.cpp for  in /home/pidoux_q/abstractvm-2015-pidoux_q
//
// Made by Matthieu FLEURO
// Login   <fleuro_m@epitech.net>
//
// Started on  Fri Feb 17 09:55:40 2012 Matthieu FLEURO
// Last update Sun Feb 19 16:20:14 2012 Matthieu FLEUROT
//

#include <stdexcept>
#include "CreatOperand.hh"
#include "IOperand.hpp"
#include "Action.hh"

void	action::mypush(std::string &line)
{
  std::string	type;
  std::string	value;
  creator crea;

  if (line.size() > 0)
    {
      type = line;
      type.erase(type.find("("));
      value = line;
      value.erase(0, value.find("(") + 1);
      value.erase(value.find(")"));
      if (!type.compare("int8"))
	this->res = crea.creatOperand(INT8, value);
      else if (!type.compare("int16"))
	this->res = crea.creatOperand(INT16, value);
      else if (!type.compare("int32"))
	this->res = crea.creatOperand(INT32, value);
      else if (!type.compare("float"))
	this->res = crea.creatOperand(FLOAT, value);
      else if (!type.compare("double"))
	this->res = crea.creatOperand(DOUBLE, value);
      else
	throw std::range_error("incorect type of value");
      this->_mylist.push_front(res);
    }
  else
    {
      throw std::runtime_error("no value to push");
    }
}

void	action::mypop(std::string &line)
{
  std::list<IOperand *>::iterator it;

  if (!line.size())
    {
      it = this->_mylist.begin();
      this->_mylist.erase(it);
    }
  else
    throw std::runtime_error("To many member for pop");
}

void	action::mydump(std::string &line)
{
  std::list<IOperand *>::iterator it;

  if (!line.size())
    for (it = this->_mylist.begin(); it != this->_mylist.end(); it++)
      std::cout << (*it)->toString() << std::endl;
  else
    throw std::runtime_error("To many member for dump");
}

void	action::myassert(std::string &line)
{
  this->res = this->_mylist.front();

  if (res->toString().compare(line))
    throw std::range_error("incorect type of assert");
}

void	action::myadd(std::string &line)
{
  if (line.size() == 0)
    {
      if (this->_mylist.size() > 1)
	{
	  this->b = this->_mylist.front();
	  this->_mylist.pop_front();
	  this->a = this->_mylist.front();
	  this->_mylist.pop_front();
	  this->res = *this->a + *this->b;
	  this->_mylist.push_front(res);
	}
      else
	throw std::runtime_error("Missing member for Addition");
    }
  else
    throw std::runtime_error("To many member for Addition");
}

void	action::mysub(std::string &line)
{
  if (line.size() == 0)
    {
      if (this->_mylist.size() > 1)
	{
	  this->b = this->_mylist.front();
	  this->_mylist.pop_front();
	  this->a = this->_mylist.front();
	  this->_mylist.pop_front();
	  this->res = *this->a - *this->b;
	  this->_mylist.push_front(res);
	}
      else
	throw std::runtime_error("Missing member for Substraction");
    }
  else
    throw std::runtime_error("To many member for Substraction");
}

void	action::mymul(std::string &line)
{
  if (line.size() == 0)
    {
      if (this->_mylist.size() > 1)
	{
	  this->b = this->_mylist.front();
	  this->_mylist.pop_front();
	  this->a = this->_mylist.front();
	  this->_mylist.pop_front();
	  this->res = *this->a * *this->b;
	  this->_mylist.push_front(res);
	}
      else
	throw std::runtime_error("Missing member for Multiplication");
    }
  else
    throw std::runtime_error("To many member for Multiplication");
}

void	action::mydiv(std::string &line)
{
  if (line.size() == 0)
    {
      if (this->_mylist.size() > 1)
	{
	  this->b = this->_mylist.front();
	  this->_mylist.pop_front();
	  this->a = this->_mylist.front();
	  this->_mylist.pop_front();
	  this->res = *this->a / *this->b;
	  this->_mylist.push_front(res);
	}
      else
	throw std::runtime_error("Missing member for Division");
    }
  else
    throw std::runtime_error("To many member for Division");
}

void	action::mymod(std::string &line)
{
 if (line.size() == 0)
   {
     if (this->_mylist.size() > 1)
       {
	 this->b = this->_mylist.front();
	 this->_mylist.pop_front();
	 this->a = this->_mylist.front();
	 this->_mylist.pop_front();
	 this->res = *this->a % *this->b;
	 this->_mylist.push_front(res);
       }
     else
       throw std::runtime_error("Missing member for Modulo");
   }
 else
   throw std::runtime_error("To many member for Modulo");
}

void	action::myprint(std::string &line)
{
  if (!this->_mylist.size())
    throw std::range_error("Not Enought Value for print");
  else
    {
      this->res = this->_mylist.front();

      if (!line.size())
	if (this->res->getType() != INT8)
	  throw std::runtime_error("incorect type of assert");
	else
	  {
	    int dest = atoi(this->res->toString().c_str());
	    write(1, &dest, 1);
	    std::cout << std::endl;
	  }
      else
	throw std::runtime_error("To many member for print");
    }
}

void	action::myexit(std::string &line)
{
  if (!line.size())
    while (this->_mylist.size())
      this->mypop(line);
  throw std::logic_error("end of file");
}

void	action::mycom(std::string &line)
{
  (void)line;
}

void	action::initmap()
{
  this->_mymap["push"] = &action::mypush;
  this->_mymap["pop"] = &action::mypop;
  this->_mymap["dump"] = &action::mydump;
  this->_mymap["assert"] = &action::myassert;
  this->_mymap["add"] = &action::myadd;
  this->_mymap["sub"] = &action::mysub;
  this->_mymap["mul"] = &action::mymul;
  this->_mymap["div"] = &action::mydiv;
  this->_mymap["mod"] = &action::mymod;
  this->_mymap["print"] = &action::myprint;
  this->_mymap["exit"] = &action::myexit;
  this->_mymap[";"] = &action::mycom;
}

std::map<std::string, void (action::*)(std::string &)> const& action::getMap() const
{
  return (this->_mymap);
}

action::action()
{
  this->initmap();
}

action::~action()
{
}

