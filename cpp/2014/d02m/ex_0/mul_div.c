/*
** mul_div.c for mul_div in /home/pidoux_q//rendu/cpp/d02/ex_0
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Jan  5 10:30:40 2011 quentin pidoux
** Last update Wed Jan  5 11:06:07 2011 quentin pidoux
*/

void add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first+second;
  *mul = first*second;
}

void add_mul_2param(int *first, int *second)
{
  int a = *first;
  int b = *second;
  int add;
  int mul;

  add = a+b;
  mul = a*b;

  *first = add;
  *second = mul;
}
