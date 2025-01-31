/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_two_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:27:32 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/29 16:40:46 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*current;

	current = (*stack_b)->target;
	if (current->index != 0)
	{
		if (current->median == 1)
			while ((*stack_a)->content != current->content)
				ra(stack_a);
		else
			while ((*stack_a)->content != current->content)
				rra(stack_a);
	}
	pb(stack_b, stack_a);
}

void	init_first_values(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_target(stack_a, stack_b);
	get_index(stack_a);
	get_index(stack_b);
	get_median(stack_a);
	get_median(stack_b);
	get_first_cost(stack_a, stack_b);
	get_cheapest(stack_a);
	get_cheapest(stack_b);
}

void	init_values(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_second_target(stack_a, stack_b);
	get_index(stack_a);
	get_index(stack_b);
	get_median(stack_a);
	get_median(stack_b);
}
