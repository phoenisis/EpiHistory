#ifndef		__BOMB_HH__
#define		__BOMB_HH__

#include "bomberlib.hh"
#include "AObject.hh"
#include "Vector3f.hh"
#include "Map.hh"
#include "Fire.hh"

namespace Model
{
  class	Bomb : public AObject
  {
  public :
    Bomb(Map *map, Fire *fire);
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
    void draw_object(Vector3f *position);
    void explose(int i, std::vector<std::pair<Vector3f*, float> >::iterator it);
    void explose(int x, int y);

    std::vector<std::pair<Vector3f*, float> > getposition_b() const;

  private :
    gdl::Model model_;
    Map	 *map;
    Fire *fire;
  };
}

#define		UP	0
#define		RIGHT	1
#define		DOWN	2
#define		LEFT	3

#endif
