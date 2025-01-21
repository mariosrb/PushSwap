/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:48:08 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/21 14:44:50 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack_node **head)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (!*head)
		return ;
	tmp = *head;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp->prev = tmp2;
	tmp2->next = *head;
	tmp2->prev = NULL;
	*head = tmp2;
	write (1, "sa\n", 3);
}
void	ss(t_stack_node **head_a, t_stack_node **head_b)
{
	sa(&(*head_a));
	sa(&(*head_b));
}