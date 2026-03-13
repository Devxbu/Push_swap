/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:41:48 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/13 13:52:43 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_INTEGER 2147483647
# define MIN_INTEGER -2147483648

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_op_counter
{
	int				sa_counter;
	int				sb_counter;
	int				ss_counter;
	int				pa_counter;
	int				pb_counter;
	int				ra_counter;
	int				rb_counter;
	int				rr_counter;
	int				rra_counter;
	int				rrb_counter;
	int				rrr_counter;
	int				op_bool_control;
	int				chosen_mode;
	int				bit_pass;

}					t_op_counter;

typedef enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
}					t_mode;

// Operations
int					sa(t_list **a, t_op_counter *ops);
int					sb(t_list **b, t_op_counter *ops);
int					ss(t_list **a, t_list **b, t_op_counter *ops);
int					pa(t_list **a, t_list **b, t_op_counter *ops);
int					pb(t_list **a, t_list **b, t_op_counter *ops);
int					ra(t_list **a, t_op_counter *ops);
int					rb(t_list **b, t_op_counter *ops);
int					rr(t_list **a, t_list **b, t_op_counter *ops);
int					rra(t_list **a, t_op_counter *ops);
int					rrb(t_list **b, t_op_counter *ops);
int					rrr(t_list **a, t_list **b, t_op_counter *ops);

// Linked List
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);

// Utils
double				compute_disorder(t_list *stack, int size);
int					safe_atoi(const char *str, int *out);
char				**ft_split(char const *s, char c);
size_t				count_words(const char *s, char c);
void				free_stack(t_list *stack);
void				free_all(int *values, int *indexes, t_list *stack);
void				init_ops(t_op_counter *ops);
int					*index_finder(int size, int *arr);
int					is_sorted(t_list *stack);
t_list				*create_stack(int size, int *arr);
void				bring_to_top_b(t_list **b, int position, int size,
						t_op_counter *ops);

// Parsing
t_mode				parse_mode(int *argc, char ***argv, int *bench);
int					*validate_input(int argc, char **argv, int *size);
void				arr_free(char **arr);
int					only_spaces(char *str);
int					is_duplicate(int *arr, int size, int num);

// Strategy
void				execute_strategy(t_mode mode, t_list **a, int size,
						t_op_counter *ops);
void				adaptive_sort(t_list **a, int size, t_op_counter *ops);

// Sorting
void				simple_sort(t_list **a, int size, t_op_counter *ops);
void				medium_sort(t_list **a, int size, t_op_counter *ops);
void				complex_sort(t_list **a, int size, t_op_counter *ops);

// Bench
void				bench_print(double disorder, t_mode mode,
						t_op_counter *ops);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

// simple_sort utils
void				move_one(t_list **a, t_op_counter *ops);
void				move_two(t_list **a, t_op_counter *ops);
void				move_three(t_list **a, t_op_counter *ops);
void				move_four(t_list **a, t_op_counter *ops);
void				move_five(t_list **a, t_op_counter *ops);

#endif