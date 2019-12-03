# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pde-bakk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/02 17:36:51 by pde-bakk       #+#    #+#                 #
#    Updated: 2019/12/03 16:57:13 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_flags.c ft_itoa_base.c ft_putstuff.c ft_memsetfunctions.c \
ft_typefinder.c ft_longfinders.c ft_longlongfinders.c ft_shortfinders.c \
ft_shortshortfinders.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(HEADER) $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o *~ *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
