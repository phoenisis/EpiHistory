##
## Makefile for Makefile in /u/all/pidoux_q/cu/rendu/math/103homogene
## 
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
## 
## Started on  Sat Dec 12 17:59:08 2009 quentin pidoux
## Last update Sat Dec 12 18:22:39 2009 quentin pidoux
##

NAME	=	103homogene

SRCS	=	main.c		\
		homothetie.c	\
		rotation.c	\
		translation.c	\
		symetrie.c	\

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