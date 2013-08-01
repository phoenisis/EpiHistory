NAME		= epikong_etape_1

SRCS            = main.c	\
		  get_map.c	\
		  handle_key.c	\
		  xfunction.c	\
		  xSDL_event.c	\
		  xSDL_img.c

OBJS		= $(SRCS:.c=.o)
CC		= gcc
RM		= rm -f
CFLAGS		+= -W -Wall -Wextra
LDFLAGS		= -lSDL_image -lSDL -lpthread

$(NAME)		: $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all		: $(NAME)
		  clean

clean		:
		$(RM) $(OBJS)

fclean		: clean
		$(RM) $(NAME)

re		: fclean all

.PHONY  	: all clean fclean re

.c.o		:
		$(CC) $(CFLAGS) -c $< -o $@
