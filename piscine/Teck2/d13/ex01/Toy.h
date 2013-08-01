#ifndef _TOY_H_
#define _TOY_H_

#include <string>
#include <iostream>
#include "Picture.h"

class Toy
{
 public:
  enum ToyType
  {
    BASIC_TOY,
    ALIEN
  };

  Toy();
  Toy(const Toy&);
  Toy &operator=(const Toy&);
  Toy(ToyType type, const std::string& name, const std::string& ASCII);
  ~Toy();

  ToyType getType() const;
  std::string getName() const ;
  void setName(std::string);
  std::string getAscii() const;
  void setAscii(const std::string& ASCII);

  std::string Name;
  ToyType Type;
  Picture ASCII;
};

#endif
