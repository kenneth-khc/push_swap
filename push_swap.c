/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/09 10:38:57 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*list_of_integers;
	int		size;
	t_stack	a;
	t_stack	b;

	list_of_integers = NULL;
	size = 0;
	list_of_integers = parse_arguments(argc, ++argv, &size);
	init_stacks(&a, &b, list_of_integers, size);
	// printf("Hello,kenneth!!! ;)🐨🐨");

// testing
	// fill_stack_b_for_test(&b);
	// peek_entire_stack(a, b);
	// execute_instructions_for_test(&a, &b);
	// peek_entire_stack(a, b);
// end test
	// sorting(&a, &b, size);

	pingpong(&a, &b ,size);
}
