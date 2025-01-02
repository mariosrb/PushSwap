#include "push_swap.h"


int is_valid_number(char *str)
{
	int	i;
	i = 0;

	if (!str[i] || !str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int main()
{
    char *test_cases[] = {
        "42", "-42", "+42", "42a", "a42", "", " ", NULL
    };

    int i = 0;
    while (test_cases[i])
    {
        if (is_valid_number(test_cases[i]))
            printf("✅ '%s' est un nombre valide.\n", test_cases[i]);
        else
            printf("❌ '%s' n'est PAS un nombre valide.\n", test_cases[i]);
        i++;
    }

    return (0);
}