/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:10:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:20:25 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_first_section(t_stacks *stacks, int to_push, int mid)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	while (to_push > 0)
	{
		if (a->top->id <= mid)
		{
			pb(a, b);
			to_push--;
		}
		else
			ra(a);
	}
}
