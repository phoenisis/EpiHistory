/*
**  inc/Bomb.hh
**  Bomberman
**
**  Created by Evan HERVE on 03/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef	__BOMB_HH__
# define __BOMB_HH__

# include "AObject.hh"
# include "Vector3f.hh"
# include "Bomberlib.hh"
# include "Fire.hh"
# include "Map.hh"

class Bombe : public AObject
{
public:
  Bombe(int, int, int, Fire *);
  ~Bombe();

  void initialize();
  void update(gdl::GameClock const &, gdl::Input &);
  void draw();
  void draw_object(Vector3f *);
  void explose();
  std::vector<std::pair<Vector3f*, float> > getposition_b() const;

private:
  gdl::Model model_;
  int		_posX;
  int		_posY;
  int		_power;
  Fire		*_fire;

};

#endif //!__BOMB_HH__
