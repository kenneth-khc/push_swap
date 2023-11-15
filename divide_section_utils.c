/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_section_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:35:01 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/08 14:35:12 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_while_shifting_down(t_stack *a, t_stack *b, int shifted_up)
{
	while (shifted_up--)
	{
		rra(a);
		if (a->top->id > a->top->next->id)
			optimized_swap('A', a, b);
	}
}

