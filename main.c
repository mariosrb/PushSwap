/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:16:27 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/13 13:03:59 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	
	if (!verif(ac, av))
		return (0);
	fill_list(stack_a);
	return (0);
}