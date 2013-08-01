/*
** bsq.c for bsq test in /u/all/pidoux_q/cu/rendu/c/bsq
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Thu Nov 12 13:04:05 2009 quentin pidoux
** Last update Fri Nov 13 11:43:07 2009 quentin pidoux
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int             point = 0;
int             rond = 0;
int             line = 1;
int             col = 0;
char            tab[100][100];
int             ab = 0;
int             ord = 0;

void            my_putchar(char c)
{
  write(1, &c, 1);
}

int             lecture()
{
  char          c;
  int           fd;

  fd =  open("example", O_RDWR);
  while ((read(fd, &c, 1) > 0))
    {
      my_putchar(c);
      if (c == '.')
          point = point + 1;
      if (c == 'o')
          rond = rond + 1;
      if (c == '\n' || c == '\0')
        {
          col = 0;
          line = line + 1;
        }
      if (c != '\n')
	col = col + 1;
      tab[ab][ord] = c;
      ab = ab + 1;
      if(ab == 17)
        {
          ord = ord + 1;
          ab = 0;
	}
    }
  close(fd);
  return (0);
}

int             main(int ac, char **av)
{
  lecture();
  if(rond == 0)
    {
      printf("\n\n***invalid map***\n");
    }
  else
    {
      printf("\n\nnombre de points = %ld\nnombre de ronds = %ld\n", point, rond);
      printf("\nnombre de lignes = %ld\nnombre de colonnes = %ld\n\n", line, col);

      printf("xxxxxxxxxxxxx\n\n");
      ab = 0;
      ord = 0;
      while(ab <= 17 && ord != '\0')
        {
          printf("%c", tab[ab][ord]);
          ab = ab + 1;
          if(ab == 17)
            {
              ab = 0;
              ord = ord + 1;
            }
        }
      printf("fin\n\n");
    }
}
