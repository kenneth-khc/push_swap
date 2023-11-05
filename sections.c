/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:10:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/05 23:35:54 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * After pushing a group of numbers to the opposite stack, add a new section
 * with the len member tracking how many elements are in that section.
 * The stack the section belongs to is also tracked.
*/
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
 * Removes the last section after sorting it.
 */
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

/**
 * After repeatedly dividing a section in A and it is sorted, remove it 
 * from the list without affecting the other sections that are after it.
 */
void	remove_current_section_a(t_section *current)
{
	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
}
