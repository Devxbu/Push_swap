/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:47 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/28 11:42:47 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void adaptive_sort(t_list **a, int size, int bench) {
  double disorder;

  // Look again the sizes it might be wrong here
  disorder = compute_disorder(*a, size);
  if (size <= 5) {
    simple_sort(a, size, 1, disorder, bench);
    return;
  }
  if (size <= 100) {
    if (disorder < 0.15)
      simple_sort(a, size, 1, disorder, bench);
    else
      medium_sort(a, size, bench, 1, disorder);
  } else {
    if (disorder < 0.10)
      medium_sort(a, size, bench, 1, disorder);
    else
      complex_sort(a, size, bench, 1, disorder);
  }
}

// This method can be true
// void adaptive_sort(t_list **a, int size, int bench) {
//   double disorder;

//   // Look again the sizes it might be wrong here
//   disorder = compute_disorder(*a, size);
//     if (disorder < 0.2)
//       simple_sort(a, size, 1, disorder, bench);
//     else if (disorder < 0.5)
//       medium_sort(a, size, bench, 1, disorder);
//     else
//       complex_sort(a, size, bench, 1, disorder);
//   }
// }
