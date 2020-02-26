# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 23:16:01 by yelee             #+#    #+#              #
#    Updated: 2020/02/25 13:00:41 by yelee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & Basic Flags -------------------------------------------------------
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g \
		-fsanitize=address \

# Libray -------------------------------------------------------------------------
LIBRARY = libft/libft.a

# File Names ---------------------------------------------------------------------
SRC = backtrack board coordination error main free getfile
SRC_FILES = $(addsuffix .c, $(SRC))
OBJ_FILES = $(addsuffix .o, $(SRC))
NAME = fillit

# Required Makefile --------------------------------------------------------------
all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) $(CFLAGS) -I./libft/ -L./libft -lft $(SRC_FILES) -o $(NAME)
	@echo "File was compiled~"

clean:
	@echo "Cleaning Object Files..."
	@/bin/rm -rf $(OBJ_FILES)
	@make -C libft/ clean

fclean: clean
	@echo "Cleaning Library & Binary File..."
	@make -C libft/ fclean
	@if test -e $(NAME); then\
		/bin/rm $(NAME);\
	fi;

re: fclean all

.PHONY: all clean fclean re test norm

# Norminette ---------------------------------------------------------------------
norm:
	@norminette *.c *.h
