/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:51:45 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/14 17:50:29 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	set_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*target;
	t_stack_node	*tmp;
	long			target_number;

	target_number = LONG_MIN;
	target = NULL;
	tmp = stack_b;
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
		target = max_value(tmp);
	stack_a->target = target;
	printf("La valeur de la target de a = %d", target->content);
}

void	a_to_b

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_size(*stack_a) == 2)
		return (sort_two(&(*stack_a)));
	else if (stack_size(*stack_a) == 3)
		return (sort_three(&(*stack_a)));
	a_to_b(&(*stack_a), &(*stack_b));
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
