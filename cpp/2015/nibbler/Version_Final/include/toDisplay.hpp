
#ifndef  __TODISPLAY_HPP__
# define __TODISPLAY_HPP__

#include <vector>
#include "Case.hpp"
#include "IApplication.hpp"

class	toDisplay
{
private:  
  toDisplay(toDisplay const &);
  toDisplay	&operator=(toDisplay const &);

protected:
  IApplication			*_app;
  std::vector<Case *>		_storage;

public:
  toDisplay(IApplication  *app);
  ~toDisplay() {}
  
  void				display() const;
  std::vector<Case *> const&	getStorage() const;
};

#endif /* ! __TODISPLAY_HPP__ */
