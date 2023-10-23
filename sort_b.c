/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:50:23 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/23 21:20:03 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stack *stack_a, t_stack *stack_b, t_section_list *sections)
{
	int			midpoint_b;
	int			num_elements_to_push;
	t_section	*current_section;

	current_section = sections->tail;
	/// check base case
	if (stack_len(stack_b) <= 3)
	{
		reverse_sort_three_elements(stack_a, stack_b);
		return ;
	}
	// Finish sorting sections
	if (current_section == NULL)
		return ;
	if (current_section->len <= 3)
	{
		sort_current_section(stack_a, stack_b, current_section);
		// sort_section(stack_a, stack_b, current_section->len);
		// delete_section(sections);
		update_section_list(sections);
		sort_b(stack_a, stack_b, sections);
	}
	else if (1 == 1)
	{
		divide_section(stack_a, stack_b, sections);
		sort_b(stack_a, stack_b, sections);
	}
	else if (1 == 2)
	{
		midpoint_b = find_mid_in_section(stack_b, current_section->len);
		num_elements_to_push = find_number_to_push_b(midpoint_b, stack_b, current_section->len);
		current_section->len -= num_elements_to_push;
		add_section(num_elements_to_push, sections, 'B');

		push_to_a(num_elements_to_push, midpoint_b, stack_a, stack_b);
		fix_a(stack_a, stack_b, sections);
		// delete_section(list);
		sort_b(stack_a, stack_b, sections);
	}
}

void	update_section_list(t_section_list *sections)
{
	t_section	*last_section;
	t_section	*second_last;

	last_section = sections->tail;
	if (!last_section->prev)
	{
		free(sections->tail);
		sections->tail = NULL;
		return ;
	}
	// if (!sections || !section->tail)
	// 	return ;
	second_last = last_section->prev;
	free(last_section);
	sections->tail = second_last;
	if (second_last)
		second_last->next = NULL;
	else
		sections->head = NULL;
}

void	sort_current_section(t_stack *stack_a, t_stack *stack_b, t_section *section)
{
	if (section->in == 'B')
	{
		sort_section(stack_a, stack_b, section->len);
		printf("yea");
	}
		// sort section in b
	else if (section->in == 'A') // fix section in A
	{
		if (section->len == 3)
			sort_three_a(stack_a, stack_b);
		else if (section->len == 2)
			sort_two_a(stack_a, stack_b);
	}
}

void	sort_three_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack_a->top;
	second = first->next;
	third = second->next;
	if (third->simplified != third->next->simplified - 1)
	{
		if (second->simplified == third->next->simplified - 1)
		{
			ra(stack_a, stack_b);
			sa(stack_a, stack_b);
			rra(stack_a, stack_b);
		}
		else if (first->simplified == third->next->simplified - 1)
		{
			sa(stack_a, stack_b);
			ra(stack_a, stack_b);
			sa(stack_a, stack_b);
			rra(stack_a, stack_b);
		}
		if (stack_a->top->simplified > stack_a->top->next->simplified)
			sa(stack_a, stack_b);
	}
	else if (first->simplified > second->simplified)
		sa(stack_a, stack_b);
}

void	sort_two_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	first = stack_a->top;
	second = first->next;
	if (first->simplified > second->simplified)
		sa(stack_a, stack_b);
}

void	sort_section(t_stack *stack_a, t_stack *stack_b, int section_len)
{
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
}

int	find_number_to_push_b(int mid, t_stack *stack, int section_len)
{
	int		to_push;
	t_node	*current;
	int		i;
// here
	i = 0;
	to_push = 0;
	current = stack->top;
	while (section_len > 0)
	{
		if (current->simplified > mid)
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
		if (current->simplified > mid)
			return (true);
		current = current->next;
	}
	return (false);
}
