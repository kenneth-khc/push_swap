/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:47:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/11 22:05:37 by kecheong         ###   ########.fr       */
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
	size_t	arg_len;

	if (*argv == NULL || **argv == '\0')
		error();
	// printf("THIS: %s\n", *argv);
	while (*argv)
	{
		reconverted = ft_itoa(*list_of_integers++);
		arg_len = ft_strlen(reconverted);
		// printf("RECONVERTED: %s\n", reconverted);
		// printf("ORIG: %s\n", *argv);
		// printf("ARG_LEN: %zu\n", arg_len);
		if (ft_strncmp(reconverted, *argv, arg_len + 1) != 0)
			error();
		// if (ft_strnstr(reconverted, *argv, arg_len) == NULL)
			// error();
		free(reconverted);
		argv++;
	}
}
