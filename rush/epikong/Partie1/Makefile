##
## Makefile for epikong in /afs/epitech.net/users/all/pidoux_q/public/epikong/Partie1
## 
## Made by sevan hubert
## Login   <hubert_s@epitech.net>
## 
## Started on  Sun Mar 27 23:12:36 2011 sevan hubert
## Last update Sun Mar 27 23:23:00 2011 sevan hubert
##

NAME	= epikong

SRCS	= main.c	 \
	  get_next_line.c\
	  usualFuncs.c   \
	  makeMap.c	 \
	  xfunction.c	 \
	  give_me_pos.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc

CFLAGS	= -W -Wall -Werror

all	: $(NAME)

$(NAME) : $(OBJS)
	  $(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lSDL

clean	: 
	  rm -rf $(OBJS)

fclean	:
	  rm -rf $(NAME)

re	: clean fclean all
