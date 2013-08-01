NAME	=	server
SRCS	=	AcceptHandler.cpp	\
		Account.cpp		\
		Buffer.cpp		\
		Commands.cpp		\
		Deserializer.cpp	\
		Serializer.cpp		\
		Client.cpp		\
		ClientSocket.cpp	\
		main.cpp		\
		ReadWriteHandler.cpp	\
		Server.cpp		\
		ServerSocket.cpp	\
		Synchronizer.cpp	\
		UnixFunc.cpp		\
		WinFunc.cpp


OBJS	=	$(SRCS:.cpp=.o)
RM	=	rm -f
CC	=	g++
CXXFLAGS	+=	-W -Wall -Werror

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all
