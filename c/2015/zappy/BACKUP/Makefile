#ZAPPY
#Makefile

NAMESERVER	= server/server

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
			  server/map.c				\


OBJSSERVER 	= $(SRCSSERVER:.c=.o)


NAMECLIENT	= client/client

SRCSCLIENT	=	client/cmds.cpp			\
			client/error.cpp        	\
			client/filetransfert.cpp	\
			client/handle_server.cpp	\
			client/main_client.cpp		\
			client/str_to_wordtab.cpp	\

OBJSCLIENT	= $(SRCSCLIENT:.cpp=.o)

CC	= clang

CPP	= clang++

CFLAGS	+= -g3 -W -Wextra -Wall  

RM	= rm -rf

.PHONY		:	all clean fatclean re

$(NAME)	:	$(OBJSSERVER) Makefile
		$(OBJSCLIENT) Makefile
		$(CC) -o $(NAMESERVER) $(OBJSSERVER) $(CFLAGS)
		$(CPP) -o $(NAMECLIENT) $(OBJSCLIENT) $(CFLAGS)
		$(clean)

all	:	$(NAME) server client

server	:	$(OBJSSERVER) Makefile
	 	$(CC) -o $(NAMESERVER) $(OBJSSERVER) $(CFLAGS)
		$(clean)

client	:	$(OBJSCLIENT) Makefile
	 	$(CPP) -o $(NAMECLIENT) $(OBJSCLIENT) $(CFLAGS)
		$(clean)

clean	:
	@find . \( -name "*.o" -o -name "*~" -o -name "#*#" \) -exec rm {} \;

re	:	fclean all

fclean:		clean
		@$(RM) $(NAMESERVER) $(NAMECLIENT)






