#ifndef		__BLOCS_HH__
# define	__BLOCS_HH__

#include "Object.hh"
#include "Vector3f.hh"

namespace Bonus
{
  class Flamme;
  class Bombe;
}

namespace Bloc
{
  class	Breakable : public Object::Cube
  {
  public :
    Breakable();
    void	draw();
    void	draw_object(Vector3f *position);
    void	initialize(void);
    void	remove(float x, float y);
    void	SetBonus(Bonus::Flamme *flamme, Bonus::Bombe *bombe);

    Bonus::Bombe  *getBonus_b() const;
    Bonus::Flamme *getBonus_f() const;
    
  private :
    Bonus::Flamme *flamme;
    Bonus::Bombe  *bombe;
  };
  
  class	Unbreakable : public Object::Cube
  {
  public :
    Unbreakable();
    void	draw();
    void	draw_object(Vector3f *position);
    void	initialize(void);    
  };
  
}
#endif 
