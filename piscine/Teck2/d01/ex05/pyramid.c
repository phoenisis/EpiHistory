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
