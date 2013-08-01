#ifndef		__IBONUS_HH__
# define	__IBONUS_HH__

#include "AObject.hh"
#include "bomberlib.hh"
#include "Map.hh"

class	IBonus : public AObject
{
public :
  void	initialize(void);
  void	update(gdl::GameClock const &, gdl::Input &);
  void  draw(void);
  void	draw_object(Vector3f *position);

  void  remove(float x, float y);
  
protected :
  gdl::Image	texture_;
  Map		*map;
};

#endif
