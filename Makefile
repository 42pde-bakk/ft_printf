# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pde-bakk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/02 17:36:51 by pde-bakk      #+#    #+#                  #
#    Updated: 2020/10/24 11:53:59 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = ./src
SRC = ft_printf.c ft_flags.c ft_itoa_base.c ft_putstuff.c \
ft_typefinder.c ft_longfinders.c ft_longlongfinders.c ft_shortfinders.c \
ft_shortshortfinders.c ft_floats.c ft_moreputstuff.c ft_ultoa.c ft_floats2.c \
ft_floats3.c

GNLOBJ = ./get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

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
	@make bonus -s -C ./libft/
	@make re -s -C ./get_next_line/
	@gcc -c $(FLAGS) -I ./include/ $(FILES)
	@cp ./libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ) $(GNLOBJ)
	@echo "$(GREEN)Done!$(RESET)"

clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@make clean -s -C ./libft
	@make clean -s -C ./get_next_line
	@/bin/rm -f *.o *~ *.gch

fclean: clean
	@make fclean -s -C ./libft
	@make fclean -s -C ./get_next_line
	@/bin/rm -f $(NAME)

re: fclean all

bonus: re
	@echo "$(PINK)Linking bonus files$(RESET)"
