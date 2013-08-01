#ifndef __CAMERA_H__
#define __CAMERA_H__


#include "Vector3f.hh"
#include "GameClock.hpp"
#include "Input.hpp"

class Camera
{
 public:
  Camera(Vector3f *position, Vector3f *rotation);
  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &);

  Vector3f *position_;
  Vector3f *rotation_;
};

#endif
