/*
** my_putnbr.c for my_put_nbr in /u/all/ricard_v/cu/rendu/piscine/Jour_03
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Mon Oct 12 14:26:33 2009 vincent ricard
** Last update Sat Nov 28 19:31:10 2009 vincent ricard
*/

int		my_put_nbr(int nbre)
{
  if (nbre < 0)
    {
      my_putchar('-');
      nbre = nbre * -1;
    }
  else
    {
      if (nbre / 10 != 0)
        {
          my_put_nbr(nbre / 10);
        }
      my_putchar(nbre % 10 + '0');
    }
}

