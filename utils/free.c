/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:32:05 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/12 23:09:35 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	free_all(int *nums, int *indexes, t_list *a)
{
	if (nums)
		free(nums);
	if (indexes)
		free(indexes);
	if (a)
		free_stack(a);
}

void	init_ops(t_op_counter *ops)
{
	ops->sa_counter = 0;
	ops->sb_counter = 0;
	ops->ss_counter = 0;
	ops->pa_counter = 0;
	ops->pb_counter = 0;
	ops->ra_counter = 0;
	ops->rb_counter = 0;
	ops->rr_counter = 0;
	ops->rra_counter = 0;
	ops->rrb_counter = 0;
	ops->rrr_counter = 0;
	ops->op_bool_control = 0;
	ops->chosen_mode = ADAPTIVE;
}