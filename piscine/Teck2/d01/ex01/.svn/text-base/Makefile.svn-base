NAME   = menger
SRCS   = menger.c	\
	 main.c

OBJS   = $(SRCS:.c=.o)
CC     = gcc
RM     = rm -rf
CFLAGS = -Wextra -Wall -std=gnu99

all	: $(NAME)

$(NAME) : $(OBJS)
	  $(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
	  $(RM) $(OBJS)

fclean	: clean
	  $(RM) $(NAME)

re	: fclean all
	  $(RM) $(OBJS)

.PHONY: clean mrproper


mrproper: clean
	  rm $(NAME) temp
