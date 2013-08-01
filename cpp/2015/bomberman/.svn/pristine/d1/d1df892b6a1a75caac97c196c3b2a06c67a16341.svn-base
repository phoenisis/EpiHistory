/*
**  inc/Bomb.hh
**  Bomberman
**
**  Created by Evan HERVE on 03/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef		__BOMB_HH__
# define	__BOMB_HH__

#include "Map.hh"

class Bomb
{
public:
  Bomb(int, int, int);
  ~Bomb();
  //Coplien
  Bomb(const Bomb &);
  Bomb&		operator=(const Bomb &);
  void		doExplosion(map::map &);
  void		explose(map::map &, int, int, int, int, int);
  void		generateBonus(map::map &, int);
private:
  int		_posX;
  int		_posY;
  int		_power;
  int		_begX;
  int		_begY;
  int		_endX;
  int		_endY;
};

#endif		//!__BOMB_HH__
