/*
** pyramid.c for pyramide in /home/pidoux_q//rendu/cpp/d01/ex_1
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Jan  4 16:00:55 2011 quentin pidoux
** Last update Wed Jan  5 01:25:01 2011 quentin pidoux
*/

int		len;

int		comb(int size, int **map, int step, int col, int stock)
{
  if (size == 0)
    {
      if (stock < len)
	len = stock;
      return (0);
    }
  stock += map[step][col];
  step++;
  comb(size - 1, map, step, col, stock);
  return (comb(size - 1, map, step, col + 1, stock));
}

int		pyramid_path(int size, int **map)
{
  int	step = 0;
  int	col = 0;
  int	stock = 0;

  len = 999999; 
  comb(size, map, step, col, stock);
  return (len);
}
