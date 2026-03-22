/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sorting_m_push_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:22:20 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/23 00:07:15 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

static t_stack	*pop_node(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	if (node->next == node)
		*stack = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*stack = node->next;
	}
	node->next = node;
	node->prev = node;
	return (node);
}

static void	push_node(t_stack **stack, t_stack *node)
{
	if (!*stack)
		*stack = node;
	else
	{
		node->next = *stack;
		node->prev = (*stack)->prev;
		node->prev->next = node;
		(*stack)->prev = node;
		*stack = node;
	}
}

static void	push(t_stack **dst, t_stack **src, char *op)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = pop_node(src);
	push_node(dst, tmp);
	if (op)
		write(1, op, 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a, NULL);
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b, NULL);
}
