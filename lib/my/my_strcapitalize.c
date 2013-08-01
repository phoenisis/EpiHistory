/*
** my_strcapitalize.c for capitalize in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:45:23 2010 quentin pidoux
** Last update Wed Oct 13 21:45:24 2010 quentin pidoux
*/

char		*my_cap(char *str, int a)
{
  while (str[a] != 0)
    {
      if (str[a] == ' ')
	{
	  a++;
	  if (str[a] == 0)
	    return (0);
	  if (str[a] > 96 && str[a] < 123)
	    {
	      str[a] = str[a] - 32;
	      a++;
	    }
	}
      else
	{
	  a++;
	}
    }
  return (str);
}

char		*my_strcapitalize(char *str)
{
  int		a = 0;

  if (str[a] >= 'a' && str[a] <= 'z')
    {
      str[a] = str[a] - 32;
      a++;
    }
 if (str[a] <= 'a' && str[a] >= 'z')
   {
     a++;
   }
 my_cap(str, a);
}
