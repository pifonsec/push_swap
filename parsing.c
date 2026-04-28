/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:05:36 by pifonsec          #+#    #+#             */
/*   Updated: 2026/04/28 12:50:17 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node *a)
{
	int	current;
	int	next;

	if (!a)
		return (-1);
	while (a->next)
	{
		current = a->value;
		next = a->next->value;
		if (current > next)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

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
	t_stack_node	*following;

	current = a;
	while (current)
	{
		following = current->next;
		while (following)
		{
			if (following->value == current->value)
				return (1);
			following = following->next;
		}
		current = current->next;
	}
	return (0);
}
