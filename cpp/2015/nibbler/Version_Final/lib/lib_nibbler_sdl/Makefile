
NAME=		lib_nibbler_sdl.so

SRC=		lib_nibbler_sdl.cpp

OBJ=		$(SRC:.cpp=.o)

INCLUDE=	-I../../include/

CXXFLAGS=	-W -Wall -Werror -fPIC $(INCLUDE)

LDFLAGS=	-lSDL -lSDL_ttf -lSDL_image

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
