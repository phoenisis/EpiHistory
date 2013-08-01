/*
** board.h for  in /home/pidoux_q/epikong/etape_2
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:03:26 2012 quentin pidoux
** Last update Sat Mar  3 14:03:29 2012 quentin pidoux
*/

#ifndef		__BOARD_T__
# define	__BOARD_T__

# include		<SDL/SDL.h>
# include		<unistd.h>
# include		<SDL/SDL_image.h>
# include		<sys/mman.h>
# include		<fcntl.h>
# include		<stdio.h>

# include		"xSDL_func.h"
# include		"xfunction.h"

# define	PRINT_ERROR	perror("Epikong Error")
# define	READ_ONLY	O_RDONLY
# define	FAILURE_VALUE	0

typedef enum
  {
    Up,
    Down,
    Left,
    Right,
    Walk,
    Jump,
    Fall = Jump,
    Climb = Jump,
    Standing
  } eWay;

typedef enum
  {
    Human,
    Monst,
    Boss
  } eMode;

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
    Life = 'l',
    Key = 'k'
  };

typedef enum
  {
    QUIT,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    JUMP,
    ELSE
  } eKey;

typedef struct s_perso
{
  eWay		way;
  int		x;
  int		y;
  int		ix;
  int		iy;
  int		nb_life;
  eKey		dir;
  eMode		type;
  SDL_Surface*	img[3][2];
  struct s_perso *next;
}		t_perso;

typedef		struct
{
  char		*map;
  int		size;
  int		h;
  int		numb_monster;
  t_perso	*mobs;
  t_perso	player;
  SDL_Surface	*ecran;
}		t_board;



void		gere_errors(int num);
int		handle_key();
char		*getlevel();
t_perso		*create_mobs(t_board *board);
void		aff_obj(char c, SDL_Rect position, SDL_Surface *ecran);
void		move_mob(t_perso *mob, t_board *map);
void		move_monsters(t_board *board);
void		play_the_game(t_board *board);
void		move(t_board *board, t_perso *pl, eKey dir);
void		init_player(int *ix, int *iy, t_board *map);
void		create_player(t_perso* pl);
void		aff_board(t_board *board, SDL_Surface *ecran);
void		aff_player(t_board* board, t_perso* pl, int x, int y);

#endif
