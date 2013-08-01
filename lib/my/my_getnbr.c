/*
** my_getnbr.c for  in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:36:04 2010 quentin pidoux
** Last update Wed Oct 13 21:36:11 2010 quentin pidoux
*/


int             my_getnbr(char *str)
{
  int           nbr;

  nbr = 0;
  while (*str != '\0')
    {
      nbr = nbr * 10;
      nbr = nbr + (*str - '0');
      str = str + 1;
    }
  return (nbr);
}
