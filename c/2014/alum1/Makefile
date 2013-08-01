##
## Makefile for make our alum1 in here
## 
## Made by sevan hubert
## Login   <hubert_s@epitech.net>
## 
## Started on  Tue Oct 20 11:13:31 2009 sevan hubert
## Last update Sun Feb 14 17:36:18 2010 sevan hubert
##

NAME 	= alum1
SRCS 	= AIbot.c		\
	  my_prompt.c		\
	  aff_and_create.c

OBJS 	= $(SRCS:.c=.o)

RM	= rm
LIBS	= 
CC	= cc
FLAGS   = -W -Wall -o


all	: $(NAME)

$(NAME) : $(OBJS)
	  $(CC) $(FLAGS) $(NAME) $(OBJS) $(LIBS)

clean	:
	  $(RM) $(OBJS)

fclean  : clean
	  $(RM) $(NAME)