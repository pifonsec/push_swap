/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:33 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:33 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int	i;
    
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void    push_swap(t_stack_node **a, t_stack_node **b)
{
    if (stack_size(*a) <= 5)
        sort_small(a, b);
	else
		radix_sort(a, b);
}