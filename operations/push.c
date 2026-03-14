/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:30:29 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/14 17:42:39 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_list **a, t_list **b, t_op_counter *ops)
{
	t_list	*temp;

	if (!(*b))
		return (0);
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	(void)ops;
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_list **a, t_list **b, t_op_counter *ops)
{
	t_list	*temp;

	(void)ops;
	if (!(*a))
		return (0);
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
	return (1);
}
