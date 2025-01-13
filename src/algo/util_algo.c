/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:41:55 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/13 12:42:14 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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