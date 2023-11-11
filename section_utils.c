/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:40:39 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/11 22:34:49 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_section_midpoint(t_int_array *section)
{
	int	i;
	int	min;
	int	max;
	int	mid;

	i = 0;
	min = section->contents[i];
	max = section->contents[i];
	while (i < section->size)
	{
		if (section->contents[i] <= min)
			min = section->contents[i];
		if (section->contents[i] >= max)
			max = section->contents[i];
		i++;
	}
	mid = min + ((max - min) / 2);
	return (mid);
}

t_int_array	*init_updated_unsorted_array(t_stack *stack, int len, int first_mid)
{
	t_int_array	*array;
	t_node		*current;
	int			i;

	array = malloc(sizeof(t_int_array));
	if (array == NULL)
		error();
	array->contents = malloc(sizeof(int) * len);
	if (array->contents == NULL)
		error();
	array->size = len;
	current = stack->top;
	i = 0;
	while (i < len)
	{
		if (current->id <= first_mid)
		{
			current = current->next;
			continue ;
		}
		array->contents[i] = current->id;
		current = current->next;
		i++;
	}
	return (array);
}
