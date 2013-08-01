#ifndef		__BONUS_HH__
# define	__BONUS_HH__

#include "IBonus.hh"
#include "Map.hh"
#include "Vector3f.hh"

namespace Bonus
{
  class	Bombe : public IBonus
  {
  public :
    Bombe(Map *map);
    void initialize(void);
    void add_positions(Vector3f *position, float rotation);
  };
  
  class	Flamme : public IBonus
  {
  public :
    Flamme(Map *map);
    void initialize(void);
    void add_positions(Vector3f *position, float rotation);
  };
}

#endif
