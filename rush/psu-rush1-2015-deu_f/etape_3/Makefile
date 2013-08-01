NAME		= epikong_etape_3

SRCS		= main.c		\
		  get_map.c		\
		  handle_key.c		\
		  monster.c		\
		  getlevel.c		\
		  player.c		\
		  move_monster.c	\
		  check_monster.c	\
		  game.c		\
		  setplayer.c		\
		  sprites.c		\
		  life.c		\
		  epikong.c		\
		  xfunction.c		\
		  xSDL_img.c		\
		  xSDL_event.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS		+= -W -Wall -Wextra -g3
LDFLAGS		= -lSDL_image -lSDL -lpthread

$(NAME)		: $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all		: $(NAME)

clean		:
		$(RM) $(OBJS)

fclean		: clean
		$(RM) $(NAME)

re		: fclean all

.PHONY		: all clean fclean re

.c.o		:
		$(CC) $(CFLAGS) -c $< -o $@
