# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mario <mario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 12:17:13 by mario             #+#    #+#              #
#    Updated: 2025/01/24 14:04:11 by mario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	./ft_atoi.c ./ft_isdigit.c ./ft_split.c ./ft_itoa.c \
		./ft_lstlast_bonus.c ./ft_lstadd_back_bonus.c

NAME = libft.a
AR = ar -rcs
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(AR) $@ $^

all: $(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
