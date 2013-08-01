#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "int.h"
#include "raise.h"

char const	*aff_string_i(Object *self);

typedef struct
{
  Class base;
  int x;
} IntClass;

bool		eq_i(const Object* self, const Object* other)
{
  if (((IntClass*)(self))->x == ((IntClass*)(other))->x)
    return (true);
  return (false);
}

bool		gt_i(const Object* self, const Object* other)
{
  if (((IntClass*)(self))->x > ((IntClass*)(other))->x)
    return (true);
  return (false);
}

bool		lt_i(const Object* self, const Object* other)
{
  if (((IntClass*)(self))->x < ((IntClass*)(other))->x)
    return (true);
  return (false);
}

Object*	       add_i(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Int, ((IntClass*)(self))->x + ((IntClass*)(other))->x);
   
  return (me);
}

Object*	       sub_i(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Int, ((IntClass*)(self))->x - ((IntClass*)(other))->x);
   
  return (me);
}

Object*	       mul_i(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Int, ((IntClass*)(self))->x * ((IntClass*)(other))->x);
   
  return (me);
}

Object*	       div_i(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Int, ((IntClass*)(self))->x / ((IntClass*)(other))->x);
   
  return (me);
}

static void Int_dtor(Object* self)
{
  if (self != NULL)
    free(self);
  self = NULL;
}

static void Int_ctor(Object* self, va_list * args)
{
  IntClass	*init;

  if ((init = malloc(sizeof(IntClass))) == NULL)
    raise("malloc as fail");
  init = (IntClass*)self;
  ((Class*)self)->__init__ = &Int_ctor;
  ((Class*)self)->__del__ = &Int_dtor;
  ((Class*)self)->__str__ = &aff_string_i;
  ((Class*)self)->__add__ = &add_i;
  ((Class*)self)->__sub__ = &sub_i;
  ((Class*)self)->__mul__ = &mul_i;
  ((Class*)self)->__div__ = &div_i;
  ((Class*)self)->__div__ = &div_i;
  ((Class*)self)->__eq__ = &eq_i;
  ((Class*)self)->__gt__ = &gt_i;
  ((Class*)self)->__lt__ = &lt_i;
  self = &init;
  init->x = va_arg(*args, int);
}

char const	*aff_string_i(Object *self)
{
  char		*str;
  int		i = 2;
  int		nb;

  nb = ((IntClass*)(self))->x;
  while (nb / 10 != 0)
    {
      nb /= 10;
      i++;
    }
  if ((str = malloc((sizeof(int) * i) + ((strlen(((IntClass*)(self))->base.__name__) + 7) * sizeof(char)) + 1)) == NULL)
    raise("malloc as fail");
  i += strlen(((IntClass*)(self))->base.__name__) + 10;
  snprintf(str, i ,"<%s (%d)>", ((IntClass*)(self))->base.__name__, ((IntClass*)(self))->x);
  return (str);
}

static IntClass _description = {
  { sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, &aff_string_i, &add_i, &sub_i, &mul_i, &div_i, &eq_i, &gt_i, &lt_i},
  0
};

Class* Int = (Class*) &_description;
