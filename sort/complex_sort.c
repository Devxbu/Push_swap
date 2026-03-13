/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:01:02 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 13:55:35 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix_pass(t_list **a, t_list **b, int size, t_op_counter *ops)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (!(*a))
			break ;
		if (((*a)->content >> ops->bit_pass) & 1)
		{
			ra(a, ops);
			ops->ra_counter++;
		}
		else
		{
			pb(a, b, ops);
			ops->pb_counter++;
		}
	}
	while (*b)
	{
		pa(a, b, ops);
		ops->pa_counter++;
	}
}

void	complex_sort(t_list **a, int size, t_op_counter *ops)
{
	t_list	*b;

	if (size <= 1 || is_sorted(*a))
		return ;
	if (size <= 6)
	{
		simple_sort(a, size, ops);
		return ;
	}
	b = NULL;
	ops->bit_pass = 0;
	while ((1 << ops->bit_pass) < size)
	{
		radix_pass(a, &b, size, ops);
		ops->bit_pass++;
	}
	ops->bit_pass = 0;
}
