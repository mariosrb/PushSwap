/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:04:00 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/12/24 17:23:39 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verif(char **av)
{
	t_list *a;
	int		i;
	char	**result;
	
	i = 0;
	a = ft_lstnew(0);

	while (av[i])
	{
			
	}
}	

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Pas assez darguments\n");
		return (0);
	}
	verif(av);
	return (0);
}