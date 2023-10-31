/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:10:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 23:19:02 by kecheong         ###   ########.fr       */
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
