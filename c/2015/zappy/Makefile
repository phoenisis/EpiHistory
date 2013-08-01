##
## Makefile for Makefile ZAPPY in /home/cohen_d//zappy/zappy-2015-2014s-herve_a
## 
## Made by clement cohen
## Login   <cohen_d@epitech.net>
## 
## Started on  Sun Jul 15 22:29:37 2012 clement cohen
## Last update Sun Jul 15 22:29:45 2012 clement cohen
##

$(shell tar -xf SFML-2.0-rc-linux-64.tar.bz2)

NAMESERVER	= Server

SRCSSERVER	=	  server/main.c				\
	               	  server/handle_clients.c		\
	               	  server/handle_clients_welcome.c	\
	               	  server/main_server.c			\
	               	  server/communication.c		\
			  server/list_clients.c			\
	               	  server/player.c			\
	               	  server/str_to_wordtab.c		\
	               	  server/parse.c			\
	               	  server/error.c			\
			  server/mapp.c				\
			  server/broadcast.c			\
			  server/display_funcs.c		\
			  server/display_info_player.c		\
			  server/team_name.c			\
			  server/prendre.c			\
			  server/move.c				\
			  server/jeter.c			\

OBJSSERVER 	= $(SRCSSERVER:.c=.o)

NAMECLIENT	= Client

SRCSCLIENT	=	clientc++/Client.cpp			\
			clientc++/IA.cpp        		\
			clientc++/init.cpp			\
			clientc++/main.cpp			\
			clientc++/parse.cpp			\
			clientc++/player.cpp			\

OBJSCLIENT	= $(SRCSCLIENT:.cpp=.o)

CC	= clang

CXX	= g++ -I ./SFML-2.0-rc/include/ -L ./SFML-2.0-rc/lib/ -Wl,--rpath=./SFML-2.0-rc/lib/ -lsfml-network -lsfml-system

CFLAGS	+= -g3 -W -Wextra -Wall

RM	= rm -rf

.PHONY		:	all clean fatclean re

$(NAME)	:	$(OBJSSERVER) Makefile
		$(OBJSCLIENT) Makefile
		$(CC) -o $(NAMESERVER) $(OBJSSERVER) $(CFLAGS)
		$(CXX) -o $(NAMECLIENT) $(OBJSCLIENT) $(CFLAGS)
#		@find . \( -name "*.o" -o -name "*~" -o -name "#*#" \) -exec rm {} \;


all	:	$(NAME) server client


server	:	$(OBJSSERVER) Makefile
	 	$(CC) -o $(NAMESERVER) $(OBJSSERVER) $(CFLAGS)
#		@find . \( -name "*.o" -o -name "*~" -o -name "#*#" \) -exec rm {} \;


client	:	$(OBJSCLIENT) Makefile
	 	$(CXX) -o $(NAMECLIENT) $(OBJSCLIENT) $(CFLAGS)
#		@find . \( -name "*.o" -o -name "*~" -o -name "#*#" \) -exec rm {} \;

clean	:
		@find . \( -name "*.o" -o -name "*~" -o -name "#*#" \) -exec rm {} \;

re	:	fclean all

fclean:		clean
		@$(RM) $(NAMESERVER) $(NAMECLIENT)
