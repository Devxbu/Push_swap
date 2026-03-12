/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:30:12 by melmbaz           #+#    #+#             */
/*   Updated: 2026/02/26 19:30:21 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void exit_err(void) {
  write(2, "Error\n", 6);
  exit(1);
}

static int ft_strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return ((unsigned char)*s1 - (unsigned char)*s2);
}
// Ask Mehran if the bench flag can be used after the other flags. ex ->
// --adaptive --bench ? Is there a problem?
void bench_finder(int *argc, char ***argv, int *bench) {
  if (*bench == 1 && *argc > 1 && ft_strcmp((*argv)[1], "--bench") == 0)
    exit_err();
  if (*argc > 1 && ft_strcmp((*argv)[1], "--bench") == 0 && *bench == 0) {
    *bench = 1;
    (*argv)++;
    (*argc)--;
  }
}

t_mode parse_mode(int *argc, char ***argv, int *bench) {
  t_mode mode;

  mode = ADAPTIVE;
  bench_finder(argc, argv, bench);
  if (*argc > 1 && (*argv)[1][0] == '-' && (*argv)[1][1] == '-') {
    if (ft_strcmp((*argv)[1], "--simple") == 0)
      mode = SIMPLE;
    else if (ft_strcmp((*argv)[1], "--medium") == 0)
      mode = MEDIUM;
    else if (ft_strcmp((*argv)[1], "--complex") == 0)
      mode = COMPLEX;
    else if (ft_strcmp((*argv)[1], "--adaptive") == 0)
      mode = ADAPTIVE;
    else
      exit_err();
    (*argv)++;
    (*argc)--;
    if (*argc < 2)
      exit_err();
  }
  bench_finder(argc, argv, bench);
  return (mode);
}
