##
##  Makefile
##  ccmmander
##
##  Created by Quentin PIDOUX on 30/04/12.
##  Copyright (c) 2012 EPITECH. All rights reserved.
##

SDIR    =	./src

IDIR    =	./inc/

NAME	=	kommander

SRCS	=	$(SDIR)/main.cpp		\
		$(SDIR)/Building.cpp		\
		$(SDIR)/Ressource.cpp		\
		$(SDIR)/Map.cpp



OBJS	=	$(SRCS:.cpp=.o)

CXX	=	g++

RM	=	rm -rfv

$(NAME) :	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS)
		@$(RM) $(OBJS)

all	:	$(NAME)

clean   :
		@$(RM) ./*~
		@$(RM) ./#*#
		@$(RM) $(OBJS)

fclean  :	clean
		@$(RM) $(NAME)

re	:	clean all

.PHONY  :	all clean fclean re cclean

.c.o   	:
		$(CXX) $(CXXFLAGS) -c $< -o $(<:.c=.o)
