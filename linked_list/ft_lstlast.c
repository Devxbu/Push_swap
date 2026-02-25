/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:24:54 by buranli           #+#    #+#             */
/*   Updated: 2026/01/12 16:26:22 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *ft_lstlast(t_list *lst) {
  if (!lst)
    return (NULL);
  while (lst->next)
    lst = lst->next;
  return (lst);
}
