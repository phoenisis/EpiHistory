NAME    =       202loi

SRC     =       main.c \
                option.c

OBJ     =       $(SRC:.c=.o)

CC      =       gcc

CFLAGS  =       -W -Wall -ansi -pedantic

RM      =       rm -f

$(NAME) :       $(OBJ)
	        $(CC) -o $(NAME) $(OBJ)

all     :       $(NAME)

test    :
	        sh test.sh

clean   :
		$(RM) $(OBJ)

fclean  :       clean
	        $(RM) $(NAME)

re      :       fclean all

.PHONY : re fclean clean all 
