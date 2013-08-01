
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <list>
#include <dlfcn.h>
#include "CExceptions.hpp"
#include "Nibbler.hpp"

// _CTOR

Nibbler::Nibbler(size_t w, size_t h, std::string const &lib)
{

  std::string           lib_path = "./" + lib;
  IApplication*		(*external_lib)(size_t, size_t);

  if ((this->_handle = dlopen(lib_path.c_str(), RTLD_LAZY)) != NULL)
    {
      external_lib = reinterpret_cast<IApplication* (*)(size_t, size_t)>(dlsym(this->_handle, "fuckInterface"));
      if (external_lib != NULL)
	{
	  this->_app = external_lib(w, h);

	  this->_field = new Field(this->_app, w, h);
	  this->_player = new Player(this->_app, this->_field, NULL);
	  this->_prey = new Prey(this->_app, this->_field, this->_player);
	  this->_player->setPrey(this->_prey);

	  this->_displayObj.push_back(this->_field);
	  this->_displayObj.push_back(this->_prey);
	  this->_displayObj.push_back(this->_player);
	}
      else
	throw CFatal("Fatal error : Failed to load symbole");
    }
  else
    throw CFatal("Fatal error : Failed to load library: " + lib + ".");
}

// _DTOR

Nibbler::~Nibbler()
{
  dlclose(this->_handle);
}

// Initialize

void		Nibbler::init(int argc, char **argv)
{
  this->_app->init(argc, argv);
}

// Affichage

void		Nibbler::display()
{
  this->_app->display(this->_displayObj);
}

// Loop

void		Nibbler::loop()
{
  this->_app->mainLoop(this->_player);
}

// Affichage sur screen

void		Nibbler::putOnScreen(Case const * const cs)
{
  this->_app->putOnScreen(cs);
}
