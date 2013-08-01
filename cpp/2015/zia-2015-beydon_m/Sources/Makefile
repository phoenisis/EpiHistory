##
##  Makefile
##  ZIA
##
##  Created by Quentin PIDOUX on 08/04/13.
##  Copyright (c) 2012 EPITECH. All rights reserved.
##

SDIR    =	./

IDIR    =	./

NAME	=	ZIA

SRCS	=	$(SDIR)/main.cpp		\
		$(SDIR)/Body.cpp		\
		$(SDIR)/Buffer.cpp		\
		$(SDIR)/Client.cpp		\
		$(SDIR)/Config.cpp		\
		$(SDIR)/HttpCommands.cpp	\
		$(SDIR)/HttpParser.cpp		\
		$(SDIR)/ModuleManager.cpp	\
		$(SDIR)/PluginManager.cpp	\
		$(SDIR)/Request.cpp		\
		$(SDIR)/RequestHeader.cpp	\
		$(SDIR)/Response.cpp		\
		$(SDIR)/ResponseHeader.cpp	\
		$(SDIR)/Server.cpp		\
		$(SDIR)/ThreadPool.cpp		\
		$(SDIR)/tinyxml2.cpp		\
		$(SDIR)/UnixCondVar.cpp		\
		$(SDIR)/UnixFileStat.cpp	\
		$(SDIR)/UnixLibraryLoader.cpp	\
		$(SDIR)/UnixMutex.cpp		\
		$(SDIR)/UnixSynchronizer.cpp	\
		$(SDIR)/UnixTCPSocket.cpp	\
		$(SDIR)/UnixThread.cpp		\
		$(SDIR)/UnixTimer.cpp		\
		$(SDIR)/UnixUDPSocket.cpp	\
		$(SDIR)/WhatElseModule.cpp	\
		$(SDIR)/WinCondVar.cpp		\
		$(SDIR)/WinFileStat.cpp		\
		$(SDIR)/WinLibraryLoader.cpp	\
		$(SDIR)/WinMutex.cpp		\
		$(SDIR)/WinSynchronizer.cpp	\
		$(SDIR)/WinTCPSocket.cpp	\
		$(SDIR)/WinThread.cpp		\
		$(SDIR)/WinTimer.cpp		\
		$(SDIR)/WinUDPSocket.cpp

PHP_NAME=	libphp.so

PHP_SRCS=	$(SDIR)/PHP_CGI_mod.cpp		\

PHP_OBJS=	$(PHP_SRCS:.cpp=.o)		\
		Body.o				\
		Request.o			\
		RequestHeader.o			\
		Response.o			\
		ResponseHeader.o

OBJS	=	$(SRCS:.cpp=.o)
CXXFLAGS=	-W -Wall -O3
CXXFLAGSLIB=	$(CXXFLAGS) -fPIC
LNKFLAGS=	-shared
CXX	=	g++

RM	=	rm -rfv

$(NAME) :	obj
		$(CXX) $(LNKFLAGS) -o $(PHP_NAME) $(PHP_OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all	:	$(NAME)

obj	:
		$(CXX) $(CXXFLAGSLIB) -c $(PHP_SRCS)
		$(CXX) $(CXXFLAGS) -c $(SRCS)

clean   :
		@$(RM) ./*~
		@$(RM) ./#*#
		@$(RM) $(OBJS)

fclean  :	clean
		@$(RM) $(NAME)

re	:	fclean all