##
##  Makefile
##  210Random
##
##  Created by Quentin PIDOUX on 30/04/12.
##  Copyright (c) 2012 EPITECH. All rights reserved.
##

NAME    = 210random
SRCS    = ./src/210random.c \
	  ./src/calculs.c

OBJS    = $(SRCS:.c=.o)

CC      = gcc
CFLAGS  = -W -Wall -Werror -Wextra
RM      = rm -rf

all     : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
	$(RM) src/*.o

clean   :
	$(RM) *.o $(NAME)

re      : clean all
