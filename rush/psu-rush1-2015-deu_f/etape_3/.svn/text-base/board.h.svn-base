/*
** board.h for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:28:22 2012 quentin pidoux
** Last update Sat Mar  3 14:28:23 2012 quentin pidoux
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
    NearDoor,
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
  int		exx;
  int		exy;
  int		nb_life;
  int		gotkey;
  eKey		dir;
  eMode		type;
  int		nb_fall;
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
int		play_the_game(t_board *board);
void		move(t_board *board, t_perso *pl, eKey dir);
void		init_player(int *ix, int *iy, t_board *map);
void		create_player(t_perso* pl);
void		aff_board(t_board *board, SDL_Surface *ecran);
void		aff_player(t_board* board, t_perso* pl, int x, int y);
int		epikong();
void		aff_life(t_board *board, SDL_Surface *ecran);
void		dec_life(t_board *board);
void		get_map(t_board *board, char *filename);


void		check_player(t_perso *mob, t_board *map, SDL_Rect pos);
void		move_monsters(t_board *board);
int		moveleft(t_perso *mob, t_board *map, SDL_Rect pos);
int		checkwall(t_perso mob, t_board *map, int x);
int		checkempty(t_perso mob, t_board *map, int x);
void		aff_victory();

#endif
