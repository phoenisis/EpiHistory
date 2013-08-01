#ifndef	__OBJECT__
#define __OBJECT__

#include "AObject.hh"
#include "Vector3f.hh"

namespace Object
{
  class Cube : public AObject
  {
  public :
    Cube(float sizeX, float sizeY, float sizeZ);
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
    void draw_object(Vector3f *position);
    
  protected :
    gdl::Image texture_;

    float	sizeX;
    float	sizeY;
    float	sizeZ;
  };
}


#endif
