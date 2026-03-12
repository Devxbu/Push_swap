/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:01:02 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/10 16:26:54 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void print_bench(double disorder, int is_adaptive, int pb_count,
                        int ra_count, int pa_count) {
  putstr_fd("[bench] disorder: ", 2);
  putfloat_fd(disorder * 100, 2);
  if (is_adaptive)
    putstr_fd("%\n[bench] strategy: Adaptive / O(n log n)\n[bench] total_ops: ",
              2);
  else
    putstr_fd("%\n[bench] strategy: Complex / O(n log n)\n[bench] total_ops: ",
              2);
  putnbr_fd(pa_count + pb_count + ra_count, 2);
  putstr_fd("\n[bench] sa: 0 sb: 0 ss: 0 pa: ", 2);
  putnbr_fd(pa_count, 2);
  putstr_fd(" pb: ", 2);
  putnbr_fd(pb_count, 2);
  putstr_fd("\n[bench] ra: ", 2);
  putnbr_fd(ra_count, 2);
  putstr_fd(" rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0\n", 2);
}

void complex_sort(t_list **a, int size, int bench, int is_adaptive,
                  double disorder) {
  int i;
  int bit_amount;
  t_list *b;
  int ra_count;
  int pb_count;
  int pa_count;

  ra_count = 0;
  pb_count = 0;
  pa_count = 0;
  b = NULL;
  bit_amount = 0;
  while ((1 << bit_amount) < size) {
    i = 0;
    while (i++ < size) {
      if (((*a)->content >> bit_amount) & 1)
        ra_count += ra(a);
      else
        pb_count += pb(a, &b);
    }
    while (b)
      pa_count += pa(a, &b);
    bit_amount++;
  }
  print_bench(disorder, is_adaptive, pb_count, ra_count, pa_count);
}
