/*
**  inc/Player.hh
**  Bomberman
**
**  Created by Quentin PIDOUX on 01/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef Player_hh_
# define Player_hh_

# include "MenuCamera.hh"
# include "AObject.hh"
# include "Map.hh"
# include "Bomb.hh"

class Bombe;

class Player: public AObject
{
public:
  Player(map::map *map, Bombe *bomb);
  ~Player();

  void initialize();
  void update(gdl::GameClock const &, gdl::Input &);
  void draw();
  void draw_object(Vector3f *);
  std::vector<std::pair<Vector3f*, float> > getBomb() const;
  int getPower() const;
  int getNbBombs() const;
  float getPosX() const;
  float getPosY() const;
  void setPower(const int);
  void setNbBombs(const int);
  void setPosX(const int);
  void setPosY(const int);
  bool isAlive() const;
  void isKill();
  virtual void Action(gdl::Input &);

protected:
  Bombe *bomb;
  gdl::Model model_;
  map::map   *map;
  std::vector<int> posed_bombs;
  Vector3f *position_;
  Vector3f *rotation_;

  bool alive;
  int _power;
  int _nbBombs;
};

#endif
