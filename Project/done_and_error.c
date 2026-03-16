/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 01:18:53 by adaza-ru          #+#    #+#             */
/*   Updated: 2026/03/01 01:42:22 by adaza-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	last = (*stack)->prev;
	last->next = NULL;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	terminate_program(t_state state, t_stack *a)
{
	free_stack(&a);
	if (state == ERROR)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
		return (1);
}
