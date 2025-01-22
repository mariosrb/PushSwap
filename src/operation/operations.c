/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:47:36 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/01/22 14:18:23 by mdodevsk         ###   ########.fr       */
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

// int main(int ac, char **av)
// {
// 	t_stack_node	*stack_a;
// 	t_stack_node	*stack_b;
	//char			*strs[] = {"5", "1", "4", "3", "8", "2", "7", "9", NULL};
	//char			*strs[] = {"19", "9", "4", "3", "8", NULL};
	//char			*strss[] = {"7", "12", "34", "17", "457", "43", NULL};
	//char			*strss[] = {"7", "11", "12", "34", "17", "457", "43", NULL};
	//char			**strss;

// char *strs[] = {
//     "371", "475", "14", "18", "286", "89", "639", "172", "1", "576",
//     "848", "74", "956", "745", "348", "696", "511", "146", "661", "892",
//     "671", "869", "929", "516", "71", "102", "992", "114", "162", "60",
//     "356", "609", "64", "767", "397", "739", "413", "1000", "225", "709",
//     "903", "56", "3", "292", "630", "751", "963", "545", "217", "521",
//     "908", "902", "321", "817", "367", "70", "644", "6", "623", "171",
//     "224", "608", "349", "497", "961", "160", "910", "851", "420", "524",
//     "620", "500", "313", "13", "311", "208", "755", "484", "493", "28",
//     "139", "704", "776", "919", "849", "303", "402", "857", "446", "492",
//     "810", "259", "253", "632", "634", "481", "610", "896", "642", "52",
//     "65", "871", "674", "926", "735", "779", "626", "274", "418", "339",
//     "99", "220", "893", "793", "317", "494", "318", "451", "923", "284",
//     "551", "57", "29", "309", "322", "419", "954", "144", "571", "643",
//     "555", "42", "993", "109", "124", "331", "186", "228", "411", "37",
//     "837", "119", "676", "354", "685", "930", "938", "328", "839", "981",
//     "72", "207", "753", "628", "884", "806", "775", "381", "664", "299",
//     "588", "811", "422", "868", "61", "126", "441", "933", "209", "746",
//     "777", "863", "12", "691", "7", "357", "245", "404", "585", "457",
//     "238", "829", "155", "147", "654", "153", "948", "682", "607", "383",
//     "337", "433", "373", "988", "589", "536", "469", "399", "188", "946",
//     "792", "431", "856", "400", "20", "711", "199", "455", "91", "677",
//     "999", "33", "88", "77", "825", "496", "426", "212", "252", "621",
//     "73", "251", "442", "972", "25", "388", "395", "821", "668", "699",
//     "717", "351", "121", "185", "706", "778", "227", "701", "600", "707",
//     "798", "879", "888", "725", "53", "180", "58", "703", "877", "758",
//     "200", "647", "211", "627", "886", "149", "866", "503", "890", "382",
//     "561", "826", "985", "254", "90", "756", "898", "75", "269", "942",
//     "964", "858", "916", "92", "501", "336", "466", "505", "953", "769",
//     "872", "940", "631", "853", "852", "108", "290", "615", "302", "570",
//     "178", "977", "665", "915", "107", "556", "759", "813", "333", "0",
//     "405", "218", "655", "343", "820", "287", "850", "595", "189", "667",
//     "697", "765", "36", "113", "444", "646", "327", "520", "306", "689",
//     "859", "326", "722", "440", "514", "152", "860", "624", "490", "135",
//     "229", "822", "861", "424", "132", "918", "770", "452", "195", "401",
//     "329", "527", "434", "398", "737", "448", "255", "445", "443", "901",
//     "358", "54", "612", "941", "913", "812", "712", "909", "635", "39",
//     "590", "602", "347", "976", "747", "683", "649", "525", "550", "87",
//     "261", "979", "838", "262", "530", "194", "239", "560", "548", "552",
//     "242", "513", "477", "583", "335", "2", "270", "515", "843", "376",
//     "361", "363", "15", "163", "115", "973", "841", "486", "295", "359",
//     "425", "27", "158", "485", "174", "5", "94", "230", "692", "283",
//     "591", "156", "76", "968", "49", "730", "945", "379", "288", "315",
//     "862", "553", "845", "66", "428", "887", "169", "672", "461", "213",
//     "587", "996", "183", "950", "81", "372", "673", "26", "614", "173",
//     "281", "97", "771", "203", "937", "222", "905", "904", "320", "880",
//     "384", "846", "582", "960", "864", "613", "638", "38", "787", "134",
//     "127", "210", "93", "640", "456", "323", "662", "967", "925", "157",
//     "800", "449", "899", "906", "122", "579", "118", "40", "761", "294",
//     "403", "45", "350", "68", "345", "518", "772", "362", "586", "48",
//     "997", "743", "105", "353", "815", "572", "784", "280", "231", "900",
//     NULL
// };

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
//     NULL
// };



	// init_stacks(&stack_a, &stack_b);
	
	// stack_a = fill_list(strs);
	//stack_b = fill_list(strss);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	//pa(&stack_a, &stack_b);
	// sort_stack(&stack_a, &stack_b);
	//print_list_all(stack_b);
	
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////TEST PUSH TO B//////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	
	// printf("\nSTACK A\n");
	// print_list(stack_a);
	
	// printf("\nSTACK B\n");
	// print_list(stack_b);
	
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
	
// 	return (0);
// }

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