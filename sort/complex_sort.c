/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:01:02 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 03:29:14 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	complex_sort(t_list **a, int size, t_op_counter *ops)
{
	int		i;
	int		bit_amount;
	t_list	*b;

	b = NULL;
	bit_amount = 0;
	if (size <= 6)
	{
		simple_sort(a, size, ops);
		return ;
	}
	while ((1 << bit_amount) < size)
	{
		i = 0;
		while (i++ < size)
		{
			if (!(*a))
				break ;
			if (((*a)->content >> bit_amount) & 1)
			{
				ra(a, ops);
				ops->ra_counter++;
			}
			else
			{
				pb(a, &b, ops);
				ops->pb_counter++;
			}
		}
		while (b)
		{
			pa(a, &b, ops);
			ops->pa_counter++;
		}
		bit_amount++;
	}
}
