/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:10:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 12:27:18 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_section(int to_sort, t_section_list *list, char stack)
{
	t_section	*new_section;

	new_section = malloc(sizeof(t_section));
	new_section->len = to_sort;
	new_section->next = NULL;
	new_section->prev = list->tail;
	if (!list->head)
		list->head = new_section;
	else
		list->tail->next = new_section;
	list->tail = new_section;
	new_section->in = stack;
}

/**
 * Check to see if a group of elements are sorted.
 */

bool	section_is_sorted(t_node *begin_node, int size)
{
	t_node	*current;
	int		prev;

	if (begin_node)
	{
		current = begin_node;
		prev = current->data;
		while (--size)
		{
			current = current->next;
			if (prev > current->data)
				return (false);
			prev = current->data;
		}
	}
	return (true);
}

void	remove_section(t_section_list *sections)
{
	t_section	*last;
	t_section	*second_last;

	last = sections->tail;
	second_last = last->prev;
	free(last);
	sections->tail = second_last;
	if (second_last)
		second_last->next = NULL;
	else
		sections->head = NULL;
}
