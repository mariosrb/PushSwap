/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:47:36 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/12 15:48:06 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*new_node(int n)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->content = n;
	new->next = NULL;
	new->prev = NULL;
	new->target = NULL;
	return (new);
}

void	print_list(t_stack_node *head)
{
	while (head != NULL)
	{
		printf("la valeur est %d\n", head->content);
		head = head->next;
	}
}

void	swap_first(t_stack_node **head)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (!*head)
		return ;
	tmp = *head;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp->prev = tmp2;
	tmp2->next = *head;
	tmp2->prev = NULL;
	*head = tmp2;
}
void	swap_both(t_stack_node **head_a, t_stack_node **head_b)
{
	swap_first(&(*head_a));
	swap_first(&(*head_b));
}

void	push_first(t_stack_node **before, t_stack_node **after)
{
	t_stack_node	*tmp;

	if (!*before)
		return ;
	tmp = (*before)->next;
	(*before)->next = *after;
	(*after)->prev = *before;
	*after = *before;
	*before = tmp;
	(*before)->prev = NULL;
}

void	rotate_to_last(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*tmp;

	if (!*head)
		return ;
	if (!(*head)->next)
		return ;
	first = *head;
	tmp = *head;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = tmp;
}

void	rotate_both(t_stack_node **head_a, t_stack_node **head_b)
{
	rotate_to_last(&(*head_a));
	rotate_to_last(&(*head_b));
}

void	rev_rotate(t_stack_node **head)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!*head)
		return ;
	tmp = *head;
	last = *head;
	while (1)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			break;
		last = last->next;
	}
	tmp->next = *head;
	tmp->prev = NULL;
	last->next = NULL;
	(*head)->prev = tmp;
	*head = tmp;
}

void	rev_rotate_both(t_stack_node **head_a, t_stack_node **head_b)
{
	rev_rotate(&(*head_a));
	rev_rotate(&(*head_b));
}
t_stack_node	*assign_list(int *tab, int size)
{
	t_stack_node	*list;
	t_stack_node 	*temp;
	t_stack_node	*prev_temp;
	int 			i;
	
	i = 1;
	list = new_node(tab[0]);
	if (!list)
		return (NULL);
	temp = list;
	while (i < size)
	{
		temp->next = new_node(tab[i]);
		if (!temp->next)
			return (NULL);
		prev_temp = temp;
		temp = temp->next;
		temp->prev = prev_temp;
		i++;
	}
	return (list);
}

int main(int ac, char **av)
{
	int 	num[] = {1, 2, 3, 4};
	int		numm[] ={5, 6, 7, 8};
	t_stack_node	*head_a = assign_list(num, 4);
	t_stack_node	*head_b = assign_list(numm, 4);
	//print_list(head_a);
	//print_list(head_b);
	//swap_first(&head_a);	
	//swap_both(&head_a, &head_b);
	//push_first(&head_a, &head_b);
	//rotate_to_last(&head_a);
	// rev_rotate(&head_a);
	// head_a = head_a->next;
	// head_a = head_a->next;
	// head_a = head_a->next;
	// head_a = head_a->next;
	// head_a = head_a->prev;
	// head_a = head_a->prev;
	// head_a = head_a->prev;

	printf("%d\n", head_a->content);
	//rotate_both(&head_a, &head_b);
	//rev_rotate_both(&head_a, &head_b);
	//print_list(head_a);
	//print_list(head_b);
	return (0);
}