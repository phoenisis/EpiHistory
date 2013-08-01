#include "MenuCamera.hh"
#include "Vector3f.hh"

MenuCamera::MenuCamera(void)
  : position_(0.0f, 30.0f, 6.0f), rotation_(0.0f, 0.0f, 0.0f)
{}

void MenuCamera::initialize(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 10000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(position_.x, position_.y, position_.z,
	    rotation_.x, rotation_.y, rotation_.z,
	    0.0f, 1.0f, 0.0f);
  
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

#include <iostream>

void  MenuCamera::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 10000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(position_.x, position_.y, position_.z,
	    rotation_.x, rotation_.y, rotation_.z,
	    0.0f, 1.0f, 0.0f);
  
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}



