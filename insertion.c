/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:40:07 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/29 17:21:15 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion(t_stack *a, t_stack *b)
{
	int		min;
	t_node	*current;
	char	direction;
	int		len;
	int		flag;

	current = a->top;
	flag = 0;
	while (1)
	{
		if (flag == 0)
		{
			min = find_min(a);
			len = stack_len(a);
			direction = find_target(a, min);
			flag = 1;
		}
		if (len <= 5)
		{
			if (elements_are_ascending(a))
				return ;
			if (len == 5)
				sort_five(a, b);
			else if (len == 4)
				sort_four(a, b);
			else if (len == 3)
				sort_three(a, b);
			else if (len == 2)
				if (a->top->simplified > a->top->next->simplified)
					sa(a, b);
			break ;
		}
		if (a->top->simplified == min)
		{
			pb(a, b);
			flag = 0;
		}
		else
		{
			if (direction == UP)
				ra(a, b);
			else if (direction == DOWN)
				rra(a,b);
		}
	}

	while (b->top)
	{
		pa(a,b);
	}
}

char	find_target(t_stack *stack, int target)
{
	int	total_len;
	int	steps_to_target;
	t_node	*current;
	int	midpoint;

	total_len = stack_len(stack);
	steps_to_target = 0;
	current = stack->top;
	midpoint = total_len / 2;

	while (current->simplified != target)
	{
		current = current->next;
		steps_to_target++;
		if (steps_to_target > midpoint)
		{
			return (DOWN);
		}
	}
	return (UP);
}

bool	hundred_elements_left(t_section_list *sections)
{
	t_section	*current;
	int			left;

	current = sections->tail;
	if (current->in == 'A')
		return (false);
	left = 0;
	if (current->in == 'B')
	{
		while (current)
		{
			if (current->in == 'A')
				return (false);
			left += current->len;
			current = current->prev;
		}
		if (left <= 100)
			return (true);
	}
	return (false);
}

void	insert(t_stack *a, t_stack *b)
{
	char	direction;
	bool	checked;

	checked = false;
	while (b->top)
	{
		if (!checked)
		{
			direction = find_target(b, a->top->simplified - 1);
			checked = true;
		}
		if (b->top->simplified == a->top->simplified - 1)
		{
			pa(a, b);
			checked = false;
		}
		else
		{
			if (direction == UP)
				rb(a, b);
			else if (direction == DOWN)
				rrb(a, b);
		}
	}
}
