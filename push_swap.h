#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

long	ft_atol(char *str);
int		check_format(int ac, char **av);
int		is_double(char **strs, int i);
int		is_space(char *str);
int		is_valid_number(char *str);
void	free_matrice(char **strs);


#endif