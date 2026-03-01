/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:00:56 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/28 12:08:50 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_list **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->content;
	mid = (*a)->next->content;
	bot = (*a)->next->next->content;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

static int	find_minimum_pos(t_list *a)
{
	int	pos;
	int	min_pos;
	int	min;

	pos = 0;
	min_pos = 0;
	min = a->content;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			min_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (min_pos);
}

static void	bring_to_top(t_list **a, int position, int size)
{
	if (position <= size / 2)
	{
		while (position-- > 0)
			ra(a);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rra(a);
	}
}

static void	sort_small(t_list **a, t_list **b, int size)
{
	int	to_push;
	int	current_size;
	int	i;

	to_push = size - 3;
	current_size = size;
	i = 0;
	while (i < to_push)
	{
		bring_to_top(a, find_minimum_pos(*a), current_size);
		pb(a, b);
		current_size--;
		i++;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	simple_sort(t_list **a, int size)
{
	t_list	*b;

	b = NULL;
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else
		sort_small(a, &b, size);
}
