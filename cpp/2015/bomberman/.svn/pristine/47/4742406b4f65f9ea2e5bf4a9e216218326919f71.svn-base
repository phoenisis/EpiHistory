/*
**  inc/Graph.hh
**  Bomberman
**
**  Created by Quentin PIDOUX on 30/04/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef Graph_hh_
# define Graph_hh_
# include "Bomberlib.hh"
# include "MenuCamera.hh"
# include "Vector3f.hh"
# include "AObject.hh"
# include <list>

namespace Disp
{
  class MenuLabel : public AObject
  {
  public :
    MenuLabel(int x, int y, int sizeX, int sizeY);
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
    int  MenuCurr;
    bool MenuDecide;
    std::list<AObject*> objects_;

  private :
    gdl::Image	texture_;
    std::map<int, gdl::Image > menu_model;
    int	x;
    int	y;
    int	sizeX;
    int	sizeY;
  };

  class Menu : public gdl::Game
  {
  public:
    Menu();
    ~Menu();
    void add_object(AObject *);
    void close();
    MenuLabel *lbl_;

  protected:
    void initialize();
    void update();
    void draw();
    void unload();
    void intro();

    std::list<AObject*> objects_;

  private:
    MenuCamera		camera_;
  };
}

#endif
