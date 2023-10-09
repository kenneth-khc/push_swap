/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:07:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/09 21:49:20 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Determine the size of the integer array by
 * checking how many arguments there are.
 */

int	number_of_strings(char **strings)
{
	int	i;

	i = 0;
	while (*strings++)
		i++;
	return (i);
}

void	free_and_move_list(t_instruction **node)
{
	free((*node)->instruction);
	*node = (*node)->next;
}

int	find_mid_in_stack(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		max;
	int		mid;

	current = stack->top;
	min = current->simplified;
	max = current->simplified;
	while (current)
	{
		if (current->simplified <= min)
			min = current->simplified;
		if (current->simplified >= max)
			max = current->simplified;
		current = current->next;
	}
	mid = min + ((max - min) / 2);
	return (mid);
}

int	find_mid_in_section(t_stack *stack, int section_len)
{
	t_node	*current;
	int		min;
	int		max;
	int		mid;

	current = stack->top;
	min = current->simplified;
	max = current->simplified;
	while (section_len > 0)
	{
		if (current->simplified <= min)
			min = current->simplified;
		if (current->simplified >= max)
			max = current->simplified;
		current = current->next;
		section_len--;
	}
	mid = min + ((max - min) / 2);
	return (mid);
}
