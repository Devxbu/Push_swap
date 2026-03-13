/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:32:37 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 12:24:23 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_one(t_list **a, t_op_counter *ops)
{
	sa(a, ops);
	ops->sa_counter++;
}

void	move_two(t_list **a, t_op_counter *ops)
{
	sa(a, ops);
	ops->sa_counter++;
	rra(a, ops);
	ops->rra_counter++;
}

void	move_three(t_list **a, t_op_counter *ops)
{
	ra(a, ops);
	ops->ra_counter++;
}

void	move_four(t_list **a, t_op_counter *ops)
{
	sa(a, ops);
	ops->sa_counter++;
	ra(a, ops);
	ops->ra_counter++;
}

void	move_five(t_list **a, t_op_counter *ops)
{
	rra(a, ops);
	ops->rra_counter++;
}
