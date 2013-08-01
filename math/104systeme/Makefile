##
## Makefile for Makefile in /u/all/pidoux_q/cu/rendu/math/104systeme
## 
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
## 
## Started on  Mon Dec 21 10:01:33 2009 quentin pidoux
## Last update Mon Dec 21 10:53:07 2009 quentin pidoux
##

NAME	=	104systeme

SRCS	=	main.c		\
		option1.c	\
		option2.c	\
		option3.c	\
		option4.c	\

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

RM	=	rm -f

CFLAGS	=	-lm -W -Wall -pedantic -ansi

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:	
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean 	all