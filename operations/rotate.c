/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:30:44 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/14 17:42:58 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate_stack(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !(*stack)->next)
		return (0);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	return (1);
}

int	ra(t_list **a, t_op_counter *ops)
{
	(void)ops;
	if (!rotate_stack(a))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_list **b, t_op_counter *ops)
{
	(void)ops;
	if (!rotate_stack(b))
		return (0);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_list **a, t_list **b, t_op_counter *ops)
{
	int	did_something;

	(void)ops;
	did_something = 0;
	if (rotate_stack(a))
		did_something = 1;
	if (rotate_stack(b))
		did_something = 1;
	if (did_something)
		write(1, "rr\n", 3);
	return (did_something);
}
