#if DEBUG
#include <iostream>
#endif /* DEBUG */

#include "Game.hpp"
#include "GameImpl.hpp"

namespace gdl
{
  Game::Game(void)
    : window_(), gameClock_(), input_(window_), gameInternal_(GameImpl::getInstance())
  {
  }

  Game::~Game(void) { }

  void		Game::run(void)
  {
    // Initialization from user
    this->initialize();

    // Initialization of clock
    this->gameClock_.play();

    // Main loop
    while (this->window_.isOpened())
      {
	// Check if the window is closed
	this->window_.catchEvent();

	// Update clock
	this->gameClock_.update();

	// Update from user
	this->update();

	if (!this->window_.isOpened())
	  break;

	// Draw from user
	this->draw();

	this->window_.display();
      }
    this->unload();
  }

  const std::string&	Game::getContentRoot()	const
  {
    return GameImpl::getInstance().ContentRoot;
  }

  void			Game::setContentRoot(const std::string& name)
  {

#if DEBUG
    std::cout << "Content root Changed : old("<< GameImpl::getInstance().ContentRoot;
    std::cout << ") new (" << name << ")" << std::endl;
#endif /* DEBUG*/ 
    GameImpl::getInstance().ContentRoot = name;
  }

}
