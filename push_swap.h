/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:31:32 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/13 12:19:24 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

// typedef struct s_stack_node
// {
// 	int					content;
// 	int					cost;
// 	int					index;
// 	bool				median;
// 	bool				cheap;

// 	struct s_stack_node	*next;
// 	struct s_stack_node	*prev;
// 	struct s_stack_node	*target;
// }	t_stack_node;

// Parsing
long			ft_atol(char *str);
int				check_format(int ac, char **av);
int				is_double(char **strs, int i);
int				is_space(char *str);
int				is_valid_number(char *str);
void			free_matrice(int ac, char **av, char **strs);

// Stack 

t_stack_node	*new_node(int n);
t_stack_node	*fill_list(char **strs);
void			free_list(t_stack_node *list);


// Operation
void			rev_rotate_both(t_stack_node **head_a, t_stack_node **head_b);
void			rev_rotate(t_stack_node **head);
void			rotate_both(t_stack_node **head_a, t_stack_node **head_b);
void			rotate_to_last(t_stack_node **head);
void			push_first(t_stack_node **before, t_stack_node **after);
void			swap_both(t_stack_node **head_a, t_stack_node **head_b);
void			swap_first(t_stack_node **head);

//  Algo 
t_stack_node	*max_value(t_stack_node *head);
t_stack_node	*min_value(t_stack_node *head);

#endif