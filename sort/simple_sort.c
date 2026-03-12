/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:00:56 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/03 20:36:34 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void sort_three(t_list **a, int *sa_count, int *ra_count,
                       int *rra_count) {
  int oneth;
  int twoth;
  int threeth;

  oneth = (*a)->content;
  twoth = (*a)->next->content;
  threeth = (*a)->next->next->content;
  if (oneth > twoth && twoth < threeth && oneth < threeth)
    *sa_count += sa(a);
  else if (oneth > twoth && twoth > threeth) {
    *sa_count += sa(a);
    *rra_count += rra(a);
  } else if (oneth > twoth && twoth < threeth && oneth > threeth)
    *ra_count += ra(a);
  else if (oneth < twoth && twoth > threeth && oneth < threeth) {
    *sa_count += sa(a);
    *ra_count += ra(a);
  } else if (oneth < twoth && twoth > threeth && oneth > threeth)
    *rra_count += rra(a);
}

static int find_min_position(t_list *a) {
  int pos;
  int tmp_min_value;
  int tmp_min_node;

  pos = 0;
  tmp_min_value = 0;
  tmp_min_node = a->content;
  while (a) {
    if (a->content < tmp_min_node) {
      tmp_min_node = a->content;
      tmp_min_value = pos;
    }
    a = a->next;
    pos++;
  }
  return (tmp_min_value);
}

static void bring_to_top(t_list **a, int position, int size, int *ra_count,
                         int *rra_count) {
  if (position <= size / 2) {
    while (position-- > 0)
      *ra_count += ra(a);
  } else {
    position = size - position;
    while (position-- > 0)
      *rra_count += rra(a);
  }
}

static void sort_small(t_list **a, t_list **b, int size, int *pa_count,
                       int *pb_count, int *ra_count, int *rra_count,
                       int *sa_count) {
  int to_push;
  int current_size;
  int i;

  to_push = size - 3;
  current_size = size;
  i = 0;
  while (i < to_push) {
    bring_to_top(a, find_min_position(*a), current_size, ra_count, rra_count);
    *pb_count += pb(a, b);
    current_size--;
    i++;
  }
  sort_three(a, sa_count, ra_count, rra_count);
  while (*b)
    *pa_count += pa(a, b);
}

void simple_sort(t_list **a, int size, int is_adaptive, double disorder,
                 int bench) {
  int sa_count = 0;
  int pa_count = 0;
  int pb_count = 0;
  int ra_count = 0;
  int rra_count = 0;
  t_list *b;

  b = NULL;
  if (size <= 1 || is_sorted(*a))
    return;
  if (size == 2) {
    if ((*a)->content > (*a)->next->content)
      sa_count += sa(a);
  } else if (size == 3)
    sort_three(a, &sa_count, &ra_count, &rra_count);
  else
    sort_small(a, &b, size, &pa_count, &pb_count, &ra_count, &rra_count,
               &sa_count);
  if (bench) {
    putstr_fd("[bench] disorder: ", 2);
    putfloat_fd(disorder * 100, 2);
    if (is_adaptive && bench != 2)
      putstr_fd("%\n[bench] strategy: Adaptive / O(n^2)\n[bench] total_ops: ",
                2);
    else if (bench != 2)
      putstr_fd("%\n[bench] strategy: Simple / O(n^2)\n[bench] total_ops: ", 2);
    if (is_adaptive && bench == 2)
      putstr_fd("%\n[bench] strategy: Medium / O(n√2)\n[bench] total_ops: ", 2);
    else if (bench == 2)
      putstr_fd("%\n[bench] strategy: Medium / O(n√2)\n[bench] total_ops: ", 2);
    putnbr_fd(sa_count + pa_count + pb_count + ra_count + rra_count, 2);
    putstr_fd("\n[bench] sa: ", 2);
    putnbr_fd(sa_count, 2);
    putstr_fd(" sb: 0 ss: 0 pa: ", 2);
    putnbr_fd(pa_count, 2);
    putstr_fd(" pb: ", 2);
    putnbr_fd(pb_count, 2);
    putstr_fd("\n", 2);
    putstr_fd("[bench] ra: ", 2);
    putnbr_fd(ra_count, 2);
    putstr_fd(" rb: 0 rr: 0 rra: ", 2);
    putnbr_fd(rra_count, 2);
    putstr_fd(" rrb: 0 rrr: 0\n", 2);
  }
}
