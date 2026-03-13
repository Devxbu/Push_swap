/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:35:38 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 11:03:50 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	exit_err(int *nums, char **arr)
{
	if (arr)
		arr_free(arr);
	if (nums)
		free(nums);
	write(2, "Error\n", 6);
	exit(1);
}

static char	**fill_arr(char **arr, int argc, char **argv)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		i++;
		if (!split)
		{
			arr_free(arr);
			return (NULL);
		}
		j = 0;
		while (split[j])
			arr[k++] = split[j++];
		free(split);
	}
	arr[k] = NULL;
	return (arr);
}

static char	**generate_arr(int argc, char **argv, int *total)
{
	int		i;
	char	**arr;

	*total = 0;
	i = 1;
	while (i < argc)
	{
		if (only_spaces(argv[i]))
			return (NULL);
		*total += count_words(argv[i], ' ');
		i++;
	}
	if (*total == 0)
		return (NULL);
	arr = malloc(sizeof(char *) * (*total + 1));
	if (!arr)
		return (NULL);
	return (fill_arr(arr, argc, argv));
}

int	*validate_input(int argc, char **argv, int *size)
{
	int		i;
	int		*nums;
	char	**arr;

	if (argc < 2)
		exit(0);
	arr = generate_arr(argc, argv, size);
	if (!arr)
		exit_err(NULL, NULL);
	nums = malloc(sizeof(int) * (*size));
	if (!nums)
		exit_err(NULL, arr);
	i = 0;
	while (i < *size)
	{
		if (!safe_atoi(arr[i], &nums[i]) || is_duplicate(nums, i, nums[i]))
			exit_err(nums, arr);
		i++;
	}
	arr_free(arr);
	return (nums);
}
