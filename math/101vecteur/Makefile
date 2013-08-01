##
## Makefile for  in /u/all/pidoux_q/cu/rendu/c/my_ls
## 
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
## 
## Started on  Sun Nov  7 15:15:14 2010 quentin pidoux
## Last update Tue Nov  9 13:19:52 2010 quentin pidoux
##

NAME   = 101vecteur
SRCS   = main.c		\
	 my_getnbr.c	\
	 option_1.c	\
	 option_2.c	\
	 option_3.c

OBJS   = $(SRCS:.c=.o)
CC     = gcc
RM     = rm -rf

all	: $(NAME)

$(NAME) : $(OBJS)
	  $(CC) -lm -o $(NAME) $(OBJS)

clean	:
	  $(RM) $(OBJS)

fclean	: clean
	  $(RM) $(NAME)

re	: fclean all
	  $(RM) $(OBJS)

.PHONY: clean mrproper


mrproper: clean
	rm $(EXEC)
