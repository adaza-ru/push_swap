/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_loading_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 01:09:02 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 14:28:57 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_push_swap.h"

static t_stack	*ft_stack_new(int val, int *idx, int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = val;
	node->index = binary_search_index(idx, n, val);
	node->next = node;
	node->prev = node;
	return (node);
}

static int	fill_stack(t_stack **a, int *numbers, int *indexes, int n)
{
	int		i;
	t_stack	*new;
	t_stack	*last;

	i = 0;
	while (i < n)
	{
		new = ft_stack_new(numbers[i], indexes, n);
		if (!new)
			return (0);
		if (!*a)
			*a = new;
		else
		{
			last = (*a)->prev;
			new->next = *a;
			new->prev = last;
			last->next = new;
			(*a)->prev = new;
		}
		i++;
	}
	return (1);
}

static int	create_stack(t_stack **a, char **args, int n)
{
	int	*numbers;
	int	*indexes;
	int	success;

	numbers = numbers_array(args, n);
	indexes = indexes_array(numbers, n);
	success = 1;
	if (!numbers || !indexes || check_duplicates(indexes, n)
		|| !fill_stack(a, numbers, indexes, n))
		success = 0;
	free(numbers);
	free(indexes);
	return (success);
}

int	init_stack(t_stack **a, char **args)
{
	int	n;

	n = count_numbers(args);
	if (n > 0)
		if (!create_stack(a, args, n))
			return (0);
	return (n);
}

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
