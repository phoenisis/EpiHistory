/*
** my_isneg.c for isneg in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:37:33 2010 quentin pidoux
** Last update Wed Oct 13 21:37:36 2010 quentin pidoux
*/

int		my_isneg(int nb)
{ 
  if (nb >= 0) 
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
}
