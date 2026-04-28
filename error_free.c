/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:17 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:17 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

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

void	error_free(t_stack_node **a, char *args)
{
	free_stack(a);
	free(args);
	write (2, "Error\n", 6);
	exit (1);
}

int	error_syntax(char *str_nbr)
{
	int	i;

	i = 0;
	if (!str_nbr)
		return (1);
	if (str_nbr[i] == '+' || str_nbr[i] == '-')
	{
		if (!str_nbr[i + 1])
			return (1);
		i++;
	}
	while (str_nbr[i])
	{
		if (str_nbr[i] < '0' || str_nbr[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
