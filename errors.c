/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:47:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/07 23:06:19 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}

void	check_list_for_errors(int *list_of_integers, char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		is_integer(list_of_integers[i], argv[i]);
		i++;
	}
}

void	is_integer(int integer, char *arg)
{
	char	*reconverted;

	reconverted = ft_itoa(integer);
	printf("RECONVERTED: %s\n", reconverted);
	printf("ORIG: %s\n", arg);
	if (ft_strncmp(reconverted, arg, ft_strlen(arg)) != 0)
		error();
	return ;
}