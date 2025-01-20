/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:54:30 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/20 15:06:44 by mdodevsk         ###   ########.fr       */
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

void	get_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*tmp;

	if (!stack_a)
		return;
	tmp = stack_a;
	// printf("size stack_a: %d\n", stack_size(stack_a));
	// printf("size stack_b: %d\n", stack_size(stack_b));
	while (tmp)
	{
		tmp->cost = 0;
		// printf("\nNode %d:\n", tmp->content);
        // printf("index: %d, median: %d\n", tmp->index, tmp->median);
        // printf("target: %d, target_index: %d, target_median: %d\n", tmp->target->content, tmp->target->index, tmp->target->median);
		if (tmp->index == 0)
			tmp->cost = 0;
		else if (tmp->median == 1)
			tmp->cost = tmp->index;
		else
			tmp->cost = stack_size(stack_a) - tmp->index;
		// printf("After stack_a cost: %d\n", tmp->cost);
		if (tmp->target->index == 0)
			tmp->cost += 0;
		else if (tmp->target->median == 1)
			tmp->cost += tmp->target->index;
		else
			tmp->cost += stack_size(stack_b) - tmp->target->index;
		//printf("%d cout --> %d\n", tmp->content, tmp->cost);
		// printf("After stack_b cost: %d\n", tmp->cost);
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

void	second_step(t_stack_node **stack_a, t_stack_node **stack_b)
{
}

void	set_second_target(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*target;
	t_stack_node	*head_b;
	long			target_number;

	head_b = stack_b;
	while (stack_a)
	{
		target_number = LONG_MAX;
		target = NULL;
		while (stack_b)
		{
			if (stack_b->content < target_number
				&& stack_a->content < stack_b->content)
				{
					target_number = stack_b->content;
					target = stack_b;
				}
			stack_b = stack_b->next;
		}
		if (!target)
			target = min_value(head_b);
		stack_a->target = target;
		stack_a = stack_a->next;
		stack_b = head_b;
	}
}