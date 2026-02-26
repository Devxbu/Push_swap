#include "../push_swap.h"

static void	swap_stack(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

int	sa(t_list **a)
{
	if (!(*a) || !(*a)->next)
		return (0);
	swap_stack(a);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_list **b)
{
	if (!(*b) || !(*b)->next)
		return (0);
	swap_stack(b);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_list **a, t_list **b)
{
	int	did_something;

	did_something = 0;
	if (*a && (*a)->next)
	{
		swap_stack(a);
		did_something = 1;
	}
	if (*b && (*b)->next)
	{
		swap_stack(b);
		did_something = 1;
	}
	if (did_something)
		write(1, "ss\n", 3);
	return (did_something);
}
