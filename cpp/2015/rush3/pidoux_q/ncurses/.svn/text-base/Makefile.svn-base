
NAME	= MyGKrellM

SRCS	= main.cpp 	\
	 ../../fleuro_m/Info.cpp

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -W -Wall -Werror -lcurses

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