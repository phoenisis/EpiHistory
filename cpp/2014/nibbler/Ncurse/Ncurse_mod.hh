//
// Ncurse_mod.hh for Ncurse mod nibbler in /home/hubert_s//test/nibbler-2014-pidoux_q
//
// Made by sevan hubert
// Login   <hubert_s@epitech.net>
//
// Started on  Thu Mar 17 15:25:42 2011 sevan hubert
// Last update Sat Mar 17 20:00:17 2012 quentin pidoux
//

#ifndef		__NCURSE_MOD__
#define		__NCURSE_MOD__

#include "../IDisplay.hh"

class	Ncurse_mod : public IDisplay
{
public :
  Ncurse_mod();
  ~Ncurse_mod();

  virtual  void	init(int x, int y);
  virtual void	print_map(int x, int y);
  virtual void	print_snake(int x, int y, bool isHead);
  virtual void	print_apple(int x, int y);
  virtual void	print_score(int highscore, int score, int apple_eat, int x);
  virtual int	get_key();
  virtual int	new_game();
  virtual void	close();
};

#endif
