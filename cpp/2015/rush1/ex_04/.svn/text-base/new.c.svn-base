#include <stdlib.h>

#include "new.h"
#include "raise.h"

Object* new(Class *class, ...)
{
  va_list	list;
  Class       	*new;

  if(!class)
    raise("class doesn't exist");
  if ((new = malloc(class->__size__)) == NULL)
    raise("malloc as fail");
  new->__name__ = class->__name__;
  new->__del__ = class->__del__;
  new->__init__ = class->__init__;
  va_start(list, class);
  class->__init__(new, &list);
  va_end(list);
  return (new);
}

Object* va_new(Class *class, va_list* ap)
{
  Class		*new;

  if(!class)
    raise("class doesn't exist");
  if ((new = malloc(class->__size__)) == NULL)
    raise("malloc as fail");
  new->__name__ = class->__name__;
  new->__del__ = class->__del__;
  new->__init__ = class->__init__;
  class->__init__(new, ap);
  return (new);
}

void delete(Object *ptr)
{
  if (ptr)
    ((Class*)ptr)->__del__(ptr);
  ptr = NULL;
}
