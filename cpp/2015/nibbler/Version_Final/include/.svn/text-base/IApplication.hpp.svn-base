
#ifndef __IAPPLCATION_HPP__
# define __IAPPLCATION_HPP__

#include <list>
class	Case;
class	Player;
class	toDisplay;

class	IApplication
{
public:
  virtual void		init(int argc, char **argv) = 0;
  virtual void		display(std::list<toDisplay *> const&) = 0;
  virtual void		putOnScreen(Case const * const) = 0;
  
  virtual void		mainLoop(Player *) = 0;
  virtual void		endingGame() = 0;
  
  virtual int		getScrWidth() const = 0;
  virtual int		getScrHeight() const = 0;

  virtual size_t	getCaseWidth()	const = 0;
  virtual size_t	getCaseHeight()	const = 0;
  virtual		~IApplication() { };
};

#endif /* ! __IAPPLCATION_HPP__ */
