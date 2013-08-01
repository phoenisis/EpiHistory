/*
**  inc/Fire.hh
**  Bomberman
**
**  Created by Evan HERVE on 03/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef		__FIRE__HH__
# define	__FIRE__HH__

# include "AObject.hh"
# include "Vector3f.hh"
# include "Bomberlib.hh"
# include "Map.hh"
# include "Mygame.hh"

class MyGame;

class Fire : public AObject
{
public:
  Fire(map::map *, int, int, int);
  ~Fire();

  void		generateBonus(int res, int x, int y);
  void		explose(int i, int y, int posx, int posy, int power);
  int		explose2(int posx, int posy);
  void		check_character(int, int);

  void initialize();
  void update(gdl::GameClock const &, gdl::Input &);
  void draw();
  void draw_object(Vector3f *);
  std::vector<std::pair<Vector3f*, float> > getposition_b() const;
   MyGame	*game;

private:
  gdl::Model	model_;
  int		_posX;
  int		_posY;
  int		_power;
  map::map *map;
};

#endif		//!__FIRE__HH__
