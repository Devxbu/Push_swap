/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:30:51 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/14 17:35:56 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	sa(t_list **a, t_op_counter *ops)
{
	(void)ops;
	if (!(*a) || !(*a)->next)
		return (0);
	swap_stack(a);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_list **b, t_op_counter *ops)
{
	(void)ops;
	if (!(*b) || !(*b)->next)
		return (0);
	swap_stack(b);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_list **a, t_list **b, t_op_counter *ops)
{
	int	did_something;

	(void)ops;
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
