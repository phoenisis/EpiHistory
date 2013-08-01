#include "Cagette.h"
#include "FruitNode.h"
#include <string>

Cagette::Cagette(const int size)
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
     delete NewFN;
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
