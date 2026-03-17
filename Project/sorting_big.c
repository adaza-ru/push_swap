/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:27:25 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/17 19:54:00 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_chunk(int n)
{
	float	size;
	float	sqr_nr;
	float	precision;

	if (n <= 0)
		return (0);
	sqr_nr = (float)n;
	precision = 0.00001f;
	while ((sqr_nr * sqr_nr - (float)n) > precision
		|| ((float)n - sqr_nr * sqr_nr) > precision)
		sqr_nr = (sqr_nr + ((float)n / sqr_nr)) / 2;
	size = sqr_nr * 1.45f;
	return ((int)(size + 0.5f));
}

void	big_sort(t_stack **a, t_stack **b, int n)
{
	int	chunk_size;

	chunk_size = calculate_chunk(n);
}

/*
static int	get_max_bits(int n)
{
	int	max_bits;

	max_bits = 0;
	while (((n - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	big_sort(t_stack **a, t_stack **b, int n)
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
*/
