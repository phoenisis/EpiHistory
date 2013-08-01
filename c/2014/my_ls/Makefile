##
## Makefile for  in /u/all/pidoux_q/cu/rendu/c/my_ls
## 
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
## 
## Started on  Sun Nov  7 15:15:14 2010 quentin pidoux
## Last update Mon Nov 15 10:37:30 2010 quentin pidoux
##

SHELL  = /bin/sh

NAME   = my_ls
SRCS   = my_ls.c	\
	 func.c		\
	 xfuncs.c	\
	 main.c

OBJS   = $(SRCS:.c=.o)
CC     = gcc
RM     = rm -rf
CFLAGS = -W -Wall -pedantic -ansi

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
