/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:54:30 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/24 13:32:00 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*CC = cc 

CFLAGS = -Wall -Wextra -Werror

VPATH = algo operation parsing

SRC =	./src/algo/algo_check.c ./src/algo/algo.c ./src/algo/util_algo.c ./src/algo/util_two_algo.c \
		./src/operation/push.c ./src/operation/reverse.c ./src/operation/rotate.c ./src/operation/swap.c \
		./src/operation/utils_list.c ./src/parsing/parsing.c ./src/parsing/utils.c ./main.c

NAME = pushswap.a
AR = ar -rcs
OBJ = $(SRC:./%.c=%.o)

$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re*/

#include "../../include/push_swap.h"

void	get_index(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}

void	get_median(t_stack_node *stack)
{
	int				 i;
	int				stack_len;
	t_stack_node	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		tmp->median = 0;
		tmp = tmp->next;
	}
	i = 0;
	stack_len = stack_size(stack);
	while (stack && i < (stack_len + 1) / 2)
	{
		stack->median = 1;
		i++;
		stack = stack->next;
	}
}

void	get_first_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*tmp;

	if (!stack_a)
		return;
	tmp = stack_a;
	while (tmp)
	{
		tmp->cost = 0;
		if (tmp->index == 0)
			tmp->cost = 0;
		else if (tmp->median == 1)
			tmp->cost = tmp->index;
		else
			tmp->cost = stack_size(stack_a) - tmp->index;
		if (tmp->target->index == 0)
			tmp->cost += 0;
		else if (tmp->target->median == 1)
			tmp->cost += tmp->target->index;
		else
			tmp->cost += stack_size(stack_b) - tmp->target->index;
		tmp = tmp->next;
	}
}

void	get_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	long			cheapest_number;

	cheapest_number = LONG_MAX;
	cheapest = NULL;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->cost < cheapest_number)
		{
			cheapest_number = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}

void	set_second_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*target;
	t_stack_node	*head_a;
	long			target_number;

	head_a = stack_a;
	while (stack_b)
	{
		target_number = LONG_MAX;
		target = NULL;
		while (stack_a)
		{
			if (stack_a->content < target_number
				&& stack_b->content < stack_a->content)
				{
					target_number = stack_a->content;
					target = stack_a;
				}
			stack_a = stack_a->next;
		}
		if (!target)
			target = min_value(head_a);
		stack_b->target = target;
		stack_b = stack_b->next;
		stack_a = head_a;
	}
}