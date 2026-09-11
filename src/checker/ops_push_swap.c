/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:22:20 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/09/11 02:29:06 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pb(t_stack **b, t_stack **a)
{
	push(b, a, NULL);
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b, NULL);
}
