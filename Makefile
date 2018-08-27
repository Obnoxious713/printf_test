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
NAME2 = libftprintf

FLAGS =	-Wall -Wextra -Werror -g

CC = gcc

ODIR = ./
IDIR = ./

SRC = libft/ft_putchar.c \
		libft/ft_putstr.c \
		libft/ft_putnbr.c \
		libft/ft_toupper.c \
		libft/ft_strlen.c \
		libft/ft_itoa_base.c \
		libft/ft_isdigit.c \
		libft/ft_strcpy.c \
		libft/ft_isalpha.c \
		libft/ft_atoi.c \
		libft/ft_strcmp.c \
		libft/ft_strtoupper.c \
		libft/ft_ltoa_base.c \
		libft/ft_ultoa_base.c \
		libft/ft_itoa.c \
		flags.c \
		flags2.c \
		ft_printf.c \
		ft_putnbr_pr.c \
		ft_putulong.c \
		parse_cs.c \
		parse_d.c \
		parse_loc.c \
		parse_num_form.c \
		parse_po.c \
		parse_size.c \
		parse_x_1.c \
		parse_x.c \
		parser.c \
		print_extra_flags.c \
		print_extra_stuff.c \
		main.c

OBJ = $(SRC:.c=.o)
EXT = $(IDIR)$(NAME:.a=.h)

O = $(addprefix $(ODIR), $(OBJ))

LIBFT = ./libft/libft.a
FTINC = -I./libft
LINK_FT = -L./libft -lft

all: $(LIBFT) $(NAME)

love: all

norm:
	norminette $(S)

$(LIBFT):
	@make -C ./libft

$(NAME): $(O) $(EXT)
	@echo "-> Creating archive $(NAME)...\n "
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c $(EXT)
	@$(CC) $(FLAGS) $(FTINC) -I $(IDIR) -c $< -o $@

$(O): | ./bin

exe: $(NAME)
	@echo "-> Compiling $(NAME)..."
	@$(CC) -o $(NAME) $(O) $(LINK_FT)
	@echo "\n   * * *   Done   * * *"

./bin:
	@mkdir -p $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@rm -rf *.o

fclean: clean
	@echo "-> Cleaning $(NAME)...\n"
	@rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re norm
