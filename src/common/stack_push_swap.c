/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 01:57:53 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/09/11 02:25:46 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char *op)
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

void	push(t_stack **dst, t_stack **src, char *op)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = pop_node(src);
	push_node(dst, tmp);
	if (op)
		write(1, op, 3);
}