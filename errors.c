/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:47:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/21 12:24:50 by kecheong         ###   ########.fr       */
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
 * compare it with the original string.
 * If they do not match, a non integer was entered, therefore error.
 * + signs are trimmed.
*/
void	validate_integers(int *integers, char **strings)
{
	int		i;
	int		len;
	char	*trimmed_arg;
	char	*reconverted;

	i = 0;
	while (strings[i])
	{
		trimmed_arg = ft_strtrim(strings[i], "+");
		reconverted = ft_itoa(integers[i]);
		len = ft_strlen(reconverted) + 1;
		if (ft_strncmp(reconverted, trimmed_arg, len))
			error();
		free(reconverted);
		free(trimmed_arg);
		free(strings[i]);
		i++;
	}
	free(strings);
}
