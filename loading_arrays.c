/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:37:06 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/02 00:30:11 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_sort(int *arr, int left, int right)
{
	
}

int	*indexes_array(int *nums, int n)
{
	int	*indexes;
	int	i;

	indexes = malloc(sizeof(int) * n);
	if (!indexes)
		return (NULL);
	i = 0;
	while (i < n)
	{
		indexes[i] = nums[i];
		i++;
	}
	merge_sort(indexes, 0, n - 1);
	return (indexes);
}

static void	process_string(int *numbers, char *str, int *idx)
{
	int	j;

	j = 0;
	while (str[j])
	{
		while (str[j] && str[j] == ' ')
			j++;
		if (str[j])
		{
			numbers[(*idx)++] = ft_atoi(str + j);
			while (str[j] && str[j] != ' ')
				j++;
		}
	}
}

int	*numbers_array(char **args, int n)
{
	int	*numbers;
	int	i;
	int	idx;

	numbers = malloc(sizeof(int) * n);
	if (!numbers)
		return (NULL);
	i = 0;
	idx = 0;
	while (args[i])
	{
		process_string(numbers, args[i], &idx);
		i++;
	}
	return (numbers);
}
