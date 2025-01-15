/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:51:45 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/15 14:09:09 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*target;
	t_stack_node	*head_b;
	long			target_number;

	head_b = stack_b;
	while (stack_a)
	{
		target_number = LONG_MIN;
		target = NULL;
		while (stack_b)
		{
			if (stack_b->content > target_number
				&& stack_a->content > stack_b->content)
				{
					target_number = stack_b->content;
					target = stack_b;
				}
			stack_b = stack_b->next;
		}
		if (!target)
			target = max_value(head_b);
		stack_a->target = target;
		stack_a = stack_a->next;
		stack_b = head_b;
	}
}

void	first_step(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_size(*stack_a) == 4)
		pa(&(*stack_a), &(*stack_b));
	sort_three(&(*stack_a));
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_size(*stack_a) == 2)
		return (sort_two(&(*stack_a)));
	else if (stack_size(*stack_a) == 3)
		return (sort_three(&(*stack_a)));
	first_step(&(*stack_a), &(*stack_b));
}

// int main(int ac, char **av)
// {
// 	t_stack_node	*stack_a;
// 	t_stack_node	*stack_b;
// 	char			*strs[] = {"15", "20", "18", NULL};
// 	char			*strss[] = {"7", "3", "2", "6", "12", NULL};
// 	stack_a = fill_list(strs);
// 	stack_b = fill_list(strss);
// 	if (!stack_a)
// 		return (0);
// 	set_target(stack_a, stack_b);
// 	return (0);
// }
