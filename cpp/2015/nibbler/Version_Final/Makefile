
NAME=		nibbler


#Directory path
LIB_PTH=	lib

##Libraries paths
SDL_PTH=	$(LIB_PTH)/lib_nibbler_sdl
OGL_PTH=	$(LIB_PTH)/lib_nibbler_opengl
NCU_PTH=	$(LIB_PTH)/lib_nibbler_ncurses

##Libraries names
SDL=		lib_nibbler_sdl.so
OGL=		lib_nibbler_opengl.so
NCU=		lib_nibbler_ncurses.so


#Directory path
SRC_PTH=	src

#Source file
SRC=		$(SRC_PTH)/main.cpp		\
		$(SRC_PTH)/Case.cpp		\
		$(SRC_PTH)/ColorRGB.cpp		\
		$(SRC_PTH)/toDisplay.cpp	\
		$(SRC_PTH)/Prey.cpp		\
		$(SRC_PTH)/Player.cpp		\
		$(SRC_PTH)/Nibbler.cpp		\
		$(SRC_PTH)/Field.cpp		\
		$(SRC_PTH)/CExceptions.cpp	\
		$(SRC_PTH)/Error.cpp		\
		$(SRC_PTH)/DLLoader.cpp

OBJ=		$(SRC:.cpp=.o)

RM=		rm -rf *~ *\#

#Include
INC_PTH=	include
INCLUDE=	-I $(INC_PTH)

#Compilation flags
CXXFLAGS=	-W -Wall -Werror $(INCLUDE)
LDFLAGS=	-L. -ldl



.PHONY:		all	\
		re	\
		clean	\
		fclean

$(NAME):	$(OBJ)
		g++ -export-dynamic $(OBJ) $(LDFLAGS) -o $(NAME)
		@echo ""

all:		$(NAME)
		@(cd $(SDL_PTH) && make)
		@(cd $(OGL_PTH) && make)
		@(cd $(NCU_PTH) && make)

clean:
		@clear
		$(RM) $(OBJ)
		@echo ""
		@echo "Clean lib"
		@(cd $(SDL_PTH) && make clean)
		@(cd $(OGL_PTH) && make clean)
		@(cd $(NCU_PTH) && make clean)
		@echo ""

fclean:		clean
		$(RM) $(SDL) $(OGL) $(NCU)
		$(RM) $(NAME)
		@echo ""
		@echo "fclean lib"
		@(cd $(SDL_PTH) && make fclean)
		@(cd $(OGL_PTH) && make fclean)
		@(cd $(NCU_PTH) && make fclean)
		@echo ""

re:		fclean all
