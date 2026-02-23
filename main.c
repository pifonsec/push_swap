#include "push_swap.h"
#include <stdio.h>

int	stack_sorted(t_stack_node *a)
{
	int boolean;

	boolean = 1;
	return (boolean);
}

int is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
			i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *values, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while(j < count)
		{
			if (values[i] == values[j])
				return (0);
			j++;
		}
	i++;
	}
	return (1);
}

void	print_tab(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("taille = %d\n", i); 
}

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char **args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	print_tab(args);

	stack_init(&a, args);
	// if (stack_sorted(a) == 0)
	// {
	// 	printf("Je trie la, dep");
	// 	//push_swap(&a, &b);
	// }
	// free_stack(&a);
}
