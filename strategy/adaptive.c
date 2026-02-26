/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:47 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/26 19:31:48 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_sort(t_list **a, int size)
{
	double	disorder;

	if (size <= 5)
	{
		simple_sort(a, size);
		return ;
	}
	disorder = compute_disorder(*a, size);
	if (size <= 100)
	{
		if (disorder < 0.15)
			simple_sort(a, size);
		else
			medium_sort(a, size);
	}
	else
	{
		if (disorder < 0.10)
			medium_sort(a, size);
		else
			complex_sort(a, size);
	}
}
