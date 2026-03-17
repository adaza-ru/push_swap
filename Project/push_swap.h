/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:30:29 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/17 17:21:47 by adaza-ru         ###   ########.fr       */
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

int		check_argv_error(char **argv);
int		init_stack(t_stack **a, char **args);
int		count_numbers(char **args);
int		check_duplicates(int *sorted_nums, int n);
int		*numbers_array(char **args, int n);
int		ft_atoi(const char *str);
int		*indexes_array(int *nums, int n);
int		check_duplicates(int *sorted_nums, int n);
int		binary_search_index(int *sorted_arr, int n, int value);
int		decide_sort_state(t_stack *a, int n);
int		is_sorted(t_stack *a);
void	ss(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	execute_sorting(t_stack **a, t_state state, int n);
void	sort_small(t_stack **a);
void	sort_five(t_stack **a, t_stack **b, int n);
//void	sort_five(t_stack **a, t_stack **b, int n);
void	radix_sort(t_stack **a, t_stack **b, int n);
int		terminate_program(t_state state, t_stack *a);

#endif