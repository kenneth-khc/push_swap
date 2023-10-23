/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:07:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/20 17:04:35 by kecheong         ###   ########.fr       */
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

int	find_midpoint(t_stack *stack)
{
	int		min;
	int		max;
	int		mid;

	find_min_max(stack, &min, &max);
	mid = min + ((max - min) / 2);
	return (mid);
}

void	find_min_max(t_stack *stack, int *min, int *max)
{
	t_node	*current;

	current = stack->top;
	*min = current->simplified;
	*max = current->simplified;
	while (current)
	{
		if (current->simplified <= *min)
			*min = current->simplified;
		if (current->simplified >= *max)
			*max = current->simplified;
		current = current->next;
	}
}

int	find_mid_in_section(t_stack *stack, int section_len)
{
	int		min;
	int		max;
	int		mid;

	find_section_min_max(stack, section_len, &min, &max);
	mid = min + ((max - min) / 2);
	return (mid);
}

void	find_section_min_max(t_stack *stack, int len, int *min, int *max)
{
	t_node	*current;

	current = stack->top;
	*min = current->simplified;
	*max = current->simplified;
	while (len > 0)
	{
		if (current->simplified <= *min)
			*min = current->simplified;
		if (current->simplified >= *max)
			*max = current->simplified;
		current = current->next;
		len--;
	}
}