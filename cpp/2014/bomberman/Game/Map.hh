#ifndef		__MAP_HH__
# define	__MAP_HH__

#include "Blocs.hh"

class	Map
{
public :
  Map(Bloc::Breakable *breakable);
  Map(Bloc::Breakable *breakable, int sizeX, int sizeY);
  ~Map();
  
  char	get_bloc(int x, int y) const;
  int	getSizeX() const;
  int	getSizeY() const;

  int	getPosX(int n) const;
  int	getPosY(int n) const;

  int	getNb_blocs() const;
  Bloc::Breakable *getBreakable() const;

  void	set_bloc(int x, int y, char set);
  void	aff_ascii();
  
  Bloc::Breakable *breakables;

private :
  int	sizeX;
  int	sizeY;
  char	*blocs;
  void	generate_map();
};

#endif
