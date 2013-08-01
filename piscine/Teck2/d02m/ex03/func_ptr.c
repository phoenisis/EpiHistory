#include "func_ptr.h"
#include <stdio.h>
#include <string.h>

void print_normal(char *str)
{
  printf("%s\n", str);
}

void print_reverse(char *str)
{
  int i = strlen(str) - 1;

  while(i >= 0)
    {
      printf("%c", str[i]);
      i--;
    }
  printf("\n");
}

void print_upper(char *str)
{
  int i = 0;
  int len = strlen(str);

  while (i != len -1)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  printf("%c", str[i]-32);
	  i++;
	}
      else 
	{
	  printf("%c", str[i]);
	  i++;
	}
    }
  printf("\n");
}

void print_42(char *str)
{
  str = "42";
  printf("%s\n", str);
}

void do_action(t_action action, char *str)
{
  int i = 0;

  tab_func_ptr func_ptr[]=
  {
    {PRINT_NORMAL, &print_normal},
    {PRINT_REVERSE, &print_reverse},
    {PRINT_UPPER, &print_upper},
    {PRINT_42, &print_42},
    {0,0}
  };

  while(i <= 3)
    {
      if (func_ptr[i].action == action)
	func_ptr[i].func_pointer(str);
      ++i;
    }
}

int main(void)
{
  char *str = "J'utilise les pointeurs sur fonctions !";
  do_action(PRINT_NORMAL, str);
  do_action(PRINT_REVERSE, str);
  do_action(PRINT_UPPER, str);
  do_action(PRINT_42, str);
  return (0);
}
