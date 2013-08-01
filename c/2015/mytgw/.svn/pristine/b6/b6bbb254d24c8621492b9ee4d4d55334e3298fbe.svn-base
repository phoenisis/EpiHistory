##
## Makefile for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/psu_mytgw-2015-pidoux_q
##
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
##
## Started on  Tue Jul 24 16:57:40 2012 quentin pidoux
## Last update Tue Jul 24 17:12:56 2012 quentin pidoux
##

C		=	gcc
NAME		=	my_tgw
SRC		=	src/main.c 	\
			src/server.c 	\
			src/log.c 	\
			src/xFunc.c 	\
			src/xConnect.c



OBJ		=	$(SRC:.c=.o)
RM		=	rm -rf
CFLAGS		=	-W -Wall
##INCLUDES	=	-I ./


$(NAME)		: 	$(OBJ)
			$(C) -o $(NAME) $(OBJ) $(CFLAGS)
			@echo -e "\033[1;31mBinaire : $(NAME)\033[0m"

all		:	clean $(NAME)


.c.o		:
			@cc -o $@ -c $< $(INCLUDES) $(CFLAGS)
			@echo -e "\033[32mChecking\033[0m $@ \033[33m......\033[32mOK\033[0m"

clean		:
			@$(RM) *~
			@$(RM) */*~
			@$(RM) *#
			@$(RM) $(OBJ)
			@echo -e "\033[32mCleaning\033[0m $@ \033[33m......\033[32mOK\033[0m"

fclean		:	 clean
			@$(RM) $(NAME)
			@echo -e "\033[32mRemoving Exec\033[0m $@ \033[33m......\033[32mOK\033[0m"

re		:	fclean all

cclean		:	all
			@$(RM) *~
			@$(RM) */*~
			@$(RM) *#
			@$(RM) $(OBJ)
			@echo -e "\033[32mCleaning For Better View\033[0m $@ \033[33m......\033[32mOK\033[0m"

.PHONY		:	all clean fclean re cclean
