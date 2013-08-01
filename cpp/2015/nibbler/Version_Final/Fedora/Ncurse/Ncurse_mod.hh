//
//  Ncurse_mod.hh
//  Nibbler
//
//  Created by quentin PIDOUX on 06/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#ifndef		_Ncurse_mod_hh
#define		_Ncurse_mod_hh

#include "../IDisplay.hh"

class	Ncurse_mod : public IDisplay
{
public :
  Ncurse_mod();
  ~Ncurse_mod();

  void	init(int x, int y);
  void	print_map(int x, int y);
  void	print_snake(int x, int y, bool isHead);
  void	print_apple(int x, int y);
  void	print_score(int highscore, int score, int apple_eat, int x);
  int	get_key();
  int	new_game();
  void	close();
};

#endif
