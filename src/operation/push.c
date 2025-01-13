/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:45:08 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/13 13:14:30 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack_node **before, t_stack_node **after)
{
	t_stack_node	*tmp;

	if (!*before)
		return ;
	tmp = (*before)->next;
	(*before)->next = *after;
	if (*after != NULL)
		(*after)->prev = *before;
	*after = *before;
	*before = tmp;
	(*before)->prev = NULL;
}