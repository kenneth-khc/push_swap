/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:40:15 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/15 18:31:15 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    stage_one(t_stack *a, t_stack *b, int *size, t_section_list *sections)
// {
//     int first_midpoint;
//     int to_push;
// }

int    find_mid_ignoring_first(t_stack *a, int first_mid)
{
    int		min;
	int		max;
	int		mid;

    t_node	*current;
	t_node	*temp;
	current = a->top;
	temp = current;
	while (temp->id <= first_mid)
		temp = temp->next;
	min = temp->id;
	max = temp->id;
	while (current)
	{
		if (current->id <= min && current->id > first_mid)
			min = current->id;
		if (current->id >= max && current->id > first_mid)
			max = current->id;
		current = current->next;
	}
	if (min == -1)
		min = first_mid + 1;
	mid = min + ((max - min) / 2);
	return (mid);
}

bool    top_is_first_section(t_stack *a, int first_mid)
{
    if (a->top->id <= first_mid)
        return (true);
    else
        return (false);
}

int	count_nums_to_push_ignore_first(int mid, int first_mid, t_stack *a)
{
	int		to_push;
	t_node	*current;

	to_push = 0;
	current = a->top;
	while (current)
	{
		if (current->id <= mid && current->id > first_mid)
			to_push++;
		current = current->next;
	}
	return (to_push);
}

void	slot_to_first_section(t_stack *a, t_stack *b, int first_mid, int mid)
{
	static int	pushed = 0;

	pb(a, b);
	pushed++;
	if (pushed == 0)
		return ;
	if (a->top->id < b->top->id)
	{
		slot_to_first_section(a, b, first_mid, mid);
	}
	if (b->top && b->top->next && not_only_first_section(b, first_mid))
	{
		if (a->top->id > mid)
			rr(a, b);
		else
			rb(b);
		pushed--;
	}
}

