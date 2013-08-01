/*
** my_strlowcase.c for lowcase in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:48:37 2010 quentin pidoux
** Last update Wed Oct 13 21:48:39 2010 quentin pidoux
*/

char		*my_strupcase(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  str[i] = str[i] + 32;
	  i++;
	}
      else
	{
	  str[i] = str[i] + 32;
	  i++;
	}
    }
  return (*str);
}

