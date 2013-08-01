##
## Makefile for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q
##
## Made by quentin pidoux
## Login   <pidoux_q@epitech.net>
##
## Started on  Fri Apr 20 11:46:05 2012 quentin pidoux
## Last update Fri Apr 20 18:01:58 2012 quentin pidoux
##

SDIR    =       ./src/
IDIR    =       ./include/

SERVEURNAME	=	serveur
SERVEURSRCS	=	$(SDIR)Serveur/serveur.c		\
			$(SDIR)Serveur/func_serveur.c		\
			$(SDIR)Serveur/check_msg.c		\
			$(SDIR)Serveur/make_sentence.c		\
			$(SDIR)Serveur/private_msg.c		\
			$(SDIR)xfunc.c

SERVEUROBJS	=	$(SERVEURSRCS:.c=.o)

CLIENTNAME	=	client
CLIENTSRCS	=	$(SDIR)Client/main.c			\
			$(SDIR)Client/client.c			\
			$(SDIR)Client/func_client.c

CLIENTOBJS	=	$(CLIENTSRCS:.c=.o)

CC	=	gcc
CFLAGS	=	-W -Wall -Wextra -Wstrict-prototypes -pedantic
LFLAGS	=	-lncurses
RM	=	rm -f
HFILE	=	-I ./inc/


all	:	$(CLIENTNAME) $(SERVEURNAME)

$(SERVEURNAME)	:	$(SERVEUROBJS)
			$(CC) -o $(SERVEURNAME) $(SERVEUROBJS)


$(CLIENTNAME)	:	$(CLIENTOBJS)
			$(CC) -o $(CLIENTNAME) $(CLIENTOBJS) $(LFLAGS)

clean	:
	$(RM) $(SERVEUROBJS)
	$(RM) $(CLIENTOBJS)
	@$(RM) *~
	@$(RM) $(SDIR)Client/*~
	@$(RM) $(SDIR)Serveur/*~
	@$(RM) *#
	@$(RM) $(SDIR)Client/*#
	@$(RM) $(SDIR)Serveur/*#

fclean	:	clean
	$(RM) $(SERVEURNAME)
	$(RM) $(CLIENTNAME)

re	:	fclean all

.c.o	:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HFILES)
