#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
    t_stack_node *tmp;
    t_stack_node *current;

    if (stack == NULL)
        return ;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void	error_free(t_stack_node **a, char **argv)
{
    free_stack(a);
    write (2, "Error\n", 6);
    exit (1);
}

int	error_syntax(char *str_nbr)
{
    int i;

    i = 0;
    if (str_nbr[i] != '+' 
            && str_nbr[i] != '-'
            && (str_nbr[i] < '0' || str_nbr[i] > '9'))
    {
        printf("a");
        return (1);
    }
    if (str_nbr[i] == '+' || str_nbr[i] == '-'
        && (str_nbr[i + 1] >= '0' && str_nbr[i + 1] <= '9'))
        {
            printf("b");
            return (1);
        }
    while (str_nbr[i])
    {
        if (str_nbr[i] < '0' && str_nbr[i] > '9')
        {
            printf("c");
            return (1);
        }
        i++;
    }
    return (0);
}

int	error_repetition(t_stack_node *a, int nbr)
{
    if (a == NULL)
        return (0);
    while (a)
    {
        if (a->value == nbr)
            return (1);
        a = a->next;
    }
    return (0);
}
