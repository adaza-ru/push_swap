/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_sorting_m_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:22:28 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 14:31:01 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_push_swap.h"

static void	rotate(t_stack **stack, char *op)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
	if (op)
		write(1, op, 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	write(1, "rr\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b, "rb\n");
}

void	ra(t_stack **a)
{
	rotate(a, "ra\n");
}
