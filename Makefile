# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 12:15:28 by mario             #+#    #+#              #
#    Updated: 2025/01/29 12:08:07 by mdodevsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc -g3

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./libft
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Source files
SRCS = ./main.c $(wildcard $(SRC_DIR)/**/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Library
LIBFT = $(LIBFT_DIR)/libft.a

# Executable name
NAME = push_swap

# Main rules
all: libft $(NAME)

# Compile libft first
libft:
	make -C $(LIBFT_DIR)

# Link the executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean object files
clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

# Full clean (remove executable and object files)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets to avoid conflicts with file names
.PHONY: all clean fclean re libft