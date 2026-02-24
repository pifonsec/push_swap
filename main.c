#include "push_swap.h"
#include <stdio.h>

int	stack_sorted(t_stack_node *a)
{
	int current;
	int	next;

	if (!a)
		return (-1);
	while (a->next)
	{
		current = a->value;
		next = a->next->value;
		if (current > next)
			return(1);
		a = a->next;
	}
	printf("la stack est triee\n");
	return (0);
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

int	count_args(char **args)
{
	int	i = 0;

	while (args[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char **args;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || count_args(args) < 3)
		{
			write (2, "Error\n", 6);
			return(1);
		}
		stack_init(&a, args);
	}
	else
	{
		if (argc < 4)
		{
			write (2, "Error\n", 6);
			return(1);
		}
		stack_init(&a, &argv[1]);
	}	
	if (stack_sorted(a) == 1)
	{
		printf("Je trie la, dep\n");
		//push_swap(&a, &b);
	}
	// free_stack(&a);
}
