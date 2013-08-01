##
## Makefile for Makefile in /u/all/anncel_m/cu/rendu/c/proj/ntn
## 
## Made by maxime anncelli
## Login   <anncel_m@epitech.net>
## 
## Started on  Sat Dec  6 14:51:05 2008 maxime anncelli
## Last update Sun Dec  7 17:56:18 2008 anthony lorillon
##

CC = gcc -g
NAME = ntn
SRC =	main.c		 \
	cent.c		 \
	dix1.c		 \
	dix.c            \
	dix22.c 	 \
	dix2.c           \
	mille.c		 \
	mille2.c	 \
	mille3.c         \
	mille4.c	 \
	million.c	 \
	my_putchar.c 	 \
	exec.c		 \
	my_putstr.c  	 \
	my_put_nbr.c     \
	my_strlen.c      \
	unity.c    	 \
	sixdix.c     	 \
	huitdix.c	 \
	espace.c	 \
	ntn.c		 \

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wall -pedantic -ansi

RM	= rm -f

$(NAME) : $(OBJ)
	  @$(CC) -o $(NAME) $(OBJ)
	  @echo "Compilation Success!!"

all :	  $(NAME)

clean:
	  @$(RM) *.o
	  @echo "Cleaning..."
	  @echo "Clean Success!"

fclean:   clean
	  @$(RM) $(NAME)

re:	  fclean all

_PHONY:   all clean fclean re