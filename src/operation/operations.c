/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:47:36 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/21 12:38:32 by mdodevsk         ###   ########.fr       */
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
	printf("\n");
	while (head != NULL)
	{
		
		// printf("|| content %d || index %d || mediane %d || cost %d || target %d\n",head->content, head->index, head->median, head->cost, head->target->content);
		// printf("Median: %s\n", head->cheapest ? "true" : "false");
		printf("%d\n", head->content);
		head = head->next;
	}
}

void	print_list_all(t_stack_node *head)
{
	while (head != NULL)
	{
		printf("\n Noeu : %d Indice : %d\n", head->content, head->target->content);
		//printf("%d\n", head->content);
		head = head->next;
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
	char			*strs[] = {"5", "1", "4", "3", "8", "2", "7", "9", NULL};
	//char			*strs[] = {"19", "9", "4", "3", "8", NULL};
	//char			*strss[] = {"7", "12", "34", "17", "457", "43", NULL};
	//char			*strss[] = {"7", "11", "12", "34", "17", "457", "43", NULL};
	//char			**strss;

// char *strs[] = {
//     "902", "554", "666", "555", "48", "77", "539", "945", "187", "805",
//     "171", "13", "696", "910", "759", "646", "464", "837", "773", "265",
//     "374", "105", "581", "504", "397", "52", "538", "460", "637", "935",
//     "197", "455", "893", "235", "391", "498", "536", "145", "225", "638",
//     "762", "523", "982", "492", "900", "281", "972", "933", "488", "85",
//     "830", "999", "632", "678", "433", "324", "932", "734", "620", "732",
//     "206", "766", "909", "629", "122", "692", "742", "260", "149", "791",
//     "862", "989", "969", "144", "757", "509", "193", "855", "557", "334",
//     "968", "996", "688", "681", "912", "257", "655", "534", "979", "203",
//     "365", "458", "512", "931", "395", "558", "611", "870", "683", "93",
//     "478", "72", "431", "255", "384", "566", "926", "522", "888", "468",
//     "445", "520", "480", "744", "310", "959", "83", "647", "233", "853",
//     "527", "487", "301", "526", "941", "109", "858", "992", "694", "674",
//     "753", "229", "403", "308", "36", "400", "462", "23", "111", "312",
//     "84", "476", "399", "833", "641", "140", "490", "130", "406", "117",
//     NULL
// };


	init_stacks(&stack_a, &stack_b);
	
	stack_a = fill_list(strs);
	//stack_b = fill_list(strss);
	
	sort_stack(&stack_a, &stack_b);
	//print_list_all(stack_b);
	
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////TEST PUSH TO B//////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	
	printf("\nSTACK A\n");
	print_list(stack_a);
	
	printf("\nSTACK B\n");
	print_list(stack_b);
	
	// printf("\n-------------------------------------\n");
	// print_list_all(stack_a);
	
	// push_to_b(&stack_a, &stack_b);
	
	// printf("\n-------------------------------------\n");
	// printf("\nSTACK A\n");
	// print_list(stack_a);
	// printf("\nSTACK B\n");
	// print_list(stack_b);
	// init_values(stack_a, stack_b);
	// print_list_all(stack_a);
	// push_to_b(&stack_a, &stack_b);

	// init_values(stack_a, stack_b);
	// push_to_b(&stack_a, &stack_b);

	// init_values(stack_a, stack_b);
	// push_to_b(&stack_a, &stack_b);
	// init_values(stack_a, stack_b);
	// push_to_b(&stack_a, &stack_b);
	// init_values(stack_a, stack_b);
	// push_to_b(&stack_a, &stack_b);
	// init_values(stack_a, stack_b);
	// push_to_b(&stack_a, &stack_b);
	// init_values(stack_a, stack_b);
	// push_to_b(&stack_a, &stack_b);
	// init_values(stack_a, stack_b);
	// push_to_b(&stack_a, &stack_b);
	// init_values(stack_a, stack_b);
	// push_to_b(&stack_a, &stack_b);	
	// sort_three(&stack_a);
	
	// printf("\n-------------------------------------\n");
	// printf("\nSTACK A\n");
	// print_list(stack_a);
	
	// printf("\nSTACK B\n");
	// print_list(stack_b);
	
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////





	
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