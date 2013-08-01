#ifndef __MENU_H__
#define __MENU_H__

#include <cstdlib>
#include <list>
#include <iostream>
#include <string>

#include "Game.hpp"
#include "MenuCamera.hh"
#include "AObject.hh"
#include "Object.hh"
#include "Input.hpp"
#include "Primitive.hh"


class Menu : public gdl::Game
{
public:
	Menu();
  void   initialize(void);
  void   update(void);
  void   draw(void);
  void   unload(void);

  void   add_object(AObject *obj);
  Primitive::MenuLabel*	lbl_;


private:
  MenuCamera    camera_;
  std::list<AObject*>   objects_;
};

#endif
