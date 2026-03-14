/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:38:11 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/14 15:14:48 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bring_to_top_b(t_list **b, int position, int size, t_op_counter *ops)
{
	if (position <= size / 2)
	{
		while (position-- > 0)
		{
			rb(b, ops);
			ops->rb_counter++;
		}
	}
	else
	{
		position = size - position;
		while (position-- > 0)
		{
			rrb(b, ops);
			ops->rrb_counter++;
		}
	}
}

void	medium_move_one(t_list **a, t_list **b, t_op_counter *ops)
{
	pb(a, b, ops);
	ops->pb_counter++;
}

void	medium_move_two(t_list **a, t_op_counter *ops)
{
	ra(a, ops);
	ops->ra_counter++;
}
