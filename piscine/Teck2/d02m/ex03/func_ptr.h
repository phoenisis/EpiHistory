#ifndef FUNC_PTR_H_
# define FUNC_PTR_H_

#include "func_ptr_enum.h"

typedef struct  tab_func_ptr
{
  t_action     	action;
  void		(*func_pointer)(char *str);
}               tab_func_ptr;

#endif /* FUNC_PTR_H_ */
