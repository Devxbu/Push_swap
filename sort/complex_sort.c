/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:01:02 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/10 16:26:54 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	complex_sort(t_list **a, int size)
{
	int		i;
	int		bit_amount;
	t_list	*b;

	b = NULL;
	bit_amount = 0;
	while ((1 << bit_amount) < size)
	{
		i = 0;
		while (i++ < size)
		{
			if (((*a)->content >> bit_amount) & 1)
				ra(a);
			else
				pb(a, &b);
		}
		while (b)
			pa(a, &b);
		bit_amount++;
	}
}
