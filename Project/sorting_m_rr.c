/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:45:33 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/16 01:47:07 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "rrr\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b, "rrb\n");
}

void	rra(t_stack **a)
{
	reverse_rotate(a, "rra\n");
}
