
#ifndef XFUNC_H_
# define XFUNC_H_

# define READ_FAILED "read failed\n"
# define WRITE_FAILED "write failed\n"
# define MALLOC_FAILED "malloc failed\n"

ssize_t		xread(int, void *, size_t)
int         xwrite(int, const void *, size_t);
void		*xmalloc(size_t);

#endif /* !XFUNC_H_ */
