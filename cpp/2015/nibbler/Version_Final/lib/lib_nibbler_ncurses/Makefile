
NAME=		lib_nibbler_ncurses.so

SRC=		lib_nibbler_ncurses.cpp

OBJ=		$(SRC:.cpp=.o)

INCLUDE=	-I../../include/

CXXFLAGS=	-W -Wall -Werror -fPIC $(INCLUDE)

LDFLAGS=	-lm -lncurses

$(NAME):	$(OBJ)
		g++ -shared $(OBJ) $(LDFLAGS) -o $(NAME)
		cp $(NAME) ../..
		@echo

all:		$(NAME)

clean:
		@clear
		rm -rf $(OBJ)
		rm -rf *~ \#*\#
		@echo ""

fclean:		clean
		rm -rf $(NAME)
		@echo ""

re:		fclean all

.PHONY:		all \
		clean \
		fclean \
		re
