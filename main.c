#include "push_swap.h"
#include <stdio.h>

static void exit_err(int *nums, int *indexes) {
  if (nums)
    free(nums);
  if (indexes)
    free(indexes);
  write(2, "Error\n", 6);
  exit(1);
}

int main(int argc, char **argv) {
  t_mode mode;
  int *nums;
  int *indexes;
  int size;

  if (argc < 2)
    return (0);

  mode = parse_mode(&argc, &argv);
  nums = validate_input(argc, argv, &size);
  if (!nums)
    exit_err(NULL, NULL);
  indexes = index_finder(size, nums);
  if (!indexes)
    exit_err(nums, NULL);
}