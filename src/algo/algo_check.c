/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:54:30 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/15 16:55:15 by mdodevsk         ###   ########.fr       */
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
		while (i != stack_len)
		{
			stack->median = true;
			i++;
			stack = stack->next;
		}
	}
	else
		while (i != ((stack_len / 2) + 1))
		{
			stack->median = true;
			i++;
			stack = stack->next;
		}
}