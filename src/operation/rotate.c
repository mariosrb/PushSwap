/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:43:00 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/21 14:44:12 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*tmp;

	if (!*head)
		return ;
	if (!(*head)->next)
		return ;
	first = *head;
	tmp = *head;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = tmp;
	write(1, "ra\n", 3);
}

void	rr(t_stack_node **head_a, t_stack_node **head_b)
{
	ra(&(*head_a));
	ra(&(*head_b));
}

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

void	rrr(t_stack_node **head_a, t_stack_node **head_b)
{
	rra(&(*head_a));
	rra(&(*head_b));
}