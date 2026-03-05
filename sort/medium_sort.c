/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:00:59 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/04 18:35:49 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	mposition_finder(t_list *a)
{
	int	pos;
	int	tmp_max_value;
	int	tmp_max_node;

	pos = 0;
	tmp_max_value = 0;
	tmp_max_node = a->content;
	while (a)
	{
		if (a->content > tmp_max_node)
		{
			tmp_max_node = a->content;
			tmp_max_value = pos;
		}
		a = a->next;
		pos++;
	}
	return (tmp_max_value);
}

static int	square(int size)
{
	int	i;

	i = 0;
	while (i * i <= size)
		i++;
	return (i - 1);
}

static void	chunk_psh(t_list **a, t_list **b, int size)
{
	int	chunk_size;
	int	chunk_num;
	int	chunk_min;
	int	current_size;
	int	i;

	chunk_size = square(size);
	chunk_num = 0;
	while (*a)
	{
		i = 0;
		chunk_min = chunk_num * chunk_size;
		current_size = ft_lstsize(*a);
		while (i++ < current_size)
		{
			if ((*a)->content >= chunk_min && (*a)->content < chunk_min
				+ chunk_size)
				pb(a, b);
			else
				ra(a);
		}
		chunk_num++;
	}
}

static void	chunk_pll(t_list **a, t_list **b)
{
	int	mposition;
	int	size_b;

	while (*b)
	{
		mposition = mposition_finder(*b);
		size_b = ft_lstsize(*b);
		bring_to_top_b(b, mposition, size_b);
		pa(a, b);
	}
}

void	medium_sort(t_list **a, int size)
{
	t_list	*b;

	b = NULL;
	if (size <= 1 || is_sorted(*a))
		return ;
	else if (size <= 6)
	{
		simple_sort(a, size);
		return ;
	}
	else
	{
		chunk_psh(a, &b, size);
		chunk_pll(a, &b);
	}
}
