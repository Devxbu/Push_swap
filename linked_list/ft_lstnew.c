/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:07:26 by buranli           #+#    #+#             */
/*   Updated: 2026/01/17 01:50:44 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *ft_lstnew(int content) {
  t_list *node;

  node = (t_list *)malloc(sizeof(t_list));
  if (!node)
    return (NULL);
  node->content = content;
  node->next = NULL;
  return (node);
}
