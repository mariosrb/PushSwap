/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:41:55 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/13 16:55:20 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_size(t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				i;

	i = 0;
	tmp = stack;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack_node	*max_value(t_stack_node *head)
{
	t_stack_node	*max;
	t_stack_node	*tmp;

	max = head;
	tmp = head->next;
	while (tmp != NULL)
	{
		if (max->content < tmp->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack_node	*min_value(t_stack_node *head)
{
	t_stack_node	*min;
	t_stack_node	*tmp;

	min = head;
	tmp = head->next;
	while (tmp != NULL)
	{
		if (min->content > tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_two(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	if ((*stack)->content > tmp->content)
		sa(stack);
}
void	sort_three(t_stack_node **stack)
{
	t_stack_node	*second;
	t_stack_node	*third;
	
	second = (*stack)->next;
	third = second->next;

	if ((*stack)->content > second->content && 
		(*stack)->content > third->content)
		ra(stack);
	else if (second->content > (*stack)->content &&
		second->content > third->content)
		rra(stack);
	second = (*stack)->next;
	third = second->next;
	if (second->content < (*stack)->content)
		sa(stack);
}
