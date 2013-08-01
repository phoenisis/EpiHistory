#ifndef __VECTOR3F_H__
#define __VECTOR3F_H__

#include "bomberlib.hh"

struct Vector3f
{
  float x;
  float y;
  float z;
  Vector3f(void);
  Vector3f(float x, float y, float z);
  void setX(float x);
  void setZ(float y);
  void setY(float z);
  void addX(float x);
  void addY(float y);
  void addZ(float z);
};

#endif
