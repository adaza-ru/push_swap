/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sorting_m_swap_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:22:48 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/23 00:06:00 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

static void	swap(t_stack **stack, char *op)
{
	int	tmp_num;
	int	tmp_idx;

	if (!*stack || (*stack)->next == *stack)
		return ;
	tmp_num = (*stack)->number;
	tmp_idx = (*stack)->index;
	(*stack)->number = (*stack)->next->number;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->number = tmp_num;
	(*stack)->next->index = tmp_idx;
	if (op)
		write(1, op, 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, NULL);
	swap(b, NULL);
}

void	sb(t_stack **b)
{
	swap(b, NULL);
}

void	sa(t_stack **a)
{
	swap(a, NULL);
}
