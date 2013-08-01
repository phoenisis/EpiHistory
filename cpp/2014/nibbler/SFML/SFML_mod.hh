//
//  SFML_Mod.hh
//
//
//  Created by quentin PIDOUX on 06/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#ifndef _SFML_Mod_hh
#define	_SFML_Mod_hh

#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "../IDisplay.hh"

class	SFML_mod : public IDisplay
{
public :
  SFML_mod(sf::RenderWindow *app);
  ~SFML_mod();

virtual   void	init(int x, int y);
virtual   void	print_map(int x, int y);
virtual   void	print_snake(int x, int y, bool isHead);
virtual   void	print_apple(int x, int y);
virtual   void	print_score(int highscore, int score, int apple_eat, int x);
virtual   int	get_key();
virtual  int	new_game();
virtual  void	close();

private :
  sf::RenderWindow	*app;
};

#endif
