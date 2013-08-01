/*
** makeMap.c for Epikong in /afs/epitech.net/users/all/pidoux_q/public/epikong
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 12:09:52 2011 sevan hubert
** Last update Sun Mar 27 23:20:51 2011 sevan hubert
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "epikong.h"

char	setChar(char c)
{
  char	s1[8] = {'.', 'k', 'o', 's', 'm', 'i', 'w', 0};
  int	i;

  i = 0;
  while (s1[i] && s1[i] != c)
      i++;
  if (s1[i] == 0)
    return ('0');
  return (i + '0');
}

void	setMap(char const *file, s_map *m)
{
  int	fd;
  char	*str;
  int	i;
  int	j;

  fd = open(file, O_RDONLY);
  m->map = xmalloc((m->sizeX * m->sizeY + 1) * sizeof(char));
  i = 0;
  j = 0;
  while (i < m->sizeX * m->sizeY)
    {
      str = get_next_line(fd);
      while (str[j])
	m->map[i++] = setChar(str[j++]);
      while (j < m->sizeX)
	{
	  m->map[i++] = '0';
	  j++;
	}
      j = 0;
      free(str);
    }
  m->map[i] = '\0';
  close(fd);
}

void	setSizeX(char const *file, s_map *m)
{
  int	fd;
  char	*str;

  fd = open(file, O_RDONLY);
  str = get_next_line(fd);
  m->sizeX = 0;
  if (m->sizeX < (int)strlen(str))
    m->sizeX = strlen(str);
  while (str)
    {
      free(str);
      if (m->sizeX < (int)strlen(str))
	m->sizeX = strlen(str);
      str = get_next_line(fd);
    }
  str = get_next_line(fd);
  get_next_line(0);
  free(str);
  close(fd);
}

void	setSizeY(char const *file, s_map *m)
{
  int	fd;
  char	*str;

  fd = open(file, O_RDONLY);
  m->sizeY = 0;
  str = get_next_line(fd);
  while (str)
    {
      free(str);
      str = get_next_line(fd);
      m->sizeY += 1;
    }
  get_next_line(0);
  m->sizeY -= 1;
  free(str);
  close(fd);
}

s_map	*makeMap(char const *file)
{
  s_map	*map;

  map = xmalloc(sizeof(s_map));
  setSizeX(file, map);
  setSizeY(file, map);
  setMap(file, map);
  return (map);
}
