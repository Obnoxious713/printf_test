# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 14:57:21 by jfleisch          #+#    #+#              #
#    Updated: 2018/08/08 14:57:22 by jfleisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  ft_printf

FLAGS = -Wall -Werror -Wextra -g

CC = gcc

NORM = norminette -R CheckForbiddenSourceHeader

SRC = main.c \
		parser.c \
		ft_putnbr_pr.c \
		flags.c \
		flags2.c \
		ft_putulong.c \
		parse_cs.c \
		parse_d.c \
		parse_loc.c \
		parse_num_form.c \
		parse_po.c \
		parse_size.c \
		parse_x.c \
		parse_x_1.c \
		print_extra_flags.c \
		print_extra_stuff.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = ./libft/libft.a
LIBFTINC = -I./libft
LINK_FT = -L./libft -lft

LIBPF = ./libpf/libpf.a
LIBPFINC = -I./libpf/include
LINK_PF = -L./libpf -lpf

SRCDIR = ./src/
INCDIR = ./include/
OBJDIR = ./bin/

all: obj libft libpf $(NAME)

pflib:
	@make -C ./libpf fclean
	@make

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) $(LIBFTINC) $(LIBPFINC) -I $(INCDIR) -o $@ -c $<

libpf: $(LIBPF)

libft: $(LIBFT)

$(LIBPF):
	@make -C ./libpf

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJ)
	@echo "-> Compiling $(NAME)..."
	@$(CC) -o $(NAME) $(OBJ) $(LINK_PF) $(LINK_FT)

clean:
	@echo "-> Cleaning $(NAME) object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "-> Cleaning $(NAME)...\n "
	@rm -rf $(NAME)
	@make -C ./libft fclean
	@make -C ./libpf fclean

re: fclean all

norm:
	$(NORM)

love: all #credit to notoriousgtw

.PHONY: all clean fclean re
