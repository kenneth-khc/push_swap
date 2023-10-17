/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:47:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/14 03:45:42 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}

/**
 * Using the list of integers stored in the array,
 * convert each element back to a string and
 * compare it with the original string
 * If they do not match, a non integer was entered, therefore error
*/

void	validate_integers(int *list_of_integers, char **argv)
{
	char	*reconverted;

	if (*argv == NULL || **argv == '\0')
		error();
	while (*argv)
	{
		reconverted = ft_itoa(*list_of_integers++);
		if (ft_strncmp(reconverted, *argv, ft_strlen(reconverted) + 1) != 0)
			error();
		free(reconverted);
		argv++;
	}
}
