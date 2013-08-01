/*
** my_ls.c for  in /u/all/pidoux_q/cu/rendu/c/my_ls
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sun Nov  7 15:16:04 2010 quentin pidoux
** Last update Sun Nov  7 16:13:02 2010 quentin pidoux
*/

#include	<pwd.h>
#include	<grp.h>
#include	<unistd.h>
#include	<time.h>
#include	<dirent.h>
#include	<sys/stat.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"my_ls.h"
#include	"xfuncs.h"

void		my_ls()
{
  DIR		*d; 
  struct dirent	*read;

  d = xopendir (".");
  if (d != NULL)
    {
      while ((read = xreaddir(d)))
	{
	  if (read->d_name[0] != '.')
	    {
	      my_putstr(read->d_name);
	      my_putstr("\t");
	    }
	}
      xclosedir(d);
    }
}

void		my_ls_a()
{
  DIR		*d; 
  struct dirent	*read;

  d = xopendir (".");
  if (d != NULL)
    {
      while ((read = xreaddir(d)))
	{
	  if (read->d_name[2] != '.')
	    {
	      my_putstr(read->d_name);
	      my_putstr("\t");
	    }
	}
      xclosedir(d);
    }
}

void		my_ls_directory(char *str)
{
  DIR		*d; 
  struct dirent	*read;

  d = opendir(str);
  if (d != NULL)
    {
      while ((read = xreaddir(d)))
	{
	  if (read->d_name[0] != '.')
	    {
	      my_putstr(read->d_name);
	      my_putstr("\t");
	    }
	  /* my_putchar('\n');*/
	}
      xclosedir(d);
    }
  if (d == NULL)
      my_putstr(str);
}
