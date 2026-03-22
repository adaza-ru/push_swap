/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sorting_m_rr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:22:40 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/23 00:05:41 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

static void	reverse_rotate(t_stack **stack, char *op)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
	if (op)
		write(1, op, 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b, NULL);
}

void	rra(t_stack **a)
{
	reverse_rotate(a, NULL);
}
