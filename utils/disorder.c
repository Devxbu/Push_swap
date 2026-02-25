#include "../push_swap.h"

double compute_disorder(t_list *stack, int size) {
  t_list *i;
  t_list *j;
  int mistakes;
  int total_pairs;

  mistakes = 0;
  total_pairs = 0;
  if (size < 2)
    return (0.0);
  i = stack;
  while (i) {
    j = i->next;
    while (j) {
      total_pairs++;
      if (i->content > j->content)
        mistakes++;
      j = j->next;
    }
    i = i->next;
  }

  return ((double)mistakes / (double)total_pairs);
}
