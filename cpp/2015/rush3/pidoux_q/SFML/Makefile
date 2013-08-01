
NAME	= MyGKrellM-SFML

SRCS	= main.cpp\
	 my_put_nbr.cpp\
	  ../../fleuro_m/Info.cpp

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -W -Wall -Werror -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

CC	= g++

RM	= rm -rf


$(NAME) : $(OBJS)
	  $(CC) -o $(NAME) $(OBJS) $(FLAGS)
	  @mv $(NAME) ../../.

all	: $(NAME)

clean	:
	  $(RM) $(OBJS)

fclean	: 
	  $(RM) $(NAME)

re	: clean $(NAME)