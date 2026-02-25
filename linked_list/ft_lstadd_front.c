/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:13:27 by buranli           #+#    #+#             */
/*   Updated: 2026/01/12 16:37:27 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_lstadd_front(t_list **lst, t_list *new) {
  if (!lst || !new)
    return;
  new->next = *lst;
  *lst = new;
}
