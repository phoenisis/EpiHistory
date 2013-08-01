#ifndef _CITRON_H_
#define _CITRON_H_

#include "Fruit.h"
#include <string>

class Citron : public Fruit
{
 public:
  Citron();
  Citron(const Citron&);
  Citron& operator=(const Citron&);
  ~Citron();
};

#endif
