/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42Angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:10:40 by pifonsec          #+#    #+#             */
/*   Updated: 2026/03/04 09:10:40 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack_node
{
    int value;
    int index;
  
    struct s_stack_node *next;
}               t_stack_node;

int	check_duplicates(t_stack_node *a);
int	error_syntax(char *str_nbr);
int	error_repetition(t_stack_node *a, int nbr);
int	stack_size(t_stack_node *stack);
long ft_atol(char *str);
void stack_init(t_stack_node **a, char *args);
void    free_matrix(char **matrix);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **a);
void    sort_three (t_stack_node **a);
void    sort_four (t_stack_node **a, t_stack_node **b);
void    sort_five (t_stack_node **a, t_stack_node **b);
void swap_a(t_stack_node **a);
void swap_b(t_stack_node **b);
void swap_both(t_stack_node **a, t_stack_node **b);
void push_a(t_stack_node **a, t_stack_node **b);
void push_b(t_stack_node **a, t_stack_node **b);
void rotate_a(t_stack_node **a);
void rotate_b(t_stack_node **b);
void rotate_both(t_stack_node **a, t_stack_node **b);
void reverse_rotate_a(t_stack_node **a);
void reverse_rotate_b(t_stack_node **b);
void reverse_rotate_both(t_stack_node **a, t_stack_node **b);
void    push_swap(t_stack_node **a, t_stack_node **b);
void	sort_small(t_stack_node **a,  t_stack_node **b);
void    radix_sort(t_stack_node **a, t_stack_node **b);

#endif