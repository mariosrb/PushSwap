/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:43:00 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/22 11:25:49 by mdodevsk         ###   ########.fr       */
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

void	rb(t_stack_node **head)
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
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **head_a, t_stack_node **head_b)
{
	ra(&(*head_a));
	ra(&(*head_b));
}
