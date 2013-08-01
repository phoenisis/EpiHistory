##
## Makefile for makefile in /u/all/pidoux_q/cu/rendu/c/minitalk
## 
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
## 
## Started on  Thu Mar  4 16:01:28 2010 quentin pidoux
## Last update Thu Mar  4 16:05:01 2010 quentin pidoux
##

NAME    =       minitalk

SRCS    =       main.c          

OBJS    =       $(SRCS:.c=.o)

CC      =       cc

RM      =       rm -f

CFLAGS  =       -W -Wall -pedantic -ansi

all     :       $(NAME)

$(NAME) :       $(OBJS)
                $(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean   :
                $(RM) $(OBJS)

fclean  :       clean
                $(RM) $(NAME)

re      :       fclean  all
