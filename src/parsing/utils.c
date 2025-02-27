/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:22:16 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/30 12:21:08 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_matrice(int ac, char **av, char **strs)
{
	int	i;

	(void)av;
	i = 0;
	if (ac == 2)
	{
		while (strs[i])
			free(strs[i++]);
		free(strs);
	}
}

int	free_and_error(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_a || *stack_a)
		free_list(*stack_a);
	if (stack_b || *stack_b)
		free_list(*stack_b);
	write (2, "Error\n", 6);
	return (1);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	free_list(t_stack_node *list)
{
	t_stack_node	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

long	ft_atol(char *str)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	number = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		number = (number * 10) + str[i] - '0';
		i++;
	}
	if (sign == 1)
		number = number * (-1);
	return (number);
}
