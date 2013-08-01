##
## Makefile for Makefile in /u/all/ricard_v/cu/rendu/math/102matrice
## 
## Made by vincent ricard
## Login   <ricard_v@epitech.net>
## 
## Started on  Sat Nov 28 19:49:48 2009 vincent ricard
## Last update Sat Nov 28 20:15:18 2009 vincent ricard
##

NAME            =       102matrice
SRCS            =       main.c			\
			option_1.c		\
			option_2.c 		\
			option_3.c		\
			option_4.c		\
			lib_base.c		\
			my_strncpy.c		\
			my_get_nbr_base.c	\
			my_getnbr.c		\
			my_put_nbr.c		\
			my_putchar.c		\
			my_putnbrbase.c		\
			my_putstr.c		\
			my_strlen.c		\

OBJS            =       $(SRCS:.c=.o)

CC              =       gcc
RM              =       rm -f
CFLAGS          =       -W -Wall -ansi -pedantic

all             :       $(NAME)

$(NAME)         :       $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean           :
			$(RM) $(OBJS)

fclean          :       clean
		$(RM) $(NAME)

re              :       fclean all
