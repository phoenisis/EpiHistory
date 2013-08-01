CC	=	g++
CFLAGS	+=	-Wall -Wextra -std=c99 -pedantic
LDFLAGS	+=

TARGET	=	my_convert_temp
SOURCES	=	my_convert_temp.cpp
HEADERS	=	
OBJECTS	=	$(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
$(OBJECTS): $(HEADERS)
all: $(TARGET)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
