/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:21:15 by buranli           #+#    #+#             */
/*   Updated: 2026/01/12 18:11:17 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_lstsize(t_list *lst) {
  int i;

  if (!lst)
    return (0);
  i = 0;
  while (lst) {
    i++;
    lst = lst->next;
  }
  return (i);
}
