# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pde-bakk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/02 17:36:51 by pde-bakk      #+#    #+#                  #
#    Updated: 2020/06/11 17:06:05 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

# COLORS
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

all: $(NAME)

$(NAME):
	@echo "$(YELLOW)Linking the library"
	@gcc -c $(FLAGS) -I ./include/ $(SRC)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Done!$(RESET)"

clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@/bin/rm -f *.o *~ *.gch

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
