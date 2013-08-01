/*
** main.c for main in /u/all/pidoux_q/cu/rendu/math/104systeme
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Dec 21 10:01:21 2009 quentin pidoux
** Last update Wed Dec 30 13:59:25 2009 quentin pidoux
*/

int		main(int argc, char **argv)
{
  if (argc < 3)
    {
      printf("Usage: ./104systemes and requiered arguments.\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      if (argv[1][0] == '1')
	option1(argv);
      if (argv[1][0] == '2')
	option2(argv);
      if (argv[1][0] == '3')
	option3(argv);
      if (argv[1][0] == '4')
	option4(argv);
    }
  return (0);
}
