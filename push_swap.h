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
void	reverse_rotate_both(t_list **head_a, t_list **head_b);
void	reverse_rotate(t_list **head);
void	rotate_both(t_list **head_a, t_list **head_b);
void	rotate_to_last(t_list **head);
void	push_first(t_list **before, t_list **after);
void	swap_both(t_list **head_a, t_list **head_b);
void	swap_first(t_list **head);


#endif