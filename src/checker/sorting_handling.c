/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:59:27 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/09/11 02:16:34 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	string_compare(const char *line, const char *cmd)
{
	int	i;

	i = 0;
	while (line[i] && cmd[i] && line[i] == cmd[i])
		i++;
	if (line[i] == '\0' && cmd[i] == '\0')
		return (1);
	else
		return (0);
}

static int	run_command(char *line, t_stack **a, t_stack **b)
{
	if (string_compare(line, "sa"))
		sa(a);
	else if (string_compare(line, "sb"))
		sb(b);
	else if (string_compare(line, "ss"))
		ss(a, b);
	else if (string_compare(line, "pa"))
		pa(a, b);
	else if (string_compare(line, "pb"))
		pb(b, a);
	else if (string_compare(line, "ra"))
		ra(a);
	else if (string_compare(line, "rb"))
		rb(b);
	else if (string_compare(line, "rr"))
		rr(a, b);
	else if (string_compare(line, "rra"))
		rra(a);
	else if (string_compare(line, "rrb"))
		rrb(b);
	else if (string_compare(line, "rrr"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	execute_sorting(t_stack **a, t_state *state, t_stack **b)
{
	char	*line;
	char	*eol;

	while (*state == SORTING)
	{
		line = get_next_line(0);
		if (!line)
			*state = DONE;
		else
		{
			eol = ft_strchr(line, '\n');
			if (eol)
				*eol = '\0';
			if (!run_command(line, a, b))
				*state = ERROR;
			free(line);
		}
	}
	if (is_sorted(*a) && !*b && *state == DONE)
		write(1, "OK\n", 3);
	else if (*state == DONE)
		write(1, "KO\n", 3);
}
