
#ifndef	 __LIB_NIBBLER_SDL_HPP__
#define	 __LIB_NIBBLER_SDL_HPP__

#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Player.hpp"
#include "IApplication.hpp"

class				SDL : public IApplication
{

public:
  SDL(size_t, size_t);
  virtual ~SDL();

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

  SDL_Surface*			_screen;
  SDL_Surface*			_imgLand;

  SDL_Event			_event;

  void				displayScore(Player const * const);

  void				moveAndFlip(Player *);
  void				moveAndFlip(Player *, direction dir);

};

extern "C"
{
  IApplication*	fuckInterface(size_t w, size_t h) { return ( new SDL(w, h) ); }
}


#endif /* ! __LIB_NIBBLER_SDL_HPP__ */
