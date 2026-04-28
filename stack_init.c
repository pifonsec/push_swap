/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:52 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:52 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	valid_number(char *args, int *i, t_stack_node **a)
{
	long	nbr;
	int		sign;

	while (args[*i] == ' ' || args[*i] == '\t')
		(*i)++;
	sign = 1;
	if (args[*i] == '+' || args[*i] == '-')
	{
		if (args[*i] == '-')
			sign = -1;
		(*i)++;
		if (!(args[*i] >= '0' && args[*i] <= '9'))
			error_free(a, args);
	}
	if (!(args[*i] >= '0' && args[*i] <= '9'))
		error_free(a, args);
	nbr = 0;
	while (args[*i] >= '0' && args[*i] <= '9')
	{
		nbr = (nbr * 10) + (args[*i] - '0');
		(*i)++;
	}
	return (nbr * sign);
}

int	error_repetition(t_stack_node *a, int nbr)
{
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	assign_index(t_stack_node *stack)
{
	int				count;
	t_stack_node	*i_node;
	t_stack_node	*j_node;

	i_node = stack;
	while (i_node)
	{
		count = 0;
		j_node = stack;
		while (j_node)
		{
			if (j_node->value < i_node->value)
				count++;
			j_node = j_node->next;
		}
		i_node->index = count;
		i_node = i_node->next;
	}
}

void	stack_init(t_stack_node **a, char *args)
{
	long			nbr;
	int				i;
	t_stack_node	*new;
	t_stack_node	*tmp;

	i = 0;
	while (args[i])
	{
		while (args[i] == ' ' || args[i] == '\t')
			i++;
		if (!args[i])
			break ;
		nbr = valid_number(args, &i, a);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_free(a, args);
		new = malloc(sizeof(t_stack_node));
		if (!new)
			error_free(a, args);
		new->value = (int)nbr;
		new->next = NULL;
		if (!*a)
			*a = new;
		else
		{
			tmp = *a;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	assign_index(*a);
}
