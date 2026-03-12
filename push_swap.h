/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:41:48 by melmbaz           #+#    #+#             */
/*   Updated: 2026/03/03 20:39:40 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_INTEGER 2147483647
#define MIN_INTEGER -2147483648

typedef struct s_list {
  int content;
  struct s_list *next;
} t_list;

typedef enum e_mode { SIMPLE, MEDIUM, COMPLEX, ADAPTIVE } t_mode;

// Operations
int sa(t_list **a);
int sb(t_list **b);
int ss(t_list **a, t_list **b);
int pa(t_list **a, t_list **b);
int pb(t_list **a, t_list **b);
int ra(t_list **a);
int rb(t_list **b);
int rr(t_list **a, t_list **b);
int rra(t_list **a);
int rrb(t_list **b);
int rrr(t_list **a, t_list **b);

// Linked List
t_list *ft_lstnew(int content);
void ft_lstadd_back(t_list **lst, t_list *node);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_front(t_list **lst, t_list *node);

// Utils
double compute_disorder(t_list *stack, int size);
int safe_atoi(const char *str, int *out);
char **ft_split(char const *s, char c);
size_t count_words(const char *s, char c);
void free_stack(t_list *stack);
void free_all(int *values, int *indexes, t_list *stack);
int *index_finder(int size, int *arr);
int is_sorted(t_list *stack);
t_list *create_stack(int size, int *arr);
void bring_to_top_b(t_list **b, int position, int size, int *rb_count,
                    int *rrb_count);
void print_bench_medium(double disorder, int is_adaptive, int ra_count,
                        int pb_count, int pa_count, int rb_count,
                        int rrb_count);
void putstr_fd(char *s, int fd);
void putnbr_fd(int n, int fd);
void putfloat_fd(double n, int fd);

// Parsing
t_mode parse_mode(int *argc, char ***argv, int *bench);
int *validate_input(int argc, char **argv, int *size);

// Strategy
void execute_strategy(t_mode mode, t_list **a, int size, int bench);
void adaptive_sort(t_list **a, int size, int bench);

// Sorting
void simple_sort(t_list **a, int size, int is_adaptive, double disorder,
                 int bench);
void medium_sort(t_list **a, int size, int bench, int is_adaptive,
                 double disorder);
void complex_sort(t_list **a, int size, int bench, int is_adaptive,
                  double disorder);
#endif