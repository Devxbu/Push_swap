/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:38:11 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/03 20:40:42 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void bring_to_top_b(t_list **b, int position, int size, int *rb_count,
                    int *rrb_count) {
  if (position <= size / 2) {
    while (position-- > 0)
      *rb_count += rb(b);
  } else {
    position = size - position;
    while (position-- > 0)
      *rrb_count += rrb(b);
  }
}

void print_bench_medium(double disorder, int is_adaptive, int ra_count,
                        int pb_count, int pa_count, int rb_count,
                        int rrb_count) {
  putstr_fd("[bench] disorder: ", 2);
  putfloat_fd(disorder * 100, 2);
  if (is_adaptive)
    putstr_fd("%\n[bench] strategy: Adaptive / O(n√n)\n[bench] total_ops: ", 2);
  else
    putstr_fd("%\n[bench] strategy: Medium / O(n√n)\n[bench] total_ops: ", 2);
  putnbr_fd(pa_count + pb_count + ra_count + rb_count + rrb_count, 2);
  putstr_fd("\n[bench] sa: 0 sb: 0 ss: 0 pa: ", 2);
  putnbr_fd(pa_count, 2);
  putstr_fd(" pb: ", 2);
  putnbr_fd(pb_count, 2);
  putstr_fd("\n[bench] ra: ", 2);
  putnbr_fd(ra_count, 2);
  putstr_fd("rb: ", 2);
  putnbr_fd(rb_count, 2);
  putstr_fd(" rr: 0 rra: 0 rrb: ", 2);
  putnbr_fd(rrb_count, 2);
  putstr_fd(" rrr: 0\n", 2);
}