##
## Makefile for Makefile in /home/pidoux_q//rendu/my_printf
## 
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
## 
## Started on  Sun Nov 28 12:45:16 2010 quentin pidoux
## Last update Sun Nov 28 12:51:48 2010 quentin pidoux
##

NAME	= libmy_printf_`uname -m`-`uname -s`.a

SRC	= funcs.c       \
	  my_putnbr.c 	\
	  func.c	\
	  my_printf.c

OBJ	= $(SRC:.c=.o)
AR      = ar rc
RAN	= ranlib
RM	= rm -rf

$(NAME)	: $(OBJS)
	  @$(AR) $(NAME) $(OBJS)
	  @$(RAN) $(NAME)
	  @echo -e "\033[1;31mLibrary : $(NAME)\033[0m"


all	: clean $(NAME)

clean	:
	 @$(RM) *~
	 @$(RM) */*~
	 @$(RM) *#
	 @$(RM) $(OBJ)
	 @echo -e "\033[32mCleaning\033[0m $@ \033[33m......\033[32mOK\033[0m"

fclean	: clean
	  @$(RM) $(NAME)
	  @echo -e "\033[32mRemoving Lib\033[0m $@ \033[33m......\033[32mOK\033[0m"

re	: cclean

cclean	: all clean
	  @echo -e "\033[32mCleaning For Better View\033[0m $@ \033[33m......\033[32mOK\033[0m"

.PHONY	: all clean fclean re cclean
