/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:42:48 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 22:37:42 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

static int	handle_loading(t_state *state, t_stack **a, char **args)
{
	int	n;

	n = init_stack(a, args);
	if (n == 0)
		*state = ERROR;
	else
		*state = SORTING;
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
	t_stack	*b;
	int		rtn;

	b = NULL;
	state = START;
	a = NULL;
	while (state != DONE && state != ERROR)
	{
		if (state == START)
			handle_start(&state, argc, argv + 1);
		else if (state == LOADING)
			handle_loading(&state, &a, argv + 1);
		else if (state == SORTING)
			execute_sorting(&a, &state, &b);
	}
	rtn = terminate_program(state, a, b);
	return (rtn);
}
