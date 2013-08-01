/*
** colle2-1.c for colle 2-1 in /u/all/pidoux_q/cu/rendu/piscine/colles/Semaine_02
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sun Oct 18 11:06:34 2009 quentin pidoux
** Last update Mon Oct 11 14:42:50 2010 quentin pidoux
*/

#include <unistd.h>

char    *initialisation(char *str2, char *str1, char b)
{
  int   i;

  i = 0;
  while (str1[i] != '\0')
    {
      if (str2[i] != str1[i])
        {
	  str2[i] = b;
        }
      i = i + 1;
    }
  return (str2);
}

int             my_text_gare(char *str1, int speed)
{
  int           a;
  char          b;
  char          *str2;

  b = 32;
  str2 = malloc(sizeof(str1) * strlen(str1) + 1);
  initialisation(str2, str1, b);
  while (b < 127)
    {
      usleep(speed);
      putstr(str2);
      initialisation(str2, str1, b);
      putchar('\r');
      b = b + 1;
    }
  free(str2);
  putchar('\n');
  return (0);
}
int             main(int argc, char **argv)
{
  if (argc == 2)
    {
      my_text_gare(argv[1], 5000);
    }
  if (argc == 3)
    {
      my_text_gare(argv[1], getnbr(argv[2]));
    }
  else
    {
      putstr("errors\n");
    }
  return (0);
}
