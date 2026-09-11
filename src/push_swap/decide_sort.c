/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 02:12:43 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/09/11 02:13:06 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decide_sort_state(t_stack *a, int n)
{
	if (is_sorted(a))
		return (DONE);
	if (n == 2)
	{
		sa(&a);
		return (DONE);
	}
	if (n == 3)
		return (SORT_SMALL);
	if (n <= 5)
		return (SORT_FIVE);
	return (SORT_BIG);
}
