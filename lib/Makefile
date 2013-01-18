##
## Makefile for Makefile in /home/lecler_i//afs/local/lib/my
## 
## Made by thomas leclercq
## Login   <lecler_i@epitech.net>
## 
## Started on  Mon Oct 22 09:18:44 2012 thomas leclercq
## Last update Thu Jan 17 23:15:24 2013 thomas leclercq
##

LIB_NAME=	libmy.a

INCL_NAME=	my.h

LIB_DEST=	../

INCL_DEST=	../

SRC=		get_next_line.c \
		my_find_prime.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_power_rec.c \
		my_printf.c \
		my_putchar.c \
		my_putnbr_base.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_show_wordtab.c \
		my_sort_int_tab.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlcat.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_str_to_wordtab.c \
		my_strupcase.c \
		my_swap.c \
		x_functions.c

OBJS=		$(SRC:.c=.o)

RM=		rm -f

CP=		cp -f

all:		$(LIB_NAME)

$(LIB_NAME):	$(OBJS)
		cc -c $(SRC)
		ar rc $(LIB_NAME) $(OBJS)
		ranlib $(LIB_NAME)

copylib:
		$(CP) $(LIB_NAME) $(LIB_DEST)

copymy:	
		$(CP) $(INCL_NAME) $(INCL_DEST)

re:		fclean all

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(LIB_NAME)
