/*
** mem_ptr.c for mem_ptr in /home/pidoux_q//rendu/cpp/d02/ex_1
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Jan  5 11:11:04 2011 quentin pidoux
** Last update Wed Jan  5 15:14:47 2011 quentin pidoux
*/

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
