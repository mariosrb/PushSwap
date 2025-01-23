# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 18:37:01 by mdodevsk          #+#    #+#              #
#    Updated: 2024/12/24 14:42:38 by mdodevsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRC = ./ft_atoi.c ./ft_isdigit.c ./ft_split.c ./ft_itoa.c\
	  ./ft_lstnew_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstsize_bonus.c \
      ./ft_lstlast_bonus.c ./ft_lstadd_back_bonus.c ./ft_lstdelone_bonus.c \
      ./ft_lstclear_bonus.c ./ft_lstiter_bonus.c 

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
