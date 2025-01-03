/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:04:00 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/12/29 19:28:15 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		is_double()
{
	
}

void	check_format(int ac, char **av)
{
	char	**strs;
	int		i;
	
	i = 0;
	if (ac == 2)
		strs[i] = av[1];
	else
	{
		strs = av;
	}
	while (strs[i])
	{

	}
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
	while (av[i])
	{
		if (is_valid_number(av[i]))
			printf("Valide\n");
		else
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}