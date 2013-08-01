/*
** get_map.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:28:59 2012 quentin pidoux
** Last update Sat Mar  3 14:28:59 2012 quentin pidoux
*/

#include	<sys/mman.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"board.h"

static void	is_carac(char c, int *ent, int *ex, int *k)
{
  if (c == Entry)
    {
      if (*ent == 0)
	*ent = 1;
      else
	gere_errors(4);
    }
  if (c == Exit)
    {
      if (*ex == 0)
	*ex = 1;
      else
	gere_errors(5);
    }
  if (c == Key)
    {
      if (*k == 0)
	*k = 1;
      else
	gere_errors(6);
    }
}

static int	openfile(char *filename)
{
  int		fd;

  fd = open(filename, O_RDWR);
  if (fd < FAILURE_VALUE)
    {
      PRINT_ERROR;
      exit(EXIT_FAILURE);
    }
  return (fd);
}

static void	check_elem(t_board *board, int *is_entry, int *is_exit, int *is_key)
{
  int		i;
  int		h;
  int		size;
  int		len;

  len = 0;
  h = 0;
  i = 0;
  while (board->map && board->map[i])
    {
      size = len;
      while (board->map[i] && board->map[i] != endLine)
	{
	  is_carac(board->map[i++], is_entry, is_exit, is_key);
	  (len == 0) ? (size++) : (size--);
	}
      if (size != 0 && len)
	gere_errors(1);
      if (!len)
	len = size;
      i++;
      h++;
    }
  board->size = len;
  board->h = h;
}


static void	check_map(t_board *board)
{
  int		is_entry;
  int		is_exit;
  int		is_key;

  is_entry = 0;
  is_exit = 0;
  is_key = 0;
  check_elem(board, &is_entry, &is_exit, &is_key);
  if (!is_entry)
    gere_errors(2);
  if (!is_exit)
    gere_errors(3);
  if (!is_key)
    gere_errors(7);
}

void		get_map(t_board *board, char  *filename)
{
  int		fd;
  void		*file_map;
  off_t		r_lseek;

  fd = openfile(filename);
  r_lseek = lseek(fd, 0, SEEK_END);
  if (r_lseek == -1)
    {
      PRINT_ERROR;
      exit(EXIT_FAILURE);
    }
  file_map = mmap(NULL,r_lseek, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (file_map == (void *)-1)
    {
      PRINT_ERROR;
      exit(EXIT_FAILURE);
    }
  board->map = (char *)file_map;
  check_map(board);
}
