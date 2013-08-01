/*
** makeMap.c for Epikong in /afs/epitech.net/users/all/pidoux_q/public/epikong
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 12:09:52 2011 sevan hubert
** Last update Sat Mar 26 19:54:28 2011 sevan hubert
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "epikong.h"

char	setChar(char c, int x, s_heros *heros, s_map *map)
{
  char	s1[8] = {'.', 'k', 'o', 's', 'm', 'i', 'w', 0};
  int	i;

  i = 0;
  while (s1[i] && s1[i] != c)
    i++;
  if (s1[i] == 'i')
    {
      heros->caseX = posX(map, x);
      heros->caseY = posY(map, x);
      return ('0');
    }
  else if (!s1[i])
    return ('0');
  return (i + '0');
}

void	setMap(char const *file, s_map *m, s_heros *heros)
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
	m->map[i++] = setChar(str[j++], i, heros, m);
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
  if (m->sizeX < strlen(str))
    m->sizeX = strlen(str);
  while (str)
    {
      free(str);
      if (m->sizeX < strlen(str))
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

s_map	*makeMap(char const *file, s_heros *heros)
{
  s_map	*map;

  map = xmalloc(sizeof(s_map));
  setSizeX(file, map);
  setSizeY(file, map);
  setMap(file, map, heros);
  return (map);
}
