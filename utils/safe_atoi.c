/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:37:31 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/26 19:37:46 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	result_finder(const char **str1, int sign)
{
	char	*str;
	long	result;

	result = 0;
	str = (char *)*str1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 &&
				-result < INT_MIN))
			return (0);
		str++;
	}
	*str1 = (const char *)str;
	return (result);
}

int	safe_atoi(const char *str, int *out)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	result = result_finder(&str, sign);
	if (*str != '\0')
		return (0);
	*out = (int)(result * sign);
	return (1);
}
