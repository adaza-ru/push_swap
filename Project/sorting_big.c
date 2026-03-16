/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:27:25 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/16 02:29:11 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int n)
{
	int	max_bits;

	max_bits = 0;
	while (((n - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b, int n)
{
	int	i;
	int	j;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(n);
	while (i < max_bits)
	{
		j = 0;
		while (j < n)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
