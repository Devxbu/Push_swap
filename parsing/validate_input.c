/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:35:38 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/26 19:35:39 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

static void	ft_free(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	only_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static void	exit_err(int *nums, char **arr)
{
	if (arr)
		ft_free(arr);
	if (nums)
		free(nums);
	write(2, "Error\n", 6);
	exit(1);
}

static char	**generate_arr(int argc, char **argv, int *total)
{
	int		i;
	int		j;
	int		k;
	char	**arr;
	char	**split;

	*total = 0;
	i = 1;
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
	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		if (!split)
			return (ft_free(arr), NULL);
		j = 0;
		while (split[j])
			arr[k++] = split[j++];
		free(split);
	}
	arr[k] = NULL;
	return (arr);
}

static int	is_duplicate(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	*validate_input(int argc, char **argv, int *size)
{
	int		i;
	int		*nums;
	char	**arr;

	if (argc < 2)
		exit(0);
	arr = generate_arr(argc, argv, size);
	// Check this part (if arr is NULL, does always exit_err(NULL, NULL)?)
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
	ft_free(arr);
	return (nums);
}
