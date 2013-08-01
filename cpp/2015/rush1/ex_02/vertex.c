#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point.h"
#include "raise.h"

//static void	Vertex_dtor(Object* self);
char const	*aff_string_V(Object *self);

typedef struct
{
  Class base;
  int x, y, z;
} VertexClass;


static void Vertex_dtor(Object* self)
{
  if (self)
    free(self);
  self = NULL;
}


static void Vertex_ctor(Object* self, va_list * args)
{
  VertexClass	*init;

  if ((init = malloc(sizeof(VertexClass))) == NULL)
    raise("malloc as fail");
  init = (VertexClass*)self;
  ((Class*)self)->__init__ = &Vertex_ctor;
  ((Class*)self)->__del__ = &Vertex_dtor;
  ((Class*)self)->__str__ = &aff_string_V;
  self = &init;
  init->x = va_arg(*args, int);
  init->y = va_arg(*args, int);
  init->z = va_arg(*args, int);
}

char const	*aff_string_V(Object *self)
{
  char		*str;
  int		i = 3;
  int		nb;

  nb = ((VertexClass*)(self))->x;
  while (nb / 10 != 0)
    {
      nb /= 10;
      i++;
    }
  nb = ((VertexClass*)(self))->y;
  while (nb / 10 != 0)
    {
      nb /= 10;
      i++;
    }
  nb = ((VertexClass*)(self))->z;
  while (nb / 10 != 0)
    {
      nb /= 10;
      i++;
    }
  if ((str = malloc((sizeof(int) * i) + ((strlen(((VertexClass*)(self))->base.__name__) + 7) * sizeof(char)) + 1)) == NULL)
    raise("malloc as fail");
  i += strlen(((VertexClass*)(self))->base.__name__) + 13;
  snprintf(str, i, "<%s (%d, %d, %d)>", ((VertexClass*)(self))->base.__name__, ((VertexClass*)(self))->x, ((VertexClass*)(self))->y, ((VertexClass*)(self))->z);
  return (str);
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &aff_string_V},
  0, 0, 0
};

Class* Vertex = (Class*) &_description;
