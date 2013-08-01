/*
** my_swap.c for swap in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:50:43 2010 quentin pidoux
** Last update Wed Oct 13 21:50:45 2010 quentin pidoux
*/

int	my_swap(int *a, int *b)
{
  int	i;
  
  i = *a;
  *a = *b;
  *b = i;
}
