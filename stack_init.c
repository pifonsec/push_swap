#include "push_swap.h"

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

void stack_init(t_stack_node **a, char **argv)
{
    long nbr;
    int i;

    i = 0;
    while (argv[i])
    {
        printf("Je lance error_syntax....................\n");
        if (error_syntax(argv[i]) == 1)
        {
            printf("asd");
            error_free(a, argv);
        }
        nbr = ft_atol(argv[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            error_free(a, (char**)argv);
        if (error_repetition(*a, (int)nbr))
            error_free(a, (char**)argv);
        //append_node(a, (int)nbr);
        i++;
    }
}