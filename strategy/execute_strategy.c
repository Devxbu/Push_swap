/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:53 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/12 23:10:02 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_strategy(t_mode mode, t_list **a, int size, t_op_counter *ops)
{
	ops->chosen_mode = mode;
	if (mode == SIMPLE)
		simple_sort(a, size, ops);
	else if (mode == MEDIUM)
		medium_sort(a, size, ops);
	else if (mode == COMPLEX)
		complex_sort(a, size, ops);
	else if (mode == ADAPTIVE)
		adaptive_sort(a, size, ops);
}