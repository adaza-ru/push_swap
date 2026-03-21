/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 20:19:09 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/21 20:44:02 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	t_stack	*start;
	int		size;

	if (!stack)
		return (0);
	start = stack;
	size = 1;
	stack = stack->next;
	while (stack != start)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_max_pos(t_stack *stack)
{
	t_stack	*start;
	int		max_pos;
	int		current_pos;
	int		max_index;

	if (!stack)
		return (0);
	start = stack;
	max_pos = 0;
	current_pos = 0;
	max_index = stack->index;
	stack = stack->next;
	while (stack != start)
	{
		current_pos++;
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_pos = current_pos;
		}
		stack = stack->next;
	}
	return (max_pos);
}
