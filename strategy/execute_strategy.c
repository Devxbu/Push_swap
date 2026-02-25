#include "../push_swap.h"

void execute_strategy(t_mode mode, t_list **a, int size) {
  if (mode == SIMPLE)
    simple_sort(a, size);
  else if (mode == MEDIUM)
    medium_sort(a, size);
  else if (mode == COMPLEX)
    complex_sort(a, size);
  else if (mode == ADAPTIVE)
    adaptive_sort(a, size);
}
