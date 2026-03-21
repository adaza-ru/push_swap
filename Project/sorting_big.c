/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:27:25 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/21 21:11:18 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_a(t_stack **a, t_stack **b)
{
	int	max_pos;
	int	size;

	while (*b)
	{
		size = get_stack_size(*b);
		max_pos = get_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			while (max_pos++ < size)
				rrb(b);
		}
		pa(a, b);
	}
}

static void	push_to_b(t_stack **a, t_stack **b, int chunk_size)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(b, a);
			i++;
		}
		else
		{
			ra(a);
		}
	}
}

static int	calculate_chunk(int n)
{
	double	sqr_nr;
	double	next;
	int		iter;

	if (n <= 0)
		return (0);
	sqr_nr = (double)n;
	iter = 60;
	while (iter--)
	{
		next = 0.5 * (sqr_nr + ((double)n / sqr_nr));
		if (next > sqr_nr && (next - sqr_nr) < 1e-12)
			break ;
		if (sqr_nr > next && (sqr_nr - next) < 1e-12)
			break ;
		sqr_nr = next;
	}
	n = (int)(sqr_nr * 1.45 + 0.5);
	if (n < 1)
		return (1);
	return (n);
}

void	big_sort(t_stack **a, t_stack **b, int n)
{
	int	chunk_size;

	chunk_size = calculate_chunk(n);
	push_to_b(a, b, chunk_size);
	push_to_a(a, b);
}
