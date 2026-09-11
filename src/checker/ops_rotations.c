/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 02:30:48 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/09/11 02:31:49 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
}

void	rb(t_stack **b)
{
	rotate(b, NULL);
}

void	ra(t_stack **a)
{
	rotate(a, NULL);
}
