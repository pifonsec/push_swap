#include "push_swap.h"

int fill_node(t_stack_node **a, char **args)
{
    int i;
    int nbr;
    t_stack_node *new_node;
    t_stack_node *tmp;

    i = 0;
    if  (!args)
        return (1);
    while(args[i])
    {
        nbr = ft_atol(args[i]);
        new_node = malloc(sizeof(t_stack_node));
        if(!new_node)
            return (1);
        new_node->value = (int)nbr;
        new_node->next = NULL;
        if (!*a)
            *a = new_node;
        else
        {
            tmp = *a;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new_node;
        }
        i++;
    }
    return (0);
}

long ft_atol(char *str)
{
    int i;
    long result;
	int	sign;

    i = 0;
    result = 0;
	sign = 1;

    while (str[i] && (str[i] == ' ' || str[i] == '\t'
            || str[i] == '\n' || str[i] == '\r'
            || str[i] == '\v' || str[i] == '\f'))
        i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
	result *= sign;
    return(result);
}

void stack_init(t_stack_node **a, char **args)
{
    long nbr;
    int i;

    i = 0;
    while (args[i])
    {
        if (error_syntax(args[i]) == 1)
            error_free(a, args);
        nbr = ft_atol(args[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            error_free(a, (char**)args);
        if (error_repetition(*a, (int)nbr) == 1)
            error_free(a, args);
        i++;
    }
    fill_node(a, args);
}