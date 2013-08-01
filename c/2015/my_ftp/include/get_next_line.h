#ifndef			__GET_NEXT_LINE_H__
# define		__GET_NEXT_LINE_H__

#define			BUF_SIZE 1080

char			*my_memset(char *str, int size);
char			*get_next_line(int fd);
int			my_strlen(char *str);
int			xread(int fd, void *buff, int nbytes);
void			*xmalloc(int size);

#endif			/*__GET_NEXT_LINE_H__*/
