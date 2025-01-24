/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:04:22 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/11/12 18:54:10 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					content;
	int					cost;
	int					index;
	int					median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

// Fonctions libft
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			**ft_split(const char *s, char c);
t_stack_node	*ft_lstlast(t_stack_node *lst);
t_stack_node	*ft_lstmap(t_stack_node *lst, void *(*f)(void *), void (*del)(void *));
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);

#endif
