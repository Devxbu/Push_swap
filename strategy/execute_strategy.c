/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:53 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/28 07:19:53 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void execute_strategy(t_mode mode, t_list **a, int size, int bench) {
  double disorder;
  disorder = compute_disorder(*a, size);

  if (mode == SIMPLE)
    simple_sort(a, size, 0, disorder, bench);
  else if (mode == MEDIUM)
    medium_sort(a, size, bench, 0, disorder);
  else if (mode == COMPLEX)
    complex_sort(a, size, bench, 0, disorder);
  else if (mode == ADAPTIVE)
    adaptive_sort(a, size, bench);
}
