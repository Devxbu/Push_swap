/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:30:37 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/26 19:30:37 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	reverse_stack(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return (0);
	prev = *stack;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

int	rra(t_list **a)
{
	if (!reverse_stack(a))
		return (0);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_list **b)
{
	if (!reverse_stack(b))
		return (0);
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_list **a, t_list **b)
{
	int	did_something;

	did_something = 0;
	if (reverse_stack(a))
		did_something = 1;
	if (reverse_stack(b))
		did_something = 1;
	if (did_something)
		write(1, "rrr\n", 4);
	return (did_something);
}
