#include "../push_swap.h"

int is_sorted(t_list *stack) {
  if (!stack)
    return (1);
  while (stack->next) {
    if (stack->content > stack->next->content)
      return (0);
    stack = stack->next;
  }
  return (1);
}
