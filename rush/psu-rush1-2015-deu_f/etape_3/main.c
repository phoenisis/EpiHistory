/*
** main.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:29:36 2012 quentin pidoux
** Last update Sat Mar  3 14:29:36 2012 quentin pidoux
*/

#include		"board.h"
#include		"get_map.h"

void			gere_errors(int num)
{
  if (num == 1)
    xfprintf(stderr,"Epikong-error : Size map are not good\n");
  else if (num == 2)
    xfprintf(stderr,"Epikong-error : Where are the entry ?\n");
  else if (num == 3)
    xfprintf(stderr,"Epikong-error : Where are the exit ?\n");
  else if (num == 4)
    xfprintf(stderr,"Epikong-error : Too many Entries !\n");
  else if (num == 5)
    xfprintf(stderr,"Epikong-error : Too many exits !\n");
  else if (num == 6)
    xfprintf(stderr,"Epikong-error : Too many keys !\n");
  else if (num == 7)
    xfprintf(stderr,"Epikong-error : Where is the key ? !\n");
  exit(EXIT_FAILURE);
}



int			main()
{
  int level;

  level = 0;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      write(2, "SDL_INIT Error\n", 15);
      exit(EXIT_FAILURE);
    }
  while ((level = epikong(level)) && level != -1);
  if (level == -1)
    aff_victory();
  return (0);
}
