/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:47 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/12 23:10:58 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_sort(t_list **a, int size, t_op_counter *ops)
{
	double	disorder;

	if (size <= 5)
	{
		simple_sort(a, size, ops);
		return ;
	}
	disorder = compute_disorder(*a, size);
	if (size <= 100)
	{
		if (disorder < 0.15)
			simple_sort(a, size, ops);
		else
			medium_sort(a, size, ops);
	}
	else
	{
		if (disorder < 0.10)
			medium_sort(a, size, ops);
		else
			complex_sort(a, size, ops);
	}
}
