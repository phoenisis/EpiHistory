#ifndef __AOBJECT_H__
#define __AOBJECT_H__

#include <utility>
#include <vector>

#include "bomberlib.hh"
#include "Vector3f.hh"

class    AObject
{
public:
  AObject(void) {}
  virtual void initialize(void) = 0;
  virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void draw(void) = 0;

  void	add_positions(Vector3f *position, float rotation);

protected:
  std::vector<std::pair<Vector3f*, float> >	positions;
};

#endif
