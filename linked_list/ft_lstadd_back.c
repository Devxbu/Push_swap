/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:24:17 by buranli           #+#    #+#             */
/*   Updated: 2026/01/12 16:37:37 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_lstadd_back(t_list **lst, t_list *new) {
  t_list *temp;

  if (!lst || !new)
    return;
  if (!*lst) {
    *lst = new;
    return;
  }
  temp = *lst;
  while (temp->next)
    temp = temp->next;
  temp->next = new;
}
