/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:54:30 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/16 11:10:11 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int i;
	int	stack_len;

	i = 0;
	stack_len = stack_size(stack);
	if (stack_len % 2 == 0)
	{
		while (i != stack_len / 2)
		{
			stack->median = 1;
			i++;
			stack = stack->next;
		}
	}
	else
		while (i != ((stack_len / 2 + 1)))
		{
			stack->median = 1;
			i++;
			stack = stack->next;
		}
}

void	get_cost(t_stack_node *stack)
{
	t_stack_node	*last;
	int				i;

	if (!stack || !stack->median)
		return ;
	i = 1;
	last = ft_lstlast(stack);
	while (stack && stack->median == 1)
	{
		stack->cost = stack->index;
		stack = stack->next;
	}
	stack = last;
	while (stack->median == 0)
	{
		stack->cost = i++;
		stack = stack->prev;
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