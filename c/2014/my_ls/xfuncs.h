/*
** xfuncs.h for  in /u/all/pidoux_q/cu/rendu/c/my_ls
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sun Nov  7 15:16:48 2010 quentin pidoux
** Last update Sun Nov  7 15:16:49 2010 quentin pidoux
*/

#ifndef			__XFUNCS_H__
# define		__XFUNCS_H__

#define			OPENDIR_FAILED "oppendir failed\n"
#define			CLOSEDIR_FAILED "closedir failed\n"
#define			READDIR_FAILED "readdir failed\n"
#define			WRITE_FAILED "write failed\n"
#define			MALLOC_FAILED "malloc failed\n"

DIR			*xopendir(const char *name);
int			xclosedir(DIR *dirp);
int			xwrite(int d, const void *buf, size_t nbytes);
struct dirent		*xreaddir(DIR *dirp);
void			*xmalloc(size_t size);

#endif			/* __FUNCS_H__ */
