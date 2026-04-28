/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:45 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:45 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack_node *a)
{
	int	max_index;
	int	bits;

	max_index = 0;
	bits = 0;
	while (a)
	{
		if (a->index > max_index)
			max_index = a->index;
		a = a->next;
	}
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	current_size;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		current_size = stack_size(*a);
		while (j < current_size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}
