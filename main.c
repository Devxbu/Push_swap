/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:49:35 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 10:54:11 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_err(int *nums, int *indexes)
{
	if (nums)
		free(nums);
	if (indexes)
		free(indexes);
	write(2, "Error\n", 6);
	exit(1);
}

static t_list	*setup(int argc, char **argv, int *size, t_op_counter *ops)
{
	int		*nums;
	int		*indexes;
	t_list	*a;

	init_ops(ops);
	nums = validate_input(argc, argv, size);
	if (!nums)
		exit_err(NULL, NULL);
	indexes = index_finder(*size, nums);
	if (!indexes)
		exit_err(nums, NULL);
	a = create_stack(*size, indexes);
	if (!a)
		exit_err(nums, indexes);
	free(nums);
	free(indexes);
	return (a);
}

static void	run(t_mode mode, t_list **a, int size, t_op_counter *ops)
{
	double	disorder;

	disorder = compute_disorder(*a, size);
	if (!is_sorted(*a))
		execute_strategy(mode, a, size, ops);
	if (ops->op_bool_control)
		bench_print(disorder, mode, ops);
}

int	main(int argc, char **argv)
{
	t_mode			mode;
	t_list			*a;
	int				size;
	int				bench;
	t_op_counter	ops;

	if (argc < 2)
		return (0);
	bench = 0;
	mode = parse_mode(&argc, &argv, &bench);
	a = setup(argc, argv, &size, &ops);
	ops.op_bool_control = bench;
	run(mode, &a, size, &ops);
	free_stack(a);
	return (0);
}
