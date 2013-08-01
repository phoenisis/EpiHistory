//
// Bloc.cpp for  in /home/fleuro_m//work/tmp
//
// Made by matthieu fleurot
// Login   <fleuro_m@epitech.net>
//
// Started on  Fri Jun  1 16:01:25 2012 matthieu fleurot
// Last update Sun Jun  3 23:10:35 2012 quentin pidoux
//

#include "../inc/Bloc.hh"

void	Bloc::ABloc::update(gdl::GameClock const & clock, gdl::Input &input)
{
  (void) input;
  this->_mymodel.update(clock);
}

void	Bloc::ABloc::draw_object(Vector3f *position)
{
  gdl::Model::Begin();

  this->_mymodel.play("Take 001");
  glPushMatrix();
  glTranslatef(position->x + 0.50, 0.0f, position->y - 0.50);
  glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
  this->_mymodel.draw();
  glPopMatrix();


  gdl::Model::End();
}

// --------------------------Wall------------------------

Bloc::Wall::Wall(map::map &my_map) : _map(my_map)
{}

Bloc::Wall::~Wall()
{}

void	Bloc::Wall::initialize()
{
  this->_mymodel = gdl::Model::load("./asserts/wall.FBX");
}

void	Bloc::Wall::draw()
{
  int		x;
  int		y;
  Vector3f	vec;

  for (y = 0; y < this->_map.getWidth(); y++)
    {
      for(x = 0; x < this->_map.getLength(); x++)
	{
	  if (this->_map.getPos(x, y) == 3)
	    {
	      vec.setX(x);
	      vec.setY(y);
	      vec.setZ(0);
	      this->draw_object(&vec);
	    }
	}
    }
}

// --------------------------BOX------------------------

Bloc::Box::Box(map::map &my_map) : _map(my_map)
{}

Bloc::Box::~Box()
{}

void	Bloc::Box::initialize()
{
  this->_mymodel = gdl::Model::load("./asserts/box.FBX");
}

void	Bloc::Box::draw()
{
  int		x;
  int		y;
  Vector3f	vec;

  for (y = 0; y < this->_map.getWidth(); y++)
    {
      for(x = 0; x < this->_map.getLength(); x++)
	{
	  if (this->_map.getPos(x, y) == 2)
	    {
	      vec.setX(x);
	      vec.setY(y);
	      vec.setZ(0);
	      this->draw_object(&vec);
	    }
	}
    }
}

// --------------------------Blank------------------------

Bloc::Blank::Blank(map::map &my_map) : _map(my_map)
{
  this->done = false;
}

Bloc::Blank::~Blank()
{}

void	Bloc::Blank::initialize()
{
  this->_mymodel = gdl::Model::load("./asserts/ground.FBX");
}

void	Bloc::Blank::draw()
{
  Vector3f	vec;

  vec.setX(0);
  vec.setY(0);
  vec.setZ(0);
  this->draw_object(&vec);
}

// --------------------------morebomb------------------------

Bloc::Morebomb::Morebomb(map::map &my_map) : _map(my_map)
{}

Bloc::Morebomb::~Morebomb()
{}

void	Bloc::Morebomb::initialize()
{
  this->_mymodel = gdl::Model::load("./asserts/bonus_bomb_up.FBX");
}

void	Bloc::Morebomb::draw()
{
  int		x;
  int		y;
  Vector3f	vec;

  for (y = 0; y < this->_map.getWidth(); y++)
    {
      for(x = 0; x < this->_map.getLength(); x++)
	{
	  if (this->_map.getPos(x, y) == 5)
	    {
	      vec.setX(x);
	      vec.setY(y);
	      vec.setZ(0);
	      this->draw_object(&vec);
	    }
	}
    }
}

// --------------------------lessbomb------------------------

Bloc::Lessbomb::Lessbomb(map::map &my_map) : _map(my_map)
{}

Bloc::Lessbomb::~Lessbomb()
{}

void	Bloc::Lessbomb::initialize()
{
  this->_mymodel = gdl::Model::load("./asserts/bonus_bomb_down.FBX");
}

void	Bloc::Lessbomb::draw()
{
  int		x;
  int		y;
  Vector3f	vec;

  for (y = 0; y < this->_map.getWidth(); y++)
    {
      for(x = 0; x < this->_map.getLength(); x++)
	{
	  if (this->_map.getPos(x, y) == 6)
	    {
	      vec.setX(x);
	      vec.setY(y);
	      vec.setZ(0);
	      this->draw_object(&vec);
	    }
	}
    }
}

// --------------------------morepower------------------------

Bloc::Morepower::Morepower(map::map &my_map) : _map(my_map)
{}

Bloc::Morepower::~Morepower()
{}

void	Bloc::Morepower::initialize()
{
  this->_mymodel = gdl::Model::load("./asserts/bonus_fire_up.FBX");
}

void	Bloc::Morepower::draw()
{
  int		x;
  int		y;
  Vector3f	vec;

  for (y = 0; y < this->_map.getWidth(); y++)
    {
      for(x = 0; x < this->_map.getLength(); x++)
	{
	  if (this->_map.getPos(x, y) == 7)
	    {
	      vec.setX(x);
	      vec.setY(y);
	      vec.setZ(0);
	      this->draw_object(&vec);
	    }
	}
    }
}

// --------------------------Lesspower------------------------

Bloc::Lesspower::Lesspower(map::map &my_map) : _map(my_map)
{}

Bloc::Lesspower::~Lesspower()
{}

void	Bloc::Lesspower::initialize()
{
  this->_mymodel = gdl::Model::load("./asserts/bonus_fire_down.FBX");
}

void	Bloc::Lesspower::draw()
{
  int		x;
  int		y;
  Vector3f	vec;

  for (y = 0; y < this->_map.getWidth(); y++)
    {
      for(x = 0; x < this->_map.getLength(); x++)
	{
	  if (this->_map.getPos(x, y) == 8)
	    {
	      vec.setX(x);
	      vec.setY(y);
	      vec.setZ(0);
	      this->draw_object(&vec);
	    }
	}
    }
}


// --------------------------fire------------------------

Bloc::fire::fire(map::map &my_map) : _map(my_map)
{}

Bloc::fire::~fire()
{}

void	Bloc::fire::initialize()
{
  this->_mymodel = gdl::Model::load("./asserts/fire.FBX");
}

void	Bloc::fire::draw()
{
  int		x;
  int		y;
  Vector3f	vec;

  for (y = 0; y < this->_map.getWidth(); y++)
    {
      for(x = 0; x < this->_map.getLength(); x++)
	{
	  if (this->_map.getPos(x, y) == 42)
	    {
	      vec.setX(x);
	      vec.setY(y);
	      vec.setZ(0);
	      this->draw_object(&vec);
	    }
	}
    }
}
