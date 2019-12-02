#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pde-bakk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/02 17:36:51 by pde-bakk      #+#    #+#                  #
#    Updated: 2019/12/02 17:38:37 by pde-bakk      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_printf.c ft_flags.c ft_itoa_base.c ft_putstuff.c ft_memsetfunctions.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(HEADER) $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
