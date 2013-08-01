#include "Primitive.hh"
#include "Vector3f.hh"

namespace Primitive
{
  Rectangle::Rectangle(int x, int y, int sizeX, int sizeY)
  {
    this->x = x;
    this->y = y;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
  }


  void Rectangle::initialize(void)
  {
    this->texture_ = gdl::Image::load("../GDL-library/textures/Grass_1.png");
  }


  void Rectangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
  }


  void Rectangle::draw(void)
  {
    int		x = 0;
    int		y = 0;
    
    this->texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);

    
    while (y < this->sizeY)
      {
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f((float)(x), 0.0f, (float)(y));
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f((float)(x + 1), 0.0f, (float)(y));
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f((float)(x + 1), 0.0f, (float)(y + 1));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f((float)(x), 0.0f, (float)(y + 1));
	x++;
	if (x > this->sizeX - 1)
	  {
	    x = 0;
	    y++;
	  }
      }
    glEnd();
  }

  
  void	Rectangle::draw_object(Vector3f *position)
  {

  }


}
