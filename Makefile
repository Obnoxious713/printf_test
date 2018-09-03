# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 15:55:00 by jfleisch          #+#    #+#              #
#    Updated: 2018/07/21 15:55:01 by jfleisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME2 = pft_to_push

FLAGS = -Wall -Wextra -Werror -g

CC = gcc

ODIR = ./
IDIR = ./

SRC = flags.c \
		ft_printf.c \
		ft_put_pf.c \
		helper.c \
		loc.c \
		parser.c \
		prec.c \
		print_flags.c \
		size.c \
		start.c \
		type_char.c \
		type_hex_int.c \
		type_hex_int_1.c \
		type_int.c \
		type_int_1.c \
		type.c
		# main.c

OBJ = $(SRC:.c=.o)
EXT = $(IDIR)$(NAME:.a=.h)

O = $(addprefix $(ODIR), $(OBJ))

LIBFT = ./libft/libft.a
FTINC = -I./libft
LINK_FT = -L./libft -lft

LINK_PF = -L./ -lftprintf

all: $(LIBFT) $(NAME) #exe

love: all

norm:
	norminette -R CheckForbiddenSourceHeader

$(LIBFT):
	@make -C ./libft

$(NAME): $(O) $(EXT)
	@echo "-> Creating archive $(NAME)...\n "
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c
	@$(CC) $(FLAGS) $(FTINC) -I $(IDIR) -c $< -o $@

$(O): | ./bin

exe: $(NAME)
	@echo "-> Compiling $(NAME2)..."
	@$(CC) -o $(NAME2) $(O) $(LINK_FT) $(LINK_PF) -W1,--no-undefined -fsanitize=address
	@echo "\n   * * *   Done   * * *"

./bin:
	@mkdir -p $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@rm -rf $(O)

fclean: clean
	@echo "-> Cleaning $(NAME)...\n"
	@rm -rf $(NAME)
	@rm -rf $(NAME2)
	@make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re norm
