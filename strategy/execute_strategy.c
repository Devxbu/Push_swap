/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:53 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/26 19:31:53 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_strategy(t_mode mode, t_list **a, int size)
{
	if (mode == SIMPLE)
		simple_sort(a, size);
	else if (mode == MEDIUM)
		medium_sort(a, size);
	else if (mode == COMPLEX)
		complex_sort(a, size);
	else if (mode == ADAPTIVE)
		adaptive_sort(a, size);
}
