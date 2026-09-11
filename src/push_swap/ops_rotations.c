/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 02:30:48 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/09/11 02:32:36 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
