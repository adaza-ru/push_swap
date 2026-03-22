/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_loading_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:03:16 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 18:02:31 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

int	is_sorted(t_stack *a)
{
	t_stack	*temp;

	if (!a)
		return (1);
	temp = a;
	while (temp->next != a)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	value;

	sign = 1;
	i = 0;
	value = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	return (sign * value);
}

int	binary_search_index(int *sorted_arr, int n, int value)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (sorted_arr[mid] == value)
			return (mid);
		if (sorted_arr[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

int	check_duplicates(int *sorted_nums, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (sorted_nums[i] == sorted_nums[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	count_numbers(char **args)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (args[i])
	{
		while (args[i][j])
		{
			while (args[i][j] && args[i][j] == ' ')
				j++;
			if (args[i][j] && args[i][j] != ' ')
				count++;
			while (args[i][j] && args[i][j] != ' ')
				j++;
		}
		j = 0;
		i++;
	}
	return (count);
}
