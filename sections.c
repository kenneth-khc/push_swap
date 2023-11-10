/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:10:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/10 14:16:50 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_section(t_stack *stack, char in_stack, int len,
t_section_list *sections)
{
	t_section	*new_section;

	if (len == 0)
		return ;
	new_section = malloc(sizeof(t_section));
	new_section->in = in_stack;
	new_section->len = len;
	new_section->top = stack->top;
	new_section->arr = init_section_array(stack, len);
	new_section->prev = sections->tail;
	new_section->next = NULL;
	if (!sections->head)
		sections->head = new_section;
	else
		sections->tail->next = new_section;
	sections->tail = new_section;
}

t_int_array	*init_section_array(t_stack *stack, int len)
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
		array->contents[i] = current->id;
		current = current->next;
		i++;
	}
	return (array);
}

/**
 * After pushing a group of numbers to the opposite stack, add a new section
 * with the len member tracking how many elements are in that section.
 * The stack the section belongs to is also tracked.
*/
void	add_section(int to_sort, t_section_list *list, char stack)
{
	t_section	*new_section;

	if (to_sort == 0)
		return ;
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
void	remove_current_section_a1(t_section *current)
{
	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
}

void	remove_current_section_a(t_section_list *sections, t_section *current)
{
	if (sections->tail == current)
		sections->tail = current->prev;
	current->next->prev = current->prev;
	current->prev->next = current->next;
	free(current);
}
