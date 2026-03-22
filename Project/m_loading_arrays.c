/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_loading_arrays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:37:06 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 14:28:54 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_push_swap.h"

static void	merge(int *arr, int *aux, int start, int end)
{
	int	mid;
	int	i;
	int	j;
	int	k;

	mid = start + (end - start) / 2;
	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
			aux[k++] = arr[i++];
		else
			aux[k++] = arr[j++];
	}
	while (i <= mid)
		aux[k++] = arr[i++];
	while (j <= end)
		aux[k++] = arr[j++];
	while (start <= end)
	{
		arr[start] = aux[start];
		start++;
	}
}

static void	perform_merge_sort(int *arr, int *aux, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = start + (end - start) / 2;
		perform_merge_sort(arr, aux, start, mid);
		perform_merge_sort(arr, aux, mid + 1, end);
		merge(arr, aux, start, end);
	}
}

int	*indexes_array(int *nums, int n)
{
	int	*indexes;
	int	*aux;
	int	i;

	indexes = malloc(sizeof(int) * n);
	aux = malloc(sizeof(int) * n);
	if (!indexes || !aux)
	{
		free(indexes);
		free(aux);
		return (NULL);
	}
	i = -1;
	while (++i < n)
		indexes[i] = nums[i];
	perform_merge_sort(indexes, aux, 0, n - 1);
	free(aux);
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
