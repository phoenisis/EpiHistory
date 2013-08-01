//
// snake.hh for snake in /home/hubert_s//nibbler-2014-pidoux_q
// 
// Made by sevan hubert
// Login   <hubert_s@epitech.net>
// 
// Started on  Mon Mar  7 12:52:01 2011 sevan hubert
// Last update Tue Mar  8 17:56:32 2011 sevan hubert
//

#ifndef		__SNAKE__
# define	__SNAKE__

class	Snake
{
protected :
  Snake(int x, int y);
  ~Snake();

public :
  Snake(int x, int y, int len);
  int	getLength() const;
  int	getPosX() const;
  int	getPosY() const;
  Snake *getNext() const;

  void	setPosX(int x);
  void	setPosY(int y);
  void	setNext(Snake *tail);
  void	move_tail(int x, int y);

protected :
  int	length;
  int	posx;
  int	posy;
  Snake *next;
};	

#endif
