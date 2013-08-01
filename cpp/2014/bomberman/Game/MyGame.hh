#ifndef __MYGAME_H__
#define __MYGAME_H__

#include <cstdlib>
#include <list>
#include <string>

#include "Game.hpp"
#include "Camera.hh"
#include "AObject.hh"
#include "Player.hh"
#include "Map.hh"


class MyGame : public gdl::Game
{
public:
  MyGame();
  void   initialize(void);
  void   update(void);
  void   draw(void);
  void   unload(void);

  void   add_object(AObject *obj);
  void	 setMap(Map *M);
  void	 setPlayer1(Player *player);
  void	 setPlayer2(Player *player);

  Model::Bomberman *getPlayer1() const;
  Model::Bomberman *getPlayer2() const;

  void   save_game(std::string str);
  void   save_player();
  void   save_bomb();

  bool	 didYouFail() const;

private:

  std::string		str;
  std::list<AObject*>   objects_;
  Map			*map;
  Player		*player1;
  Player		*player2;
};



#endif
