//
// Cagette.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d15m/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Tue Jan 18 14:58:08 2011 quentin PIDOUX
// Last update Wed Jan 19 08:19:07 2011 quentin PIDOUX
//

#include "Cagette.h"
#include "FruitNode.h"
#include <string>

Cagette::Cagette(int size)
{
  this->Node = 0;
  this->size = size;
  this->nbFru = 0;
}

Cagette::~Cagette()
{
}
 
int Cagette::nbFruit() const
{
  return (this->nbFru);
}

int Cagette::getSize() const
{
  return (this->size);
}

 bool Cagette::putFruit(Fruit* f)
 {
   FruitNode * FN;
   FruitNode * NewFN;

   FN = this->Node;

   while (FN != 0 && FN->next != 0 && f != FN->frut)
     {
       FN = FN->next;
     }
   if (this->nbFru >= size || f == FN->frut)
     {
       return (false);
     }  
   else 
     {
       NewFN = new FruitNode[1];
       NewFN->frut = f;
       NewFN->next = 0;
       if (FN == 0)
	 FN = NewFN;
       else 
	 FN->next = NewFN;
       this->nbFru++;
       return (true);
     }
 }

 Fruit* Cagette::PickFruit()
 {
   Fruit* tata = this->Node->frut;

   if (tata == 0)
     return (0);
   else if (this->Node->next != 0)
     {
       this->Node = this->Node->next;
     }
   else 
     {
       this->Node = 0; 
     }
  nbFru--;
  return (tata);
}

FruitNode *Cagette::head() const
{
  return (this->Node);
}
