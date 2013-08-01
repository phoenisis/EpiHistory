#include <cstdlib>
#include <iostream>

#include "bomberlib.hh"
#include "MyGame.hh"
#include "AObject.hh"
#include "Object.hh"
#include "Player.hh"
#include "Primitive.hh"
#include "Map.hh"
#include "Blocs.hh"
#include "Vector3f.hh"
#include "Fire.hh"
#include "Bonus.hh"
#include "Config.hh"
#include "Menu.hh"


int main(void)
{
  Menu			*main_menu   = new Menu;
  Primitive::MenuLabel  *menu_label  = new Primitive::MenuLabel(-25, -10, 50, 20);

  MyGame		*game        = new MyGame;
  Bloc::Breakable	*breakable   = new Bloc::Breakable();
  Bloc::Unbreakable	*unbreakable = new Bloc::Unbreakable();
  Map			*map         = new Map(breakable, 16, 16);
  Bonus::Flamme		*bonus_f     = new Bonus::Flamme(map);
  Bonus::Bombe		*bonus_b     = new Bonus::Bombe(map);
  Primitive::Rectangle	*base        = new Primitive::Rectangle(0, 0, map->getSizeX(), map->getSizeY());
  Model::Fire		*fire	     = new Model::Fire(game);
  Model::Bomb		*bomb	     = new Model::Bomb(map, fire);
  Config1		config1;
  Config2		config2;
  Player		*player1     = new Player(map, bomb, &config1);
  Player		*player2     = new Player(map, bomb, &config2);
  int			i = 0;

  while (i < map->getNb_blocs())
    {
      if (map->get_bloc(map->getPosX(i), map->getPosY(i)) == '#')
	unbreakable->add_positions(new Vector3f((float)map->getPosX(i),
						(float)map->getPosY(i), 0.0f), 0.0f);
      else if (map->get_bloc(map->getPosX(i), map->getPosY(i)) == 'o')
	breakable->add_positions(new Vector3f((float)map->getPosX(i),
					      (float)map->getPosY(i), 0.0f), 0.0f);
      i++;
    }

  breakable->SetBonus(bonus_f, bonus_b);
  game->setPlayer1(player1);
  game->setPlayer2(player2);
  game->add_object(player1);
  game->add_object(player2);
  game->add_object(base);
  game->add_object(breakable);
  game->add_object(unbreakable);
  game->add_object(bomb);
  game->add_object(fire);
  game->add_object(bonus_f);
  game->add_object(bonus_b);

  main_menu->add_object(menu_label);
  main_menu->lbl_ = menu_label;
  main_menu->run();

  switch (menu_label->MenuCurr) {
  case 1:
    game->run();
    break;
  case 2:
    //load

    break;
  case 3:
    //save

    break;
  default:
    //exit
    break;
  }

  game->run();
  return EXIT_SUCCESS;
}
