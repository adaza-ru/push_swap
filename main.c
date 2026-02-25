/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:42:48 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/02/25 00:34:53 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
	{
		if (check_argv_error(argv + 1))
		{
			write(2, "Error\n", 6);
			return (-1);
		}

		
	}
	return (0);
}

/*
int	main(int argc, char **argv)
{
	t_state	st;
	t_stack	*a;

	st = START;
	a = NULL;
	while (st != DONE && st != ERR)
	{
		if (st == START)
			handle_start(&st, argc, argv);
		else if (st == LOADING)
			handle_loading(&st, &a, argv + 1);
		else if (st >= SORT_SMALL && st <= SORT_BIG)
		{
			execute_sorting(a, st);
			st = DONE;
		}
	}
	return (terminate_program(st, a));
}

void	handle_start(t_state *st, int argc, char **argv)
{
	if (argc < 2)
		*st = DONE;
	else if (check_argv_error(argv + 1))
		*st = ERR;
	else
		*st = LOADING;
}

void	handle_loading(t_state *st, t_stack **a, char **args)
{
	int	sz;

	sz = init_and_fill(a, args);
	if (sz == -1)
		*st = ERR;
	else
		*st = decide_sort_state(*a, sz);
}















int	main(int argc, char **argv)
{
	t_state	state;
	t_stack	*stack_a;
	int		size;

	state = START;
	stack_a = NULL;
	while (state != DONE && state != ERR)
	{
		if (state == START)
		{
			state = PARSING;
			if (argc < 2)
				state = DONE;
		}
		else if (state == PARSING)
		{
			state = LOADING;
			if (check_argv_error(argv + 1))
				state = ERR;
		}
		else if (state == LOADING)
		{
			size = init_and_fill(&stack_a, argv + 1);
			if (size == -1)
				state = ERR;
			else
				state = decide_sort_state(stack_a, size);
		}
		else if (state == SORT_SMALL || state == SORT_FIVE || state == SORT_BIG)
		{
			execute_sorting(stack_a, state);
			state = DONE;
		}
	}
	return (terminate_program(state, stack_a));
}

t_state	decide_sort_state(t_stack *stack, int size)
{
	if (is_sorted(stack))
		return (DONE);
	if (size <= 3)
		return (SORT_SMALL);
	if (size <= 5)
		return (SORT_FIVE);
	return (SORT_BIG);
}

t_state	decide_sort_state(t_stack *stack, int size)
{
	if (is_sorted(stack))
		return (DONE);
	if (size <= 3)
		return (SORT_SMALL);
	if (size <= 5)
		return (SORT_FIVE);
	return (SORT_BIG);
}

int	terminate_program(t_state state, t_stack *stack)
{
	if (state == ERR)
		write(2, "Error\n", 6);
	if (stack)
		free_stack(stack);
	if (state == ERR)
		return (-1);
	return (0);
}
*/