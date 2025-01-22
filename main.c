/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:16:27 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/22 16:24:50 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

char	**get_numbers(int ac, char **av)
{
	if (ac == 2)
		return(ft_split(av[1], ' '));
	return (&av[1]);
}

void	init_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
 {
	*stack_a = NULL;
	*stack_b = NULL;
 }

int	is_sorted(t_stack_node *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int main(int ac, char **av)
{
	char			**numbers;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	
	if (!verif(ac, av))
		return (1);
	init_stacks(&stack_a, &stack_b);
	numbers = get_numbers(ac,av);
	stack_a = fill_list(numbers);
	if (ac == 2)
		free_matrice(ac, av, numbers);
	if (!stack_a)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}