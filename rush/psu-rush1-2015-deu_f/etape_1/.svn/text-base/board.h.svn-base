/*
** board.h for  in /home/pidoux_q/epikong/etape_1
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 13:57:28 2012 quentin pidoux
** Last update Sat Mar  3 13:57:29 2012 quentin pidoux
*/

#ifndef		__BOARD_T__
# define	__BOARD_T__

# define	PRINT_ERROR	perror("Epikong Error")
# define	READ_ONLY	O_RDONLY
# define	FAILURE_VALUE	0

# include	"xfunction.h"
# include	"xSDL_func.h"


typedef		struct
{
  char		*map;
  int		size;
  int		h;
}		t_board;

enum		eType
  {
    Empty = '.',
    Wall = 'w',
    Ladder = 's',
    Entry= 'i',
    Exit = 'o',
    EndMap = '\0',
    endLine = '\n',
    Monster = 'm',
    Key = 'k'
  };

enum		eKey
  {
    QUIT,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ELSE
  };

void		gere_errors(int num);
void		handle_key();

#endif
