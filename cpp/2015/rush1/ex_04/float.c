#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "float.h"
#include "raise.h"
#include "bool.h"

char const	*aff_string_f(Object *self);

typedef struct
{
  Class base;
  float x;
} FloatClass;

bool		eq_f(const Object* self, const Object* other)
{
  if (((FloatClass*)(self))->x == ((FloatClass*)(other))->x)
    return (true);
  return (false);
}

bool		gt_f(const Object* self, const Object* other)
{
  if (((FloatClass*)(self))->x > ((FloatClass*)(other))->x)
    return (true);
  return (false);
}

bool		lt_f(const Object* self, const Object* other)
{
  if (((FloatClass*)(self))->x < ((FloatClass*)(other))->x)
    return (true);
  return (false);
}

Object*	       add_f(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Float, ((FloatClass*)(self))->x + ((FloatClass*)(other))->x);
   
  return (me);
}

Object*	       sub_f(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Float, ((FloatClass*)(self))->x - ((FloatClass*)(other))->x);
   
  return (me);
}

Object*	       mul_f(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Float, ((FloatClass*)(self))->x * ((FloatClass*)(other))->x);
   
  return (me);
}

Object*	       div_f(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Float, ((FloatClass*)(self))->x / ((FloatClass*)(other))->x);
   
  return (me);
}

static void Float_dtor(Object* self)
{
  if (self != NULL)
    free(self);
  self = NULL;
}

static void Float_ctor(Object* self, va_list * args)
{
  FloatClass	*init;

  if ((init = malloc(sizeof(FloatClass))) == NULL)
    raise("malloc as fail");
  init = (FloatClass*)self;
  ((Class*)self)->__init__ = &Float_ctor;
  ((Class*)self)->__del__ = &Float_dtor;
  ((Class*)self)->__str__ = &aff_string_f;
  ((Class*)self)->__add__ = &add_f;
  ((Class*)self)->__sub__ = &sub_f;
  ((Class*)self)->__mul__ = &mul_f;
  ((Class*)self)->__div__ = &div_f;
  ((Class*)self)->__eq__ = &eq_f;
  ((Class*)self)->__gt__ = &gt_f;
  ((Class*)self)->__lt__ = &lt_f;
  self = &init;
  init->x = va_arg(*args, double);
}

char const	*aff_string_f(Object *self)
{
  char		*str;
  int		i = 20;

  if ((str = malloc((i + (strlen(((FloatClass*)(self))->base.__name__) + 7)) * sizeof(char) + 1)) == NULL)
    raise("malloc as fail");
  i += strlen(((FloatClass*)(self))->base.__name__) + 10;
  sprintf(str,"<%s (%f)>", ((FloatClass*)(self))->base.__name__, ((FloatClass*)(self))->x);
  return (str);
}

static FloatClass _description = {
  { sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, &aff_string_f, &add_f, &sub_f, &mul_f, &div_f, &eq_f, &gt_f, &lt_f},
  0
};

Class* Float = (Class*) &_description;
