/*
** first.c for main in /u/all/pidoux_q/cu/rendu/c/proj/bistromatique
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Thu Oct 29 14:24:41 2009 quentin pidoux
** Last update Thu Oct 29 18:14:32 2009 quentin pidoux
*/

static voidcheck_base(char *base);
static voidcheck_ops(char *ops);
static char*get_expr(unsigned size);

int		main(int ac,char **av)
{
  char*expr;
  unsigned intsize;

  if (ac != 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops\"()+-*/%\" exp_len\n");
      exit(1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  expr = get_expr(size = atoi(av[3]));
  my_putstr(eval_expr(av[1],av[2],expr,size));
}
