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
// "2 3 4 5" 5 6 7 8
void	verif(int ac, char **av)
{
	t_list *a;
	int		i;
	char	**result;
	// si > 2 arguments on atoi les arguments 
	// si = 2 split sur le 2eme argument
	
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
	verif(ac, av);
	return (0);
}