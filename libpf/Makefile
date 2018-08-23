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

NAME = libpf.a
NAME2 = libpf
FLAGS =	-Wall -Wextra -Werror -g
CC = gcc
ODIR = bin/
IDIR = include/
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
EXT = $(IDIR)$(NAME:.a=.h)

EXT += Makefile

O = $(addprefix $(ODIR), $(OBJ))

LFTINC = -I../libft

all: $(NAME)

love: all

norm:
	norminette $(S)

$(NAME): $(O) $(EXT)
	@echo "-> Creating archive $(NAME)...\n "
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c $(EXT)
	@$(CC) $(FLAGS) $(LFTINC) -c $< -o $@

$(O): | ./bin

./bin:
	@mkdir -p $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "-> Cleaning $(NAME)...\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
