/*
**  inc/Mygame.hh
**  Bomberman
**
**  Created by Quentin PIDOUX on 30/04/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef Mygame_hh_
# define Mygame_hh_

# include "Bomberlib.hh"
# include "Map.hh"
# include "Player.hh"
# include "AObject.hh"
# include "MenuCamera.hh"
# include "Graph.hh"

# include <list>
# include <iostream>
# include <cstdlib>
# include <sys/stat.h>

class Player;
class Character;

class MyGame: public gdl::Game
{
public:
  MyGame();
  ~MyGame();
  void add_object(AObject *obj);
  void setMap(map::map *M);
  void	 setCharacter1(Character *player);
  void	 setCharacter2(Character *player);

  Player *getCharacter1() const;
  Player *getCharacter2() const;

protected:
  void initialize(void);
  void update(void);
  void draw(void);
  void unload(void);
  void save_game(std::string str);

private:
  Character *Character1;
  Character *Character2;
  MenuCamera camera_;
  std::string str;
  map::map *map;
  std::list<AObject*>   objects_;
  std::map<int, gdl::Model > my_model;
};

#endif
