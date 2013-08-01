#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "char.h"
#include "raise.h"
#include "bool.h"

char const	*aff_string_c(Object *self);

typedef struct
{
  Class base;
  char x;
} CharClass;

bool		eq_c(const Object* self, const Object* other)
{
  if (((CharClass*)(self))->x == ((CharClass*)(other))->x)
    return (true);
  return (false);
}

bool		gt_c(const Object* self, const Object* other)
{
  if (((CharClass*)(self))->x > ((CharClass*)(other))->x)
    return (true);
  return (false);
}

bool		lt_c(const Object* self, const Object* other)
{
  if (((CharClass*)(self))->x < ((CharClass*)(other))->x)
    return (true);
  return (false);
}

Object*	       add_c(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Char, ((CharClass*)(self))->x + ((CharClass*)(other))->x);
   
  return (me);
}

Object*	       sub_c(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Char, ((CharClass*)(self))->x - ((CharClass*)(other))->x);
   
  return (me);
}

Object*	       mul_c(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Char, ((CharClass*)(self))->x * ((CharClass*)(other))->x);
   
  return (me);
}

Object*	       div_c(const Object* self, const Object* other)
{
  Object	*me;
 
  me = new(Char, ((CharClass*)(self))->x / ((CharClass*)(other))->x);
   
  return (me);
}

static void Char_dtor(Object* self)
{
  if (self != NULL)
    free(self);
  self = NULL;
}

static void Char_ctor(Object* self, va_list * args)
{
  CharClass	*init;

  if ((init = malloc(sizeof(CharClass))) == NULL)
    raise("malloc as fail");
  init = (CharClass*)self;
  ((Class*)self)->__init__ = &Char_ctor;
  ((Class*)self)->__del__ = &Char_dtor;
  ((Class*)self)->__str__ = &aff_string_c;
  ((Class*)self)->__add__ = &add_c;
  ((Class*)self)->__sub__ = &sub_c;
  ((Class*)self)->__mul__ = &mul_c;
  ((Class*)self)->__div__ = &div_c;
  ((Class*)self)->__eq__ = &eq_c;
  ((Class*)self)->__gt__ = &gt_c;
  ((Class*)self)->__lt__ = &lt_c;
  self = &init;
  init->x = va_arg(*args, int);
}

char const	*aff_string_c(Object *self)
{
  char		*str;

  if ((str = malloc((1 + (strlen(((CharClass*)(self))->base.__name__) + 7)) * sizeof(char) + 1)) == NULL)
    raise("malloc as fail");
  sprintf(str,"<%s (%d)>", ((CharClass*)(self))->base.__name__, ((CharClass*)(self))->x);
  return (str);
}

static CharClass _description = {
  { sizeof(CharClass), "Char", &Char_ctor, &Char_dtor, &aff_string_c, &add_c, &sub_c, &mul_c, &div_c, &eq_c, &gt_c, &lt_c},
  0
};

Class* Char = (Class*) &_description;
