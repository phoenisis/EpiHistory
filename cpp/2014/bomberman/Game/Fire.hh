#ifndef		__FIRE_HH__
# define	__FIRE_HH__

#include "bomberlib.hh"
#include "AObject.hh"

class MyGame;

namespace Model
{
  class	Fire : public AObject
  {
  public :
    Fire(MyGame *game);
    ~Fire();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
    void draw_object(Vector3f *position);

  protected :
    MyGame	*game;
    gdl::Model	model_;
  };
}
#endif
