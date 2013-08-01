#ifndef _CAGETTE_H_
#define _CAGETTE_H_

#include "Fruit.h"
#include "FruitNode.h"
#include <string>

class Cagette
{
public:
    Cagette(const int size);
    Cagette(const Cagette&);
    Cagette operator = (const Cagette&);
    ~Cagette();

    Fruit* PickFruit();
    FruitNode* head()const;
    FruitNode* Node;

    int nbFruit()const;
    int getSize()const;
    bool putFruit(Fruit* f);

private:
    int nbFru;
    int size;
};

#endif
