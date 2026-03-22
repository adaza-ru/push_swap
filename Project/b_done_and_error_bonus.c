/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_done_and_error_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:27:11 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 22:18:16 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

static void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	last = (*stack)->prev;
	last->next = NULL;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	terminate_program(t_state state, t_stack *a, t_stack *b)
{
	free_stack(&a);
	free_stack(&b);
	if (state == ERROR)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}
