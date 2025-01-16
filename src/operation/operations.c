/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:47:36 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/16 15:53:17 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	printf("-------------------------------------\n");
	while (head != NULL)
	{
		// printf("|| content %d || index %d || cost %d || target %d\n",head->content, head->index, head->cost, head->target->content);
		// printf("Median: %s\n", head->cheapest ? "true" : "false");
		printf("%d\n", head->content);
		head = head->next;
	}
}

void	print_list_prev(t_stack_node *head)
{
	printf("-------------------------------------\n");
	head = ft_lstlast(head);
	while (head != NULL)
	{
		printf("|| content %d || index %d || cost %d || target %d\n",head->content, head->index, head->cost, head->target->content);
		printf("Median: %s\n", head->cheapest ? "true" : "false");
		//printf("%d\n", head->content);
		head = head->prev;
	}
}

void	free_list(t_stack_node *list)
{
	t_stack_node	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_stack_node	*fill_list(char **strs)
{
	int				i;
	int				number;
	t_stack_node	*tmp;
	t_stack_node	*list;

	i = 1;
	list = new_node(ft_atol(strs[0]));
	if (!list)
		return (NULL);
	while (strs[i] != NULL)
	{
		number = ft_atoi(strs[i]);
		tmp = new_node(number);
		if (!tmp)
		{
			free(list);
			return (NULL);
		}
		ft_lstadd_back(&list, tmp);
		i++;
	}
	return (list);
}

int main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	//char			*strs[] = {"7", "1", "4", "3", "8", "33", "12", "17", NULL};
	char			*strs[] = {"11", "5", "4", "3", "8", NULL};
	char			*strs[] = {"7", "1", "4", NULL};
	//char			**strss;
	init_stacks(&stack_a, &stack_b);
	stack_a = fill_list(strs);
	if (!stack_a )
		return (0);
	sort_stack(&stack_a, &stack_b);
	//print_list(stack_a);
	//print_list(stack_b);
	//print_list_prev(stack_a);
	//print_list(stack_b);
	// printf("%d\n", stack_a->content);
	// stack_a = stack_a->next;
	// printf("%d\n", stack_a->content);
	// stack_a = stack_a->next;
	// printf("%d\n", stack_a->content);
	// stack_a = stack_a->next;
	// printf("b--%d\n", stack_b->content);
	return (0);
}

// int main(int ac, char **av)
// {
// 	//int 			num[] = {1, 2, 3, 4};
// 	//int				numm[] ={5, 6, 7, 8};
// 	t_stack_node	*stack_a;
// 	char			*strs[] = {"11", "15", "10", NULL};
// 	stack_a = fill_list(strs);
// 	if (!stack_a)
// 		return (0);
// 	printf("--%d--\n", is_sorted(stack_a));
// 	return (0);
// 	//print_list(head_a);
// 	//print_list(head_b);
// 	//swap_first(&head_a);	
// 	//swap_both(&head_a, &head_b);
// 	//push_first(&head_a, &head_b);
// 	//rotate_to_last(&head_a);
// 	// rev_rotate(&head_a);
// 	// head_a = head_a->prev;
// 	//printf("%d\n", stack_a->content);
// 	//rotate_both(&head_a, &head_b);
// 	//rev_rotate_both(&head_a, &head_b);
// 	//print_list(head_a);
// 	//print_list(head_b);
// 	t_stack_node *test1;
// 	t_stack_node *test2;
// 	test1 = malloc(sizeof(t_stack_node));
// 	test2 = test1;
// 	free(test1);
// 	free_list(stack_a);
// 	return (0);
// }