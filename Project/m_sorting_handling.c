/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_sorting_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:59:27 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 14:30:07 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_push_swap.h"

void	execute_sorting(t_stack **a, t_state state, int n)
{
	t_stack	*b;

	b = NULL;
	if (state == SORT_SMALL)
		sort_small(a);
	else if (state == SORT_FIVE)
		sort_five(a, &b, n);
	else if (state == SORT_BIG)
		big_sort(a, &b, n);
}
