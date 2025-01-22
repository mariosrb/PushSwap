/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:25:51 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/22 11:26:43 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack_node **head)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!*head)
		return ;
	tmp = *head;
	last = *head;
	while (1)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			break;
		last = last->next;
	}
	tmp->next = *head;
	tmp->prev = NULL;
	last->next = NULL;
	(*head)->prev = tmp;
	*head = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **head)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!*head)
		return ;
	tmp = *head;
	last = *head;
	while (1)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			break;
		last = last->next;
	}
	tmp->next = *head;
	tmp->prev = NULL;
	last->next = NULL;
	(*head)->prev = tmp;
	*head = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **head_a, t_stack_node **head_b)
{
	rra(&(*head_a));
	rra(&(*head_b));
}