/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:04:00 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/12 17:46:02 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrice(int ac, char **av, char **strs)
{
	int	i = 0;
	if (ac == 2)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	printf("--%s--\n", str);
	if (!str || str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_space(char *str)
{
	int i;
	int	only_space;

	i = 0;
	only_space = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			only_space = 0;
		i++;
	}
	return (only_space);
}

int		is_double(char **strs, int i)
{
	int		j;
	long	num;
	
	j = 0;
	num = ft_atol(strs[i]);
	while (j < i)
	{
		if (num == ft_atol(strs[j]))
			return (1);
		j++;
	}
	return (0);
}

// void	fill_list(t_stack_node **stack_a, char **strs, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (strs[i])
// }

int	check_format(int ac, char **av)
{
	int		i;
	char	**strs;
	long	num;

	i = 0;
	if (ac == 2)
		strs = ft_split(av[1], ' ');
	else
		strs = &av[1];
	while (strs[i])
	{
		num = ft_atol(strs[i]);
		if (!is_valid_number(strs[i]) || num < INT_MIN || num > INT_MAX
			|| is_double(strs, i))
		{
			ft_printf("Error premiere boucle.");
			free_matrice(ac, av, strs);
			return (0);
		}
		i++;
	}
	if (ac == 2)
		free_matrice(ac, av, strs);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
	{
		printf("Erreur : Aucun argument fourni.\n");
		return (1);
	}
	if ((ac == 2 && !av[1][0]) || !check_format(ac, av))
	{
		write (1, "Error\n", 6);
		return (1);
	}
	return (0);
}