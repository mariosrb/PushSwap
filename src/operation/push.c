/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:45:08 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/29 11:47:35 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack_node **before, t_stack_node **after)
{
	t_stack_node	*tmp;

	if (!*before)
		return ;
	if ((*before)->next)
	{
		tmp = (*before)->next;
		(*before)->next = *after;
		if (*after != NULL)
			(*after)->prev = *before;
		*after = *before;
		*before = tmp;
		(*before)->prev = NULL;
	}
	else
	{
		(*before)->next = *after;
		 if(*after != NULL)
		 	(*after)->prev = *before;
		*after = *before;
		*before = NULL;
	}
	write (1, "pb\n", 3);
}

void	pb(t_stack_node **before, t_stack_node **after)
{
	t_stack_node	*tmp;

	if (!*before)
		return ;
	if ((*before)->next)
	{
		tmp = (*before)->next;
		(*before)->next = *after;
		if (*after != NULL)
			(*after)->prev = *before;
		*after = *before;
		*before = tmp;
		(*before)->prev = NULL;
	}
	else
	{
		(*before)->next = *after;
		 if(*after != NULL)
		 	(*after)->prev = *before;
		*after = *before;
		*before = NULL;
	}
	write (1, "pa\n", 3);
}
