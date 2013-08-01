NAME	= philo1
SRC	= philosophe.c	\
	  actions.c	\
	  free_struct.c

OBJS	= $(SRC:.c=.o)
CFLAGS	= -pipe -O3 -W -Wall -Werror -ansi -pedantic -lpthread
CC	= gcc
RM	= rm -rf

$(NAME) : $(OBJS)
	  $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	  @echo "Binary : $(NAME)"

all     : $(NAME)

clean   :
	 @$(RM) *~
	 @$(RM) */*~
	 @$(RM) *#
	 @$(RM) $(OBJS)
	 @echo "Cleaning ......OK"

fclean  : clean
	 @$(RM) $(NAME)
	 @echo "Removing Bin ......OK"

re      :cclean

cclean  : all
	 @$(RM) *~
	 @$(RM) */*~
	 @$(RM) *#
	 @$(RM) $(OBJS)
	 @echo "Cleaning For Better View ...... OK"

.PHONY  : all clean fclean re cclean