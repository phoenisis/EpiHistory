/*
** my_put_nbr.c for my_put_nbr in /u/all/pidoux_q/cu/rendu/c/minitalk
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Mar  9 14:27:03 2010 quentin pidoux
** Last update Tue Mar  9 14:27:05 2010 quentin pidoux
*/

int             my_put_nbr(int nbre)
{
 if (nbre < 0)
  {
    my_putchar('-');
    if(nbre / 10 != 0)
      {
        my_put_nbr(nbre / -10);
      }
    my_putchar(-(nbre % 10) + 48);
  }
 else
  {
    if (nbre / 10 != 0)
      {
        my_put_nbr(nbre / 10);
      }
    my_putchar(nbre % 10 + 48);
  }
}
