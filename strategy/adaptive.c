/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:47 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 00:00:00 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_sort(t_list **a, int size, t_op_counter *ops)
{
	double	disorder;

	disorder = compute_disorder(*a, size);
	if (disorder < 0.2)
	{
		ops->chosen_mode = SIMPLE;
		simple_sort(a, size, ops);
	}
	else if (disorder < 0.5)
	{
		ops->chosen_mode = MEDIUM;
		medium_sort(a, size, ops);
	}
	else
	{
		ops->chosen_mode = COMPLEX;
		complex_sort(a, size, ops);
	}
}
