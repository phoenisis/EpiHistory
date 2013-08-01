#include "Exo-1.h"
#include <stdlib.h>
#include <stdio.h>


static void    KoalaInitializer(t_koala* this, char* _name, char _isALegend)
{
  NewCthulhu();
  this->m_parent.m_name =  _name;
  this->m_isALegend = _isALegend;  
  if (this->m_isALegend == 1)
    this->m_parent.m_power = 42;
  else 
    this->m_parent.m_power = 0;
}

static void    CthulhuInitializer(t_cthulhu* this)
{
  this->m_power = 42;
  this->m_name = "Cthulhu";
}

t_cthulhu*    NewCthulhu()
{

  t_cthulhu * new = malloc (sizeof(new));
  CthulhuInitializer(new);
  printf("----\n");
  printf("Building Cthulhu\n");
  return (new);
}

void        PrintPower(t_cthulhu* this)
{
  printf("Power => %d\n", this->m_power);
}

void        Attack(t_cthulhu* this)
{
  if (this->m_power < 42)
    {
      printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    }
  else 
    {
      this->m_power = this->m_power - 42;
      printf("%s attacks and destroys the city\n", this->m_name);
    }
}

void        Sleeping(t_cthulhu* this)
{
  this->m_power = this->m_power + 42000;
  printf("%s sleeps\n", this->m_name); 
}

t_koala*    NewKoala(char* name, char _isALegend)
{
  t_koala * new = malloc (sizeof(new));
  KoalaInitializer(new, name, _isALegend);
  printf("Building %s\n", name);
  return (new);
}

void        Eat(t_koala* this)
{
  this->m_parent.m_power = this->m_parent.m_power + 42;
  printf("%s eats\n", this->m_parent.m_name);
}
