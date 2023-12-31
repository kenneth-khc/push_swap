/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:10:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:11:14 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * After pushing a group of numbers to the opposite stack, add a new section
 * with the len member tracking how many elements are in that section.
 * The stack the section belongs to is also tracked.
*/
void	add_unsorted_section(char location, int len, t_sections *sections)
{
	t_section	*new_section;

	new_section = malloc(sizeof(*new_section));
	if (NULL == new_section)
		error();
	new_section->in = location;
	new_section->len = len;
	new_section->prev = sections->tail;
	new_section->next = NULL;
	if (NULL == sections->head)
		sections->head = new_section;
	else
		sections->tail->next = new_section;
	sections->tail = new_section;
}

void	remove_sorted_a(t_sections *sections)
{
	t_section	*sorted;
	t_section	*unsorted;

	sorted = sections->head;
	unsorted = sorted->next;
	if (unsorted)
	{
		sections->head = unsorted;
		sections->head->prev = NULL;
	}
	else
	{
		sections->head = NULL;
		sections->tail = NULL;
	}
	free(sorted);
}

/**
 * Removes the last section after sorting it and updates the section list.
 */
void	remove_last_section(t_sections *sections)
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

void	clear_sorted_sections(t_sections *sections, t_stacks *stacks)
{
	t_stack		*a;
	t_stack		*b;
	t_section	*last;

	a = stacks->a;
	b = stacks->b;
	last = sections->tail;
	while (last)
	{
		if (last->in == 'A' && section_is_ascending(a, last->len))
			remove_last_section(sections);
		else if (last->in == 'B' && section_is_descending(b, last->len))
		{
			push_sorted_section(a, b, last->len);
			remove_last_section(sections);
		}
		else
			break ;
		last = last->prev;
	}
}
