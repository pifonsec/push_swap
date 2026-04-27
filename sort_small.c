/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:48 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:48 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	if (stack_size(*a) == 3)
		sort_three(a);	
	else if (stack_size(*a) == 4)
		sort_four(a, b);
	else if (stack_size(*a) == 5)
		sort_five(a, b);
}

void    sort_three (t_stack_node **a)
{
    int first;
	int second;
	int third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
    if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
}

void    sort_four (t_stack_node **a, t_stack_node **b)
{
    while ((*a)->index != 1)
        rotate_a(a);
    push_b(a, b);
    sort_three(a);
    push_a(a, b);
}

void    sort_five (t_stack_node **a, t_stack_node **b)
{
    while (stack_size(*a) > 3)
    {
        if ((*a)->index == 1 || (*a)->index == 2)
            push_b(a, b);
        else
            rotate_a(a);
    }
    sort_three(a);
    if ((*b)->index < (*b)->next->index)
        swap_b(b);
    push_a(a, b);
    push_a(a, b);
}
