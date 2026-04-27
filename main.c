/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:23 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:23 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}

int is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
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

int	check_duplicates(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*runner;

	current = a;
	while (current)
	{	
		runner = current->next;
		while (runner)
		{
			if (runner->value == current->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	char *args;
	char *tmp;
	int i;

	a = NULL;
	b = NULL;
	args = NULL;
	i = 1;
	if (argc < 2)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	while (i < argc)
	{
		if (!args)
			args = ft_strjoin("",argv[i]);
		else
		{
			tmp = ft_strjoin(args, " ");
			free(args);
			args = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
		i++;
	}
	stack_init(&a, args);
	if (check_duplicates(a) == 1)
	{
		error_free(&a);
		return (1);
	}
	if (!a)
{
    free(args);
    write(2, "Error\n", 6);
    return (1);
}
	if (stack_sorted(a) == 1)
		push_swap(&a, &b);
	free(args);
	free_stack(&a);
}
