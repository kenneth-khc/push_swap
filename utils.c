/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:07:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/13 02:12:56 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Determine the size of the integer array by
 * checking how many arguments there are.
 */

int	number_of_strings(char **strings)
{
	int	i;

	i = 0;
	while (*strings++)
		i++;
	return (i);
}

void	free_and_move_list(t_instruction **node)
{
	free((*node)->instruction);
	*node = (*node)->next;
}