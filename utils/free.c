#include "../push_swap.h"

void free_stack(t_list *stack) {
  t_list *tmp;

  while (stack) {
    tmp = stack->next;
    free(stack);
    stack = tmp;
  }
}

void free_all(int *nums, int *indexes, t_list *a) {
  if (nums)
    free(nums);
  if (indexes)
    free(indexes);
  if (a)
    free_stack(a);
}
