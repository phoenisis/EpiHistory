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
      ALIEN,
      BUZZ,
      WOODY
  };

    Toy();
    Toy(ToyType, const std::string&, const std::string&);
    ~Toy();
    
    ToyType getType() const;
    std::string getName() const ;
    void setName(std::string);
    std::string getAscii() const;
    void setAscii(const std::string&);
    virtual void speak(const std::string &);

    std::string Name;
    ToyType Type;
    Picture ASCII;
    Toy &operator << (const std::string &);
};

std::ostream & operator <<(std::ostream &, const Toy &);

#endif
