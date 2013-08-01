##
## Makefile for makefile in /home/pidoux_q//rendu/piscine/Jour_10
## 
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
## 
## Started on  Mon Oct 18 15:44:13 2010 quentin pidoux
## Last update Mon Oct 18 16:19:37 2010 quentin pidoux
##

NAME 	= libmy.a
NAME2	= my.h
SRCS 	= my_find_prime_sup.c	\
	  my_get_nbr_base.c	\
	  my_getnbr.c		\
	  my_isneg.c		\
	  my_is_prime.c		\
	  my_power_it.c		\
	  my_power_rec.c	\
	  my_putchar.c		\
	  my_putnbr_base.c	\
	  my_put_nbr.c		\
	  my_putstr.c		\
	  my_revstr.c		\
	  my_showmem.c		\
	  my_showstr.c		\
	  my_sort_int_tab.c	\
	  my_square_root.c	\
	  my_strcapitalize.c	\
	  my_strcat.c		\
	  my_strcmp.c		\
	  my_strcpy.c		\
	  my_str_isalpha.c	\
	  my_str_islower.c	\
	  my_str_isnum.c	\
	  my_str_isprintable.c	\
	  my_str_isupper.c	\
	  my_strlcat.c		\
	  my_strlen.c		\
	  my_strlowcase.c	\
	  my_strncat.c		\
	  my_strncmp.c		\
	  my_strncpy.c		\
	  my_strstr.c		\
	  my_strupcase.c	\
	  my_swap.c

OBJS 	= $(SRCS:.c=.o)

RM	= rm -rf
CC	= cc
AR	= ar rc
CP	= cp
END	= /u/all/pidoux_q/rendu/lib/
END2	= /u/all/pidoux_q/rendu/include/

all	: $(NAME)

$(NAME) : $(OBJS)
	  $(AR) $(NAME) $(OBJS)
	  $(CP) $(NAME) $(END)
	  $(CP) $(NAME2) $(END2)

clean	:
	  $(RM) $(OBJS) $(NAME)

fclean  : clean
	  $(RM) $(NAME) $(NAME2)
