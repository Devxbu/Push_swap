/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:36:48 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 12:23:43 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	*bubble_sort(int size, int *arr)
{
	int	i;
	int	j;
	int	*sorted;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i++ < size)
		sorted[i - 1] = arr[i - 1];
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
				ft_swap(&sorted[j], &sorted[j + 1]);
			j++;
		}
		i++;
	}
	return (sorted);
}

int	*index_finder(int size, int *arr)
{
	int	*sorted;
	int	*index_arr;
	int	i;
	int	j;

	sorted = bubble_sort(size, arr);
	if (!sorted)
		return (NULL);
	index_arr = malloc(sizeof(int) * size);
	if (!index_arr)
		return (free(sorted), NULL);
	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (j++ < size)
		{
			if (arr[i - 1] == sorted[j - 1])
			{
				index_arr[i - 1] = j - 1;
				break ;
			}
		}
	}
	return (free(sorted), index_arr);
}
