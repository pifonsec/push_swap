#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*prev;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
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

void	reverse_rotate_a(t_stack_node **a)
{
	reverse_rotate(a);
	write (1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack_node **b)
{
	reverse_rotate(b);
	write (1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}