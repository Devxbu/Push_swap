#include "../push_swap.h"

t_list *create_stack(int size, int *arr) {
  t_list *a;
  int i;

  a = NULL;
  i = 0;
  while (i < size) {
    t_list *new_node = ft_lstnew(arr[i]);
    if (!new_node) {
      free_stack(a);
      return (NULL);
    }
    ft_lstadd_back(&a, new_node);

    i++;
  }
  return (a);
}
