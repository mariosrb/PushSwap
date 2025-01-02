
#include "push_swap.h"

void	ft_print_matrice(char **strs)
{
	int i = 0;

	while(strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i]))
	}
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

int	main(int ac, char **av)
{
	(void)ac;
	int 	i = 1;
	char	**res;
	int	j = 0;

	while(av[i])
	{
		if (is_space(av[i]))
      	{
            res = ft_split(av[i], ' ');
		while (res[j])
		{
			j++;
		}
            ft_print_matrice(res);
            free(res);
      	}
      	else
		{
            
			printf("%s\n", av[i]);
		}
      	i++;
	}
	return (0);
}