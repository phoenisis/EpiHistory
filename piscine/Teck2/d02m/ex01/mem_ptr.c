#include "mem_ptr.h"
#include <stdlib.h>
#include <string.h>

void         add_str(char *str1, char *str2, char **res)
{
  char *str;
  str = malloc(sizeof (str1)* sizeof (str2));
  str = strcat(str, str1);
  str = strcat(str, str2);

  *res = str;
}

void         add_str_struct(t_str_op *str_op)
{
  char *str;
  str = malloc(sizeof (str_op->str1)* sizeof (str_op->str2));
  str = strcat(str, str_op->str1);
  str = strcat(str, str_op->str2);

  str_op->res = str;
}
