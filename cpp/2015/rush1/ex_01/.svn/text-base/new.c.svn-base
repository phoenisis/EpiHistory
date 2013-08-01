#include <stdlib.h>

#include "point.h"
#include "new.h"
#include "raise.h"
#include "object.h"

void* new(Class* class)
{
  Class		*new;
  if ((new = malloc(class->__size__)) == NULL)
    raise("malloc as fail\n");
  class->__init__(new);
  new->__name__ = class->__name__;
  new->__del__ = class->__del__;
  new->__init__ = class->__init__;
  return (new);
}

void delete(Object* ptr)
{
  if (ptr != NULL)
    {
      ((Class*)ptr)->__del__(ptr);
      free(ptr);
    }
}
