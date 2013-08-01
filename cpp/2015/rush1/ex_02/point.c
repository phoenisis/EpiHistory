#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point.h"
#include "raise.h"

//static void	Point_dtor(Object* self);
char const	*aff_string_P(Object *self);

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_dtor(Object* self)
{
  if (self)
    free(self);
  self = NULL;
}

static void Point_ctor(Object* self, va_list * args)
{
  PointClass	*init;

  if ((init = malloc(sizeof(PointClass))) == NULL)
    raise("malloc as fail");
  init = (PointClass*)self;
  ((Class*)self)->__init__ = &Point_ctor;
  ((Class*)self)->__del__ = &Point_dtor;
  ((Class*)self)->__str__ = &aff_string_P;
  self = &init;
  init->x = va_arg(*args, int);
  init->y = va_arg(*args, int);
}

char const	*aff_string_P(Object *self)
{
  char		*str;
  int		i = 2;
  int		nb;

  nb = ((PointClass*)(self))->x;
  while (nb / 10 != 0)
    {
      nb /= 10;
      i++;
    }
  nb = ((PointClass*)(self))->y;
  while (nb / 10 != 0)
    {
      nb /= 10;
      i++;
    }
  if ((str = malloc((sizeof(int) * i) + ((strlen(((PointClass*)(self))->base.__name__) + 7) * sizeof(char)) + 1)) == NULL)
    raise("malloc as fail");
  i += strlen(((PointClass*)(self))->base.__name__) + 10;
  snprintf(str, i ,"<%s (%d, %d)>", ((PointClass*)(self))->base.__name__, ((PointClass*)(self))->x, ((PointClass*)(self))->y);
  return (str);
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &aff_string_P},
  0, 0
};

Class* Point = (Class*) &_description;
