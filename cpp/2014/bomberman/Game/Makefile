
NAME	= bomberman

SRCS	= ./AObject.cpp	\
	  ./Blocs.cpp	\
	  ./Bomb.cpp	\
	  ./Bomberman.cpp	\
	  ./Bonus.cpp \
	  ./Camera.cpp \
	  ./Config.cpp \
	  ./Cube.cpp \
	  ./Fire.cpp \
	  ./IBonus.cpp \
	  ./Map.cpp \
	  ./MyGame.cpp \
	  ./Player.cpp \
	  ./Usual_funcs.cpp \
	  ./Rectangle.cpp \
	  ./Triange.cpp \
	  ./Vector3f.cpp \
	  ./main.cpp \
	  ./MenuCamera.cpp \
	  ./Menu.cpp \
	  ./MenuLabel.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX	= g++ -I ../libgdl_gl-2012.1/include/ -L ../libgdl_gl-2012.1/lib/ -Wl,--rpath=../libgdl_gl-2012.1/lib/ -lgdl_gl -lGL -lGLU -lSDL -lSDL_mixer -lsfml-graphics -lsfml-window -lsfml-system

CC	= g++

RM	= rm -rf


$(NAME) : $(OBJS)
	  $(CC) -o $(NAME) $(OBJS)


all	: $(NAME)


clean   :
	 @$(RM) ./*~
	 @$(RM) ./#*#
	 @$(RM) $(OBJS)

fclean  : clean
	  @$(RM) $(NAME)

re	: all


.PHONY  : all clean fclean re cclean
