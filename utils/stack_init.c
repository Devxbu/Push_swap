/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:00:42 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/26 20:00:43 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_stack(int size, int *arr)
{
	t_list	*a;
	int		i;
	t_list	*new_node;

	a = NULL;
	i = 0;
	while (i < size)
	{
		new_node = ft_lstnew(arr[i]);
		if (!new_node)
		{
			free_stack(a);
			return (NULL);
		}
		ft_lstadd_back(&a, new_node);
		i++;
	}
	return (a);
}
