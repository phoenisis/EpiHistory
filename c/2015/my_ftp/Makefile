SERVER	= serveur
CLIENT	= client
IDIR	= ./inc/
SDIR	= ./src/
SERVER_SRC	= $(SDIR)serveur.c

SERVER_OBJ	= $(SERVER_SRC:.c=.o)
CLIENT_SRC	= $(SDIR)client.c		\
		  $(SDIR)get_next_line.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CC	= gcc
CFLAGS	= -W -Wall -Werror -ansi -pedantic -Wstrict-prototypes
IFLAGS	= -I$(IDIR)
DFLAGS	= 
LFLAGS	=	
GFLAGS	= 
OFLAGS	= 
RM	= rm -f
.c.o	:
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS) $(DFLAGS) $(OFLAGS)

all	: $(SERVER) $(CLIENT)

$(SERVER) :	$(SERVER_OBJ)
		$(CC) -o $(SERVER) $(SERVER_OBJ)

$(CLIENT) :	$(CLIENT_OBJ)
		$(CC) -o $(CLIENT) $(CLIENT_OBJ)

clean	:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(IDIR)*~ $(SDIR)*~ *~ \#*\#

fclean	: clean
	$(RM) $(SERVER) $(CLIENT)

re	: fclean all
