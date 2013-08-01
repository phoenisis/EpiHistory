NAME		= epikong_etape_2

SRCS            = main.c		\
		  get_map.c		\
		  handle_key.c  	\
		  monster.c		\
	          getlevel.c    	\
	          player.c		\
		  move_monster.c 	\
	 	  game.c		\
		  setplayer.c		\
		  sprites.c		\
		  xSDL_img.c		\
		  xSDL_event.c		\
		  xfunction.c

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

re		: clean all

.PHONY  	: all clean fclean re

.c.o		:
		$(CC) $(CFLAGS) -c $< -o $@
