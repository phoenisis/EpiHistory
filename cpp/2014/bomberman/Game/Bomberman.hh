#ifndef		__BOMBERMAN_HH__
# define	__BOMBERMAN_HH__

#include <list>

#include "bomberlib.hh"
#include "AObject.hh"
#include "Map.hh"
#include "Bomb.hh"
#include "Vector3f.hh"

namespace Model
{
  class Bomberman : public AObject
  {
  public :
    Bomberman(Map *map, Model::Bomb *bomb);
    ~Bomberman();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
    void draw_object(Vector3f *position);

    float getposition_x() const;
    float getposition_z() const;
    int getnb_fire() const;
    int getnb_bomb() const;
    std::vector<std::pair<Vector3f*, float> > getBomb() const;

    bool isAlive() const;
    void isKill();

    void CheckBonus();

    virtual void Action(gdl::Input &input);

  protected :
    gdl::Model			model_;
    Map				*map;
    Model::Bomb			*bomb;
    std::vector<int>		posed_bombs;
    Vector3f *position_;
    Vector3f *rotation_;

    bool	alive;
    int		nb_fire;
    int		nb_bomb;

  };
}

#endif
