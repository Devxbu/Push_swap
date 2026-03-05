/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:38:11 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/03 20:40:42 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bring_to_top_b(t_list **b, int position, int size)
{
	if (position <= size / 2)
	{
		while (position-- > 0)
			rb(b);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rrb(b);
	}
}