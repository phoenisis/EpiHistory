#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void StringDestroy(String* this)
{
  if (this)
    free(this);
}

void assign_s(String *this, const String * str)
{
  this->str = strdup(str->str);
}

void assign_c(String*this, const char * s )
{
  this->str = strdup(s);
}

void append_s(String*this, const String * ap)
{
  this->str = realloc(this->str, (strlen(this->str) + strlen(ap->str))+1);
  this->str = strcat(this->str, ap->str);
}

void append_c(String* this, char const * ap)
{
  this->str = realloc(this->str, (strlen(this->str) + strlen(ap))+1);
  this->str = strcat(this->str, ap);
}

char at(String* this, size_t pos)
{
  unsigned int save = strlen(this->str);

  if (pos < save)
    return (this->str[pos]);
  else 
    return (-1);
}

void clear(String* this)
{
  bzero(this->, strlen(this->str));
}

size_t Size(String* this)
{
  if (this->str)
    return (strlen(this->str));
  else 
    return (0);
}

int compare_s(String *this, const String* str)
{
  return (strcmp(this->str, str->str));
}

int compare_c(String *this, const char* str)
{
  return (strcmp(this->str, str));
}

size_t copy(String* this, char* s, size_t n, size_t pos)
{
  if (s && pos+n < strlen(s))
    {
      s = strndup(&this->str[pos], n);
      return (strlen(s));
    }
  return 0;
}

const char* c_str(String * this)
{
  return (this->str);
}

int empty(String* this)
{
  if (this->str == NULL)
    return(1);
  else 
    return (-1);
}

int find_s(String* this, const String *str, size_t pos)
{
  return (strncmp(this->str, str->str, pos));
}

int find_c(String* this, const char* str, size_t pos)
{
  return (strncmp(this->str, str, pos));
}


int to_int(String * this)
{
  char *dest = this->str;
  return(atoi(dest));
}

void aff(String *stis)
{
  putstr(this->str);
}

void	StringInit(String *this, char const * s)
{
  if (s == NULL)
    this->str = NULL;
  else
    this->str = strdup(s);
}

