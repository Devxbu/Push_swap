#include "../push_swap.h"

int pa(t_list **a, t_list **b) {
  t_list *temp;

  if (!(*b))
    return (0);
  temp = *b;
  *b = (*b)->next;
  temp->next = *a;
  *a = temp;
  write(1, "pa\n", 3);
  return (1);
}

int pb(t_list **a, t_list **b) {
  t_list *temp;

  if (!(*a))
    return (0);
  temp = *a;
  *a = (*a)->next;
  temp->next = *b;
  *b = temp;
  write(1, "pb\n", 3);
  return (1);
}
