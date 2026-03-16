/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:40:49 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/16 01:46:43 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, op, 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a, "pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b, "pa\n");
}
