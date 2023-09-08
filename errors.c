/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:47:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/08 22:59:30 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}

void	check_integers(int *list_of_integers, char **argv)
{
	char	*reconverted;

	reconverted = NULL;
	while (*argv)
	{
		// is_integer(*list_of_integers++, *argv++);
		reconverted = ft_itoa(*list_of_integers++);
		printf("RECONVERTED: %s\n", reconverted);
		printf("ORIG: %s\n", *argv);
		if (ft_strncmp(reconverted, *argv, ft_strlen(*argv)) != 0)
			error();
		free(reconverted);
		argv++;
	}
}

// void	is_integer(int integer, char *arg)
// {
// 	char	*reconverted;

// 	reconverted = ft_itoa(integer);
// 	if (ft_strncmp(reconverted, arg, ft_strlen(arg)) != 0)
// 		error();
// 	free(reconverted);
// 	return ;
// }