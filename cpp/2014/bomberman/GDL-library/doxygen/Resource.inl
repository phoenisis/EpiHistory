/*
** Chabal !!!!!
**
*/

#ifndef __RESOURCE_INL__
#define __RESOURCE_INL__

#include <iostream>
#include "Resource.hpp"

template <typename Type>
gdl::Resource<Type>::Resource(Type* val)
: gdl::ResourceBase(), data_(val)
{
}

template <typename Type>
gdl::Resource<Type>::Resource(gdl::Resource<Type> const & right)
: ResourceBase(right), data_(right.data_)
{
}

template <typename Type>
gdl::Resource<Type>::~Resource()
{
  this->check_destroy();
}

template <typename Type>
gdl::Resource<Type>& gdl::Resource<Type>::operator=(gdl::Resource<Type> const & right)
{
  this->gdl::ResourceBase::operator=(right);
  this->data_ = right.data_;
  return *this;
}

template <typename Type>
Type* gdl::Resource<Type>::operator->()
{
  return this->data_;
}

template <typename Type>
Type& gdl::Resource<Type>::operator*()
{
  return *this->data_;
}

template <typename Type>
bool gdl::Resource<Type>::isValid() const
{
  return this->data_ != NULL;
}

template <typename Type>
void gdl::Resource<Type>::destroy()
{
  if (this->data_ != NULL)
    delete this->data_;
  this->data_ = NULL;
}

template <typename Type>
void gdl::Resource<Type>::HardReset()
{
  this->destroy();
}

#endif /* __RESOURCE_INL__ */
