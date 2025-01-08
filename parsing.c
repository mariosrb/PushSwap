/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:04:00 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/05 14:51:09 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrice(char **strs)
{
	int	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || !str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
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
	int i = 0;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
		i++;
	}
	return (0);
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
			return (1);
		}
		i++;
	}
	if (ac == 2)
		free_matrice(strs);
	return (0);
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
	if (!check_format(ac, av))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	return (0);
}