/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:40:15 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/21 13:56:25 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_first_half(
t_sections *sections, t_stack *a, t_stack *b, int *first_mid)
{
	int			to_push;
	t_section	*unsorted_a;
	t_section	*first_half;

	unsorted_a = sections->head;
	*first_mid = find_section_midpoint(a, unsorted_a->len);
	to_push = count_nums_to_push(a, *first_mid);
	add_unsorted_section('B', to_push, sections);
	first_half = unsorted_a->next;
	if (unsorted_a->len - first_half->len <= 5)
	{
		push_first_section(a, b, first_half->len, *first_mid);
		unsorted_a->len -= first_half->len;
	}
}

int	find_mid_ignoring_first(t_stack *a, int first_mid)
{
	int		min;
	int		max;
	int		mid;
	t_node	*temp;
	t_node	*current;

	current = a->top;
	temp = current;
	while (temp->id <= first_mid)
		temp = temp->next;
	min = temp->id;
	max = temp->id;
	while (current)
	{
		if (current->id > first_mid && current->id <= min)
			min = current->id;
		if (current->id > first_mid && current->id >= max)
			max = current->id;
		current = current->next;
	}
	mid = min + ((max - min) / 2);
	return (mid);
}

bool	top_is_first_section(t_stack *a, int first_mid)
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

void	slot_to_first_section(t_stack *a, t_stack *b, int first_mid, int mid, int *pushed)
{
	pb(a, b);
	*pushed += 1;
	if (a->top->id > b->top->id && a->top->id <= first_mid)
	{
		slot_to_first_section(a, b, first_mid, mid, pushed);
	}
	if (b->top && b->top->next && not_only_first_section(b, first_mid))
	{
		if (a->top->id > b->top->id && a->top->id <= first_mid)
			slot_to_first_section(a, b, first_mid, mid, pushed);
		if (a->top->id > mid)
			rr(a, b);
		else
			rb(b);
	}
}

bool	has_remaining(t_stack *a, int first_mid)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->id <= first_mid)
			return (true);
		current = current->next;
	}
	return (false);
}

void	clear_remaining(t_stack *a, t_stack *b,
t_sections *sections, int first_midpoint)
{
	t_node	*current;
	int		remaining;
	int		pushed;

	remaining = 0;
	current = a->top;
	while (current)
	{
		if (current->id <= first_midpoint)
			remaining++;
		current = current->next;
	}
	pushed = remaining;
	while (remaining > 0)
	{
		if (a->top->id <= first_midpoint)
		{
			pb(a, b);
			remaining--;
			// if (a->top->id < last_node_id(a))
				// rr(a, b);
			// else
				rb(b);
		}
		else
			ra(a);
	}
	sections->head->len -= pushed;
}

int	last_node_id(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current->next)
		current = current->next;
	return (current->id);
}