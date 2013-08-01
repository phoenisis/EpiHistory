//
// Map.hh for Map in /home/hubert_s//nibbler-2014-pidoux_q
// 
// Made by sevan hubert
// Login   <hubert_s@epitech.net>
// 
// Started on  Mon Mar  7 13:32:14 2011 sevan hubert
// Last update Wed Mar  9 17:30:00 2011 sevan hubert
//

#ifndef		__MAP__
# define	__MAP__

#include "Snake.hh"


class	Map
{
public :
  Map();
  Map(int x, int y);
  ~Map();

  int	getSizeX() const;
  int	getSizeY() const;
  bool	case_is_free(int x, int y, Snake &hd) const;

private :
  int	x;
  int	y;
};

#endif
