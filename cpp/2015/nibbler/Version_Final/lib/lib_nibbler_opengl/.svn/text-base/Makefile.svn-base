
NAME=		lib_nibbler_opengl.so

SRC=		lib_nibbler_opengl.cpp

INTERFACE_INC=	../../include

OBJ=		$(SRC:.cpp=.o)

OPENGL=		-lGL -lGLU -lglut

INC=		-I$(INTERFACE_INC)

CXXFLAGS=	-W -Wall -Werror -fPIC $(OPENGL) $(INC) 

$(NAME):	$(OBJ)
		g++ -shared $(OBJ) $(OPENGL) -o $(NAME)
		cp $(NAME) ../..
		@echo

all:		$(NAME)

clean:
		rm -rf $(OBJ)
		rm -rf *~ \#~\#

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all \
		clean \
		fclean \
		re
