/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:29 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:29 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack_node **stack)
{
    t_stack_node    *tmp;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

void swap_a(t_stack_node **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void swap_b(t_stack_node **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void swap_both(t_stack_node **a, t_stack_node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void push_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *tmp;

    if(!*b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    write(1, "pa\n", 3);
}

void push_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *tmp;

    if(!*a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    write(1, "pb\n", 3);
}

static void rotate(t_stack_node **stack)
{
    t_stack_node *first;
    t_stack_node *last;

    if (!*stack || !(*stack)->next)
        return ;
    first = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void rotate_a(t_stack_node **a)
{
    rotate(a);
    write (1, "ra\n", 3);
}

void rotate_b(t_stack_node **b)
{
    rotate(b);
    write (1, "rb\n", 3);
}

void rotate_both(t_stack_node **a, t_stack_node **b)
{
    rotate(a);
    rotate(b);
    write (1, "rr\n", 3);
}

static void reverse_rotate(t_stack_node **stack)
{
    t_stack_node *prev;
    t_stack_node *last;

    if (!*stack || !(*stack)->next)
        return;

    prev = NULL;
    last = *stack;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

void reverse_rotate_a(t_stack_node **a)
{
    reverse_rotate(a);
    write (1, "rra\n", 4);
}

void reverse_rotate_b(t_stack_node **b)
{
    reverse_rotate(b);
    write (1, "rrb\n", 4);
}

void reverse_rotate_both(t_stack_node **a, t_stack_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}