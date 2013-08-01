#include "Kitchen.hh"
#include "Thread.hh"
#include <string.h>
#include <iostream>

Kitchen::Kitchen(const int nb, const int id)
{
  this->id = id;
  this->nb_cook = nb;
  this->p= new pipe(id);

  this->food["base"] = 5;
  this->food["tomato"] = 5;
  this->food["swiss"] = 5;
  this->food["hamme"] = 5;
  this->food["mushroom"] = 5;
  this->food["steak"] = 5;
  this->food["coatcheese"] = 5;
  this->food["aubergine"] = 5;
  this->food["love"] = 5;

  for (i = 0; i != nb ; i++)
    {
      thread th;
      this->cooker[i] = th;
    }
}

Kitchen::~Kitchen()
{
  delete this->p;
}

void Kitchen::send_msg(const std::string msg)
{
  this->p.writter(msg);
}

std::string Kitchen::listen_pipe()
{
  std::string msg;
  std::map<std::string,int>::iterator it;
  msg = this->p.reader(0);

  if (msg.compare("reload"))
    {
      for ( it=this->food.begin() ; it != this->food.end(); it++ )
        (*it).second++;
    }
  this->map = it;
}
