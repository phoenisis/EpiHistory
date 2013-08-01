##
## Makefile for objdump in /home/bonnet_b//projets/nm_obj_dump/objdump
## 
## Made by arnaud bonnet-de-larbogne
## Login   <bonnet_b@epitech.net>
## 
## Started on  Sun Mar 13 18:04:12 2011 arnaud bonnet-de-larbogne
## Last update Sun Mar 13 19:09:08 2011 arnaud bonnet-de-larbogne
##

SRC 	=	main.c			\
		loop_main_nm.c		\
		sort_list_and_display.c	\
		symtab.c

CC 	=	gcc

CFLAGS 	=	-W -Wall -ansi -pedantic -Wstrict-prototypes

OUTPUT 	=	my_nm

OBJ	=	${SRC:.c=.o}

${OUTPUT}	:$(OBJ)
		$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJ)

all	:	${OUTPUT}

clean	:
		rm -rf $(OBJ)
		rm -rf *~

fclean	:	clean
		rm -rf $(OUTPUT)

re:		fclean all
