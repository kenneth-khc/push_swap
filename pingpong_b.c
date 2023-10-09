/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpong_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:50:23 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/09 21:23:44 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stack *stack_a, t_stack *stack_b, t_section_list *sections)
{
	int			midpoint_b;
	int			num_elements_to_push;
	t_section	*current_section;

	current_section = sections->tail;

	if (stack_len(stack_b) <= 3)
	{
		reverse_sort_three_elements(stack_a, stack_b);
		return ;
	}
	if (current_section == NULL)
		return ;
	if (current_section->len <= 3)
	{
		sort_section(stack_a, stack_b, current_section->len);
		delete_section(sections);
		sort_b(stack_a, stack_b, sections);
	}
	else
	{
		midpoint_b = find_mid_in_section(stack_b, current_section->len);
		num_elements_to_push = find_number_to_push_b(midpoint_b, stack_b, current_section->len);
		current_section->len -= num_elements_to_push;
		add_section(num_elements_to_push, sections);

		push_to_a(num_elements_to_push, midpoint_b, stack_a, stack_b);
		fix_a(stack_a, stack_b, sections);
		// delete_section(list);
		sort_b(stack_a, stack_b, sections);
	}
}

void	sort_section(t_stack *stack_a, t_stack *stack_b, int section_len)
{
	// t_node	*first;
	// t_node	*second;
	// t_node	*third;

	if (section_len == 1)
	{
		pa(stack_a, stack_b);
		return ;
	}
	if (section_len == 2)
	{
		if (stack_b->top->simplified == stack_a->top->simplified - 1)
		{
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			sb(stack_a, stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		return ;
	}
	if (section_len == 3)
	{
		while (section_len--)
		{
			if (stack_b->top->simplified == stack_a->top->simplified - 1)
				pa(stack_a, stack_b);
			else if (stack_b->top->next->simplified == stack_a->top->simplified - 1)
			{
				sb(stack_a, stack_b);
				pa(stack_a, stack_b);
			}
			else
			{
				rb(stack_a, stack_b);
				sb(stack_a, stack_b);
				pa(stack_a, stack_b);
				rrb(stack_a, stack_b);
			}
		}
	}
	// first = stack_b->top;
	// second = first->next;
	// third = second->next;
}

int	find_number_to_push_b(int mid, t_stack *stack, int section_len)
{
	int		to_push;
	t_node	*current;
	int		i;

	i = 0;
	to_push = 0;
	current = stack->top;
	while (section_len > 0)
	{
		if (current->simplified >= mid)
			to_push++;
		current = current->next;
		section_len--;
	}
	// while (i < section_len)
	// {
	// 	if (current->simplified >= mid)
	// 		to_push++;
	// 	current = current->next;
	// 	i++;
	// }
	return (to_push);
}

bool	elements_left_to_push(int mid, t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->simplified >= mid)
			return (true);
		current = current->next;
	}
	return (false);
}
