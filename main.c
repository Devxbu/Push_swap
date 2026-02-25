#include "push_swap.h"
#include <stdio.h>

static void exit_err(int *nums) {
  if (nums)
    free(nums);
  write(2, "Error\n", 6);
  exit(1);
}

int main(int argc, char **argv) {
  t_mode mode;
  int *nums;
  int size;

  if (argc < 2)
    return (0);

  mode = parse_mode(&argc, &argv);
  nums = validate_input(argc, argv, &size);
  if (!nums)
    exit_err(NULL);
  free(nums);
}