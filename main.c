/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:42:48 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/01 01:42:00 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_loading(t_state *state, t_stack **a, char **args)
{
	int	numbers_count;

	numbers_count = init_stack(a, args);
	if (!numbers_count)
		*state = ERROR;
	else
		*state = decide_sort_state(*a, numbers_count);
}

static void	handle_start(t_state *state, int argc, char **args)
{
	if (argc < 2)
		*state = DONE;
	else if (check_argv_error(args))
		*state = ERROR;
	else
		*state = LOADING;
}

int	main(int argc, char **argv)
{
	t_state	state;
	t_stack	*a;

	state = START;
	a = NULL;
	while (state != DONE && state != ERROR)
	{
		if (state == START)
			handle_start(&state, argc, argv + 1);
		else if (state == LOADING)
			handle_loading(&state, &a, argv + 1);
		else if (state >= SORT_SMALL && state <= SORT_BIG)
		{
			execute_sorting(a, state);
			state = DONE;
		}
	}
	return (terminate_program(state, a));
}
