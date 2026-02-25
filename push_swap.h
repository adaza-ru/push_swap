/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:30:29 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/02/25 00:40:53 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

/*
typedef enum e_state
{
	START,
	PARSING,
	LOADING,
	SORT_SMALL,
	SORT_FIVE,
	SORT_BIG,
	DONE,
	ERROR
}	t_state;
*/
int check_argv_error(char **argv);

#endif