/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:10:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/16 18:41:22 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list_of_sections(t_section_list *list)
{
	list->head = NULL;
	list->tail = NULL;
}

void	add_section(int to_sort, t_section_list *list)
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
}

void	delete_section(t_section_list *list)
{
	t_section	*second_last;

	if (!list || !list->tail)
		return ;
	second_last = list->tail->prev;
	free(list->tail);
	list->tail = second_last;
	if (second_last)
		second_last->next = NULL;
	else
		list->head = NULL;

}
