#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

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

void	rotate_a(t_stack_node **a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

void	rotate_b(t_stack_node **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

void	rotate_both(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}