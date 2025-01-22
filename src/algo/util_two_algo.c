/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_two_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:27:32 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/22 11:29:24 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_first_values(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_target(stack_a, stack_b);
	get_index(stack_a);
	get_index(stack_b);
	get_median(stack_a);
	get_median(stack_b);
	get_first_cost(stack_a, stack_b);
	get_cheapest(stack_a);
	get_cheapest(stack_b);
}

void	init_second_values(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_second_target(stack_a, stack_b);
	get_index(stack_a);
	get_index(stack_b);
	get_median(stack_a);
	get_median(stack_b);
}
