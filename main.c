/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:49:35 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/26 19:17:08 by melmbaz          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_mode	mode;
	t_list	*a;
	int		*nums;
	int		*indexes;
	int		size;

	if (argc < 2)
		return (0);
	mode = parse_mode(&argc, &argv);
	nums = validate_input(argc, argv, &size);
	if (!nums)
		exit_err(NULL, NULL);
	indexes = index_finder(size, nums);
	if (!indexes)
		exit_err(nums, NULL);
	a = create_stack(size, indexes);
	if (!a)
		exit_err(nums, indexes);
	if (!is_sorted(a))
		execute_strategy(mode, &a, size);
	free_all(nums, indexes, a);
	return (0);
}
