#
# Makefile for Abstract VM
#

NAME	= avm

SRCS	= main.cpp	\
	  Action.cpp	\
	  CreatOperand.cpp

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS = -W -Wall -std=gnu++0x

CC	= g++

RM	= rm -rf

$(NAME) : $(OBJS)
	  $(CC) $(FLAGS) -o $(NAME) $(OBJS)
	  @echo "Binary : $(NAME)"

all	: clean $(NAME)

clean   :
	 @$(RM) *~
	 @$(RM) *#
	 @$(RM) $(OBJS)
	 @echo "Cleaning$@ ... OK."

fclean  : clean
	  @$(RM) $(NAME)

re	: cclean
	  @echo "Removing Binary $@ ... OK."

cclean  : all
	  @clean
	  @echo "Cleaning For Better View $@ ... OK."

.PHONY  : all clean fclean re cclean
