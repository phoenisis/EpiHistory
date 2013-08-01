
#include <iostream>
#include "toDisplay.hpp"

// _CTOR

toDisplay::toDisplay(IApplication  *app)
{
  this->_app = app;
}

// Affichage sur screen

void	toDisplay::display() const
{
  std::vector<Case *>::const_iterator	it;

  for (it = this->_storage.begin(); it != this->_storage.end(); ++it)
    this->_app->putOnScreen(*it);
}

// Recupere ce qu'on a stocke auparavant

std::vector<Case *> const	&toDisplay::getStorage() const
{
  return (this->_storage);
}
