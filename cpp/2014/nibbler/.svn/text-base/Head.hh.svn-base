//
// Head.hh for Head for Snake in /home/hubert_s//nibbler-2014-pidoux_q
// 
// Made by sevan hubert
// Login   <hubert_s@epitech.net>
// 
// Started on  Mon Mar  7 13:17:49 2011 sevan hubert
// Last update Sat Mar 19 12:14:27 2011 sevan hubert
//

#ifndef		__HEAD__
# define	__HEAD__

#include "Snake.hh"
#include "Map.hh"

#define	LEFT	2
#define UP	1
#define RIGHT	3
#define DOWN	0

class	Head : public Snake
{
public : 
  Head(Map const &m);
  ~Head();

  void	setDir(int dir);
  bool	has_snap();
  bool	is_out(Map const &M);
  void	move();
  void	grown_up(Map const &M);
  int	get_score() const;
  int	get_apple_eat() const;
  int	get_highscore() const;
  void	set_highscore(int n);
  void	init_highscore();
  void  save_highscore();
  
private :
  int	direction;
  int	score;
  int	apple_eat;
  int	highscore;
};

#endif
