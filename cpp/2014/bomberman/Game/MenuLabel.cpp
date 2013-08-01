#include "Primitive.hh"
#include <string>
#include <iostream>

namespace Primitive
{
  MenuLabel::MenuLabel(int x, int y, int sizeX, int sizeY)
  {
    this->x = x;
    this->y = y;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->MenuCurr = 1;
    this->MenuDecide = false;
  }

  void MenuLabel::initialize(void)
  {
    this->texture_ = gdl::Image::load("../GDL-library/textures/menu_big_play.png");
  }

  void MenuLabel::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    if (this->MenuDecide == false) {
      if (input.isKeyDown(gdl::Keys::Up) == true)
	{
	  this->texture_ = gdl::Image::load("../GDL-library/textures/menu_big_play.png");
	  this->MenuCurr = 1;
	}
      if (input.isKeyDown(gdl::Keys::Left) == true)
	{
	  this->texture_ = gdl::Image::load("../GDL-library/textures/menu_big_load.png");
	  this->MenuCurr = 2;
	}
      if (input.isKeyDown(gdl::Keys::Right) == true)
	{
	  this->texture_ = gdl::Image::load("../GDL-library/textures/menu_big_save.png");
	  this->MenuCurr = 3;
	}
      if (input.isKeyDown(gdl::Keys::Down) == true)
	{
	  this->texture_ = gdl::Image::load("../GDL-library/textures/menu_big_exit.png");
	  this->MenuCurr = 4;
	}
      if (input.isKeyDown(gdl::Keys::Space) == true)
	{
	  this->MenuDecide = true;
	}
    }
  }

  void MenuLabel::draw(void)
  {
    texture_.bind();
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f((float)(this->x), 000.0f, (float)(this->y));
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f((float)(this->x + this->sizeX), 000.0f, (float)(this->y));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f((float)((this->x + this->sizeX)), 000.0f, (float)((this->y + this->sizeY)));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f((float)(this->x), 000.0f, (float)(this->y + this->sizeY));

    glEnd();
  }
}
