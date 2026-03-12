/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:00:59 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/04 18:35:49 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int mposition_finder(t_list *a) {
  int pos;
  int tmp_max_value;
  int tmp_max_node;

  pos = 0;
  tmp_max_value = 0;
  tmp_max_node = a->content;
  while (a) {
    if (a->content > tmp_max_node) {
      tmp_max_node = a->content;
      tmp_max_value = pos;
    }
    a = a->next;
    pos++;
  }
  return (tmp_max_value);
}

static int square(int size) {
  int i;

  i = 0;
  while (i * i <= size)
    i++;
  return (i - 1);
}

static void chunk_psh(t_list **a, t_list **b, int size, int *pb_count,
                      int *ra_count) {
  int chunk_size;
  int chunk_num;
  int chunk_min;
  int current_size;
  int i;

  chunk_size = square(size);
  chunk_num = 0;
  while (*a) {
    i = 0;
    chunk_min = chunk_num * chunk_size;
    current_size = ft_lstsize(*a);
    while (i++ < current_size) {
      if ((*a)->content >= chunk_min && (*a)->content < chunk_min + chunk_size)
        *pb_count += pb(a, b);
      else
        *ra_count += ra(a);
    }
    chunk_num++;
  }
}

static void chunk_pll(t_list **a, t_list **b, int *pa_count, int *rb_count,
                      int *rrb_count) {
  int mposition;
  int size_b;

  while (*b) {
    mposition = mposition_finder(*b);
    size_b = ft_lstsize(*b);
    bring_to_top_b(b, mposition, size_b, rb_count, rrb_count);
    *pa_count += pa(a, b);
  }
}

void medium_sort(t_list **a, int size, int bench, int is_adaptive,
                 double disorder) {
  t_list *b;
  int ra_count;
  int pb_count;
  int pa_count;
  int rb_count;
  int rrb_count;

  ra_count = 0;
  pb_count = 0;
  pa_count = 0;
  rb_count = 0;
  rrb_count = 0;
  b = NULL;
  if (size <= 1 || is_sorted(*a))
    return;
  else if (size <= 6) {
    simple_sort(a, size, is_adaptive, disorder, 2);
    return;
  } else {
    chunk_psh(a, &b, size, &pb_count, &ra_count);
    chunk_pll(a, &b, &pa_count, &rb_count, &rrb_count);
  }
  printf("bench %d", bench);
  if (bench)
    print_bench_medium(disorder, is_adaptive, ra_count, pb_count, pa_count,
                       rb_count, rrb_count);
}