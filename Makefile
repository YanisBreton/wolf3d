##
## .Makefile for Makefile in /home/lecler_i/epitech/usefull
##
## Made by thomas leclercq
## Login   <lecler_i@epitech.net>
##
## Started on  Thu Jan 17 15:59:53 2013 thomas leclercq
## Last update Thu Jan 17 23:56:29 2013 thomas leclercq
##

NAME =		wolf3d

LIB_PATH =	./lib/

LIBMY =		libmy.a

MY.H =		my.h

SRCS =		main.c \
		events1.c \
		events2.c \
		parsing/map1.c \
		parsing/map2.c \
		draw/basics.c \
		draw/walls.c \
		weapons.c \
		pulse.c \
		casting.c \
		initialization1.c \
		initialization2.c \
		free.c \
		sound.c \
		strlcpy.c

LIBS +=		-L . -lmy

LIBS +=		-L /usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lm

LIBS +=		-L ./sound/fmod/ -lfmodex64-4.44.04		

CC =		gcc

RM =		rm -f

CP=		cp -f

CD=		cd

CFLAGS +=	-ansi -pedantic

CFLAGS +=	-I.

OPTIONALFLAGS =	-Wextra -Wall -Werror

OBJS =		$(SRCS:.c=.o)

all:		$(LIBMY) $(MY.H) $(NAME)


$(NAME): 	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LIBS) 

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) $(LIBMY)
		$(RM) $(MY.H)

re:		fclean fclean_lib all

all_lib:
		$(CD) $(LIB_PATH) && make

$(LIBMY):	
		$(CD) $(LIB_PATH) && make
		$(CD) $(LIB_PATH) && make copylib

$(MY.H):
		$(CD) $(LIB_PATH) && make copymy
clean_lib:
		$(CD) $(LIB_PATH) && make clean

fclean_lib:
		$(CD) $(LIB_PATH) && make fclean

re_lib:	
		$(CD) $(LIB_PATH) && make re

.PHONY: 	all clean fclean re

help:
		@echo ""
		@echo "#############  MAKEFILE HELP ################"
		@echo "#                                           #"
		@echo "#             DEFAULT ACTIONS               #"
		@echo "# make all              make the project    #"
		@echo "# make (exec_name)      compile the project #"
		@echo "# make clean            clean the project   #"
		@echo "# make fclean           fclean the project  #"
		@echo "# make re               re-make the project #"
		@echo "#                                           #"
		@echo "# make my.h             copy my.h           #"
		@echo "# make libmy.a          copy libmy.a        #"
		@echo "#                                           #"
		@echo "#             LIBRARY ACTIONS               #"
		@echo "# make all_lib          make the lib        #"
		@echo "# make clean_lib        clean the lib       #"
		@echo "# make fclean_lib       fclean the lib      #"
		@echo "# make re_lib           re-make the lib     #"
		@echo "#############################################"
		@echo ""