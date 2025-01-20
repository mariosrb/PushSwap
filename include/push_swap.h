/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:31:32 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/16 17:02:30 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

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

void	print_list(t_stack_node *head);


// Parsing
long			ft_atol(char *str);
int				check_format(int ac, char **av);
void			free_matrice(int ac, char **av, char **strs);
int				verif(int ac, char **av);
int				free_and_error(t_stack_node **stack_a, t_stack_node **stack_b);

// Stack 
t_stack_node	*new_node(int n);
t_stack_node	*fill_list(char **strs);
void			free_list(t_stack_node *list);
int				stack_size(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);
void			init_stacks(t_stack_node **stack_a, t_stack_node **stack_b);

// Operation
void			rrr(t_stack_node **head_a, t_stack_node **head_b);
void			rra(t_stack_node **head);
void			rr(t_stack_node **head_a, t_stack_node **head_b);
void			ra(t_stack_node **head);
void			pa(t_stack_node **before, t_stack_node **after);
void			ss(t_stack_node **head_a, t_stack_node **head_b);
void			sa(t_stack_node **head);

//  Algo 
t_stack_node	*max_value(t_stack_node *head);
t_stack_node	*min_value(t_stack_node *head);
void			sort_three(t_stack_node **stack);
void			sort_two(t_stack_node **stack);
void			get_cheapest(t_stack_node *stack);
void			get_index(t_stack_node *stack);
void			get_median(t_stack_node *stack);
void			get_cost(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_target(t_stack_node *stack_a, t_stack_node *stack_b); // a mettrte en static
void			sort_stack(t_stack_node **stack_a, t_stack_node **stack_b);
void			init_values(t_stack_node *stack_a, t_stack_node *stack_b);
void			push_to_b(t_stack_node **stack_a, t_stack_node **stack_b); // static ?
void			first_step(t_stack_node **stack_a, t_stack_node **stack_b); // static
void        	second_step(&(*stack_a), &(*stack_b));



#endif