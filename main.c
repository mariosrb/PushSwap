/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:16:27 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/16 10:34:39 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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
			return (1);
		stack = stack->next;
	}
	return (0);
}

// int main(int ac, char **av)
// {
// 	t_stack_node	*stack_a;
// 	t_stack_node	*stack_b;
	
// 	// on verifie les arguments
// 	if (!verif(ac, av))
// 		return (1);
// 	// Initialisation de la stack a et b
// 	init_stacks(&stack_a, &stack_b);
// 	// Remplissage de la stack a
// 	stack_a = fill_list(av);
// 	if (!stack_a)
// 		{
// 			write(2, "Error\n", 6);
// 			return (1);
// 		}
// 	// Si cest deja trie on fait rien sinon on trie
// 	if (!is_sorted(stack_a))
// 		sort_stack(&stack_a, &stack_b);
// 	// On free les deux stacks
// 	free_list(stack_a);
// 	free_list(stack_b);
// 	return (0);
// }