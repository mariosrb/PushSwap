#include "push_swap.h"

void	get_bit(int n)
{
	int i = 5;
	int bit;
	while (i >= 0)
	{
		bit = (n >> i) & 1;
		printf("%d", bit);
		i--;
	}
}
int	extract_bit(int n, int pos)
{
	return ((n >> pos) & 1);
}

int count_bits(int n)
{
	int i = 0;
	int compteur = 0;
	while (n > 0)
	{
		compteur++;
		//printf("%d\n", n);
		n = n >> 1;
	}
	//printf("%d\n", compteur);
	return (compteur);
}

t_list	*new_noode(int n)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = n;
	new->next = NULL;
	return (new);
}

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		printf("la valeur est %d\n", head->content);
		head = head->next;
	}
}
// Swap les deux premiers
void	swap_first(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*head)
		return ;
	tmp = *head;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp2->next = *head;
	*head = tmp2;
}
void	swap_both(t_list **head_a, t_list **head_b)
{
	swap_first(&(*head_a));
	swap_first(&(*head_b));
}

// Push le premier dans le deuxieme
void	push_first(t_list **before, t_list **after)
{
	t_list	*tmp;

	if (!*before)
		return ;
	tmp = (*before)->next;
	(*before)->next = *after;
	*after = *before;
	*before = tmp;
}

// Envoie le premier a la fin 
void	rotate_to_last(t_list **head)
{
	t_list	*first;
	t_list	*tmp;

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
	first->next = NULL;

}

void	rotate_both(t_list **head_a, t_list **head_b)
{
	rotate_to_last(&(*head_a));
	rotate_to_last(&(*head_b));
}

void	reverse_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

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
	last->next = NULL;
	*head = tmp;
}

void	reverse_rotate_both(t_list **head_a, t_list **head_b)
{
	reverse_rotate(&(*head_a));
	reverse_rotate(&(*head_b));
}

int main(int ac, char **av)
{
	int 	num = 1;
	int		numm = 11;
	t_list	*head_a = new_noode(num);
	t_list	*head_b = new_noode(numm);
	t_list	*tmp = head_a;
	t_list	*tmpp = head_b;

	while (num != 5)
	{
		tmp->next = new_noode(++num);
		tmp = tmp->next;
	}
	while (numm != 15)
	{
		tmpp->next = new_noode(++numm);
		tmpp = tmpp->next;
	}
	print_list(head_a);
	//print_list(head_b);
	//swap_first(&head_a);	
	//swap_both(&head_a, &head_b);
	//push_first(&head_a, &head_b);
	//rotate_to_last(&head_a);
	//rotate_both(&head_a, &head_b);
	reverse_rotate_both(&head_a, &head_b);
	print_list(head_a);
	print_list(head_b);
	return (0);
}