/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:19:16 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/21 20:22:20 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a, t_stack **b, int n)
{
	int	pushed;

	pushed = 0;
	while (pushed < n - 3)
	{
		if ((*a)->index < (n - 3))
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
	}
	sort_small(a);
	while (pushed-- > 0)
	{
		pa(a, b);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}
