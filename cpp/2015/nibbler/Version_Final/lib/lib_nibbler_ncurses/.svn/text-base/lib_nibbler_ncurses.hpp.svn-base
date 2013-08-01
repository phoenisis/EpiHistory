
#ifndef	__LIB_NIBBLER_NCURSES_HPP__
#define	__LIB_NIBBLER_NCURSES_HPP__

#include <ncurses.h>
#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Player.hpp"
#include "IApplication.hpp"

#define	KEY_ESCAPE		27
#define	KEY_RETURN		10

class				NCurses : public IApplication
{
public:
  NCurses(size_t, size_t);
  virtual ~NCurses();

  int				getScrWidth() const;
  int				getScrHeight() const;

  size_t			getCaseWidth() const;
  size_t			getCaseHeight() const;

  virtual void			init(int, char **);
  virtual void			display(std::list<toDisplay *> const&);
  virtual void			putOnScreen(Case const * const);
  virtual void			mainLoop(Player *);
  virtual void			endingGame();

private:
  int				_scrWidth;
  int				_scrHeight;

  size_t			_caseWidth;
  size_t			_caseHeight;

  size_t			_speed;
  size_t			_score;

  bool				_end;
  bool				_gameOver;

  WINDOW*			_screen;

  void				displayScore(Player const * const);

  void				moveAndFlip(Player *);
  void				moveAndFlip(Player *, direction dir);
};

extern "C"
{
  IApplication*	fuckInterface(size_t w, size_t h) { return ( new NCurses(w, h) ); }
}

#endif /* ! __LIB_NIBBLER_NCURSES_HPP__ */
