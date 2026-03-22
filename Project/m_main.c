/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:42:48 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 14:29:05 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_push_swap.h"

static int	handle_loading(t_state *state, t_stack **a, char **args)
{
	int	n;

	n = init_stack(a, args);
	if (n == 0)
		*state = ERROR;
	else
		*state = decide_sort_state(*a, n);
	return (n);
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
	int		n;
	int		rtn;

	state = START;
	a = NULL;
	n = 0;
	while (state != DONE && state != ERROR)
	{
		if (state == START)
			handle_start(&state, argc, argv + 1);
		else if (state == LOADING)
			n = handle_loading(&state, &a, argv + 1);
		else if (state >= SORT_SMALL && state <= SORT_BIG)
		{
			execute_sorting(&a, state, n);
			state = DONE;
		}
	}
	rtn = terminate_program(state, a);
	return (rtn);
}
