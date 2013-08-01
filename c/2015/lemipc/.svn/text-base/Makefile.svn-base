NAME	= lemipc

SRCS	= action.c      \
	  lemipc.c 	\
	  game_action.c	\
	  map.c

CC	= gcc
CFLAGS	= -W -Wall -Wextra
OBJS	= $(SRCS:.c=.o)
RM	= rm -rf

$(NAME)	: $(OBJS)
	  $(CC) -o $(NAME) $(OBJS)
	  @echo -e "Binary : $(NAME)"


all	: $(NAME)

clean	:
	 @$(RM) *~
	 @$(RM) */*~
	 @$(RM) *#
	 @$(RM) $(OBJS)
	 @echo -e "Cleaning ... OK."

fclean	: clean
	  @$(RM) $(NAME)
	  @echo -e "Removing Bin ... OK."

re	: cclean

cclean	: all clean
	  @echo -e "Cleaning For Better View ... OK."

.PHONY	: all clean fclean re cclean
