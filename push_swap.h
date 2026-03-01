/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:30:29 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/01 01:49:28 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef enum e_state
{
	START,
	LOADING,
	SORT_SMALL,
	SORT_FIVE,
	SORT_BIG,
	DONE,
	ERROR
}		t_state;

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

int	check_argv_error(char **argv);
int	init_stack(t_stack **a, char **args);
int	count_numbers(char **args);
int	check_duplicates(int *sorted_nums, int n);
int	*numbers_array(char **args, int n);
int	ft_atoi(const char *str);

int	binary_search_index(int *sorted_arr, int n, int value);

int	terminate_program(t_state state, t_stack *a);

#endif