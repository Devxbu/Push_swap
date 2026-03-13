/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:00:56 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 12:23:18 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_list **a, t_op_counter *ops)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->content;
	two = (*a)->next->content;
	three = (*a)->next->next->content;
	if (one > two && two < three && one < three)
		move_one(a, ops);
	else if (one > two && two > three)
		move_two(a, ops);
	else if (one > two && one > three)
		move_three(a, ops);
	else if (one < two && two > three && one < three)
		move_four(a, ops);
	else if (one < two && two > three)
		move_five(a, ops);
}

static int	find_min_position(t_list *a)
{
	int	pos;
	int	tmp_min_value;
	int	tmp_min_node;

	pos = 0;
	tmp_min_value = 0;
	tmp_min_node = a->content;
	while (a)
	{
		if (a->content < tmp_min_node)
		{
			tmp_min_node = a->content;
			tmp_min_value = pos;
		}
		a = a->next;
		pos++;
	}
	return (tmp_min_value);
}

static void	bring_to_top(t_list **a, int position, int size, t_op_counter *ops)
{
	if (position <= size / 2)
	{
		while (position-- > 0)
		{
			ra(a, ops);
			ops->ra_counter++;
		}
	}
	else
	{
		position = size - position;
		while (position-- > 0)
		{
			rra(a, ops);
			ops->rra_counter++;
		}
	}
}

static void	sort_small(t_list **a, t_list **b, int size, t_op_counter *ops)
{
	int	to_push;
	int	current_size;
	int	i;

	to_push = size - 3;
	current_size = size;
	i = 0;
	while (i < to_push)
	{
		bring_to_top(a, find_min_position(*a), current_size, ops);
		pb(a, b, ops);
		ops->pb_counter++;
		current_size--;
		i++;
	}
	sort_three(a, ops);
	while (*b)
	{
		pa(a, b, ops);
		ops->pa_counter++;
	}
}

void	simple_sort(t_list **a, int size, t_op_counter *ops)
{
	t_list	*b;

	b = NULL;
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->content > (*a)->next->content)
		{
			sa(a, ops);
			ops->sa_counter++;
		}
	}
	else if (size == 3)
		sort_three(a, ops);
	else
		sort_small(a, &b, size, ops);
}
