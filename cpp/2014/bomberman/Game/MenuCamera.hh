#ifndef __MenuCamera_H__
#define __MenuCamera_H__


#include "Vector3f.hh"
#include "GameClock.hpp"
#include "Input.hpp"

class MenuCamera
{
 public:
  MenuCamera();
  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &);
 private:
  Vector3f position_;
  Vector3f rotation_;
};

#endif
