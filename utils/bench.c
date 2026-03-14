/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:26:48 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/14 17:05:54 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_disorder(double disorder, int fd)
{
	int	whole;
	int	frac;

	whole = (int)(disorder * 100);
	frac = (int)(disorder * 10000) - (whole * 100);
	ft_putnbr_fd(whole, fd);
	write(fd, ".", 1);
	if (frac < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(frac, fd);
	write(fd, "%", 1);
}

static void	print_ops_rotate(t_op_counter *ops, int fd)
{
	ft_putstr_fd("[bench] ra: ", fd);
	ft_putnbr_fd(ops->ra_counter, fd);
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(ops->rb_counter, fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(ops->rr_counter, fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(ops->rra_counter, fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(ops->rrb_counter, fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(ops->rrr_counter, fd);
	write(fd, "\n", 1);
}

static void	print_ops(t_op_counter *ops, int total, int fd)
{
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putnbr_fd(total, fd);
	write(fd, "\n", 1);
	ft_putstr_fd("[bench] sa: ", fd);
	ft_putnbr_fd(ops->sa_counter, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(ops->sb_counter, fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(ops->ss_counter, fd);
	ft_putstr_fd(" pa: ", fd);
	ft_putnbr_fd(ops->pa_counter, fd);
	ft_putstr_fd(" pb: ", fd);
	ft_putnbr_fd(ops->pb_counter, fd);
	write(fd, "\n", 1);
	print_ops_rotate(ops, fd);
}

static void	print_complexity(int chosen_mode, int fd)
{
	if (chosen_mode == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", fd);
	else if (chosen_mode == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)", fd);
	else
		ft_putstr_fd("Complex / O(n log n)", fd);
}

void	bench_print(double disorder, t_mode mode, t_op_counter *ops)
{
	int	total;

	total = ops->sa_counter + ops->sb_counter + ops->ss_counter
		+ ops->pa_counter + ops->pb_counter + ops->ra_counter
		+ ops->rb_counter + ops->rr_counter + ops->rra_counter
		+ ops->rrb_counter + ops->rrr_counter;
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(disorder, 2);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (mode == ADAPTIVE)
		ft_putstr_fd("Adaptive -> ", 2);
	print_complexity(ops->chosen_mode, 2);
	write(2, "\n", 1);
	print_ops(ops, total, 2);
}
