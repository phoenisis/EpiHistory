#ifndef MenuCamera_hh_
# define MenuCamera_hh_

# include "Vector3f.hh"
# include "GameClock.hpp"
# include "Input.hpp"

class MenuCamera
{
 public:
  MenuCamera();
  ~MenuCamera();
  void initialize();
  void update(gdl::GameClock const &, gdl::Input &);
  void setpos(float, float, float);
  void setrot(float, float, float);

 private:
  Vector3f position_;
  Vector3f rotation_;
};

#endif
