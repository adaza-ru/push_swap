/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_start_argv_errors_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:25:05 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/22 18:03:10 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

static int	check_valid_number(char *str)
{
	long long	n;
	int			sign;
	int			digits;

	n = 0;
	sign = 1;
	digits = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
		if (++digits > 11)
			return (0);
	}
	if (digits == 0 || (*str && *str != ' '))
		return (0);
	n *= sign;
	return (n >= -2147483648 && n <= 2147483647);
}

static int	check_valid_format(char **argv)
{
	int		num;
	char	*ptr;

	if (!*argv)
		return (0);
	num = 0;
	while (*argv)
	{
		ptr = *argv;
		while (*ptr)
		{
			while (*ptr == ' ')
				ptr++;
			if (*ptr)
			{
				num = check_valid_number(ptr);
				if (num == 0)
					return (0);
			}
			while (*ptr && *ptr != ' ')
				ptr++;
		}
		argv++;
	}
	return (num);
}

static int	check_valid_chars(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && argv[i][j] != '-'
			&& argv[i][j] != '+' && argv[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_argv_error(char **argv)
{
	if (!check_valid_chars(argv) || !check_valid_format(argv))
	{
		return (1);
	}
	return (0);
}
