
CXXFLAGS = -lcurses -ltermcap -W -Wall -Werror -ldl -lsfml-graphics -lsfml-window -lsfml-system

NNCURSE = libNcurse.so

SNCURSE = ./Ncurse/libNcurse.cpp

ONCURSE = $(SNCURSE:.cpp=.o)

NSFML	= libSFML.so

SSFML	= ./SFML/SFML.cpp

OSFML = $(SSFML:.cpp=.o)

CC	= g++

RM	= rm -rf

all	: $(NSFML) $(NNCURSE)


$(NNCURSE)	:
		  $(CC) -c -fPIC $(SNCURSE)
		   mv libNcurse.o ./Ncurse/
	  	  $(CC) -shared $(ONCURSE) -o $(NNCURSE)
	  	  mv $(NNCURSE) ./Ncurse/.

$(NSFML)	:
	          $(CC) -c -fPIC $(SSFML)
		  mv SFML.o ./SFML/
	  	  $(CC) -shared $(OSFML) -o $(NSFML)
	  	  mv $(NSFML) ./SFML/.

clean   :
	 @$(RM) ./*~
	 @$(RM) ./#*#
	 @$(RM) $(ONCURSE) $(OSFML)

fclean  : clean
	  @$(RM) $(NAME) $(NNCURSE) $(NSFML)

re	: clean all

.PHONY  : all clean fclean re cclean
