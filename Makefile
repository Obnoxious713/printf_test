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

SRC = flags.c \
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
		print_extra_stuff.c

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
	@$(CC) $(FLAGS) $(FTINC) -c $< -o $@

$(O): | ./bin

./bin:
	@mkdir -p $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@rm -rf *.o

fclean: clean
	@echo "-> Cleaning $(NAME)...\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
