/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:00:56 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/03 20:36:34 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_list **a)
{
	int	oneth;
	int	twoth;
	int	threeth;

	oneth = (*a)->content;
	twoth = (*a)->next->content;
	threeth = (*a)->next->next->content;
	if (oneth > twoth && twoth < threeth && oneth < threeth)
		sa(a);
	else if (oneth > twoth && twoth > threeth)
	{
		sa(a);
		rra(a);
	}
	else if (oneth > twoth && twoth < threeth && oneth > threeth)
		ra(a);
	else if (oneth < twoth && twoth > threeth && oneth < threeth)
	{
		sa(a);
		ra(a);
	}
	else if (oneth < twoth && twoth > threeth && oneth > threeth)
		rra(a);
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
		bring_to_top(a, find_min_position(*a), current_size);
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
