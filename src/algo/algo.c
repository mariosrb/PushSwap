/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:51:45 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/29 16:56:35 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*target;
	t_stack_node	*head_b;
	long			target_number;

	head_b = stack_b;
	while (stack_a)
	{
		target_number = LONG_MIN;
		target = NULL;
		while (stack_b)
		{
			if (stack_b->content > target_number
				&& stack_a->content > stack_b->content)
			{
				target_number = stack_b->content;
				target = stack_b;
			}
			stack_b = stack_b->next;
		}
		if (!target)
			target = max_value(head_b);
		stack_a->target = target;
		stack_a = stack_a->next;
		stack_b = head_b;
	}
}

void	push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*current;

	current = *stack_a;
	while (current->cheapest != true)
		current = current->next;
	if (current->median == 1)
	{
		while (current != *stack_a)
			ra(stack_a);
	}
	else
	{
		while (current != *stack_a)
			rra(stack_a);
	}
	while (current->target->index != 0)
	{
		if (current->target->median == 1)
			rb(stack_b);
		else
			rrb(stack_b);
		get_index(*stack_b);
	}
	pa(stack_a, stack_b);
}

void	first_step(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_size(*stack_a) == 4)
	{
		pa(&(*stack_a), &(*stack_b));
		sort_three(&(*stack_a));
		return ;
	}
	pa(&(*stack_a), &(*stack_b));
	pa(&(*stack_a), &(*stack_b));
	while (stack_size(*stack_a) != 3)
	{
		init_first_values(*stack_a, *stack_b);
		push_to_b(stack_a, stack_b);
	}
	sort_three(&(*stack_a));
}

void	second_step(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (*stack_b)
	{
		init_values(*stack_a, *stack_b);
		push_to_a(stack_a, stack_b);
	}
	get_index(*stack_a);
	while (min_value(*stack_a)->index != 0)
	{
		if (min_value(*stack_a)->median == 1)
			ra(stack_a);
		else
			rra(stack_a);
		get_index(*stack_a);
	}
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_size(*stack_a) == 2)
		return (sort_two(&(*stack_a)));
	else if (stack_size(*stack_a) == 3)
		return (sort_three(&(*stack_a)));
	first_step(&(*stack_a), &(*stack_b));
	second_step(&(*stack_a), &(*stack_b));
}
